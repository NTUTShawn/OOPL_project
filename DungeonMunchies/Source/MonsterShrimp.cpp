#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <cmath>
#include <ctgmath>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "Character.h"
#include "BloodBar.h"
#include "Monster.h"
#include "MonsterShrimp.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//這個class是怪物Shrimp的物件											   //
	/////////////////////////////////////////////////////////////////////////////
	MonsterShrimp::MonsterShrimp()
	{
		_x = 400;
		_y = 400;
		hp = 10;
		attackDamage = 5;
		facingLR = 0;
		action = walk_a;
		STEP_SIZE = 1;
		attackCD = false;
	}

	MonsterShrimp::MonsterShrimp(int x, int y, Character* c) : Monster(x, y, 12, 50, c)
	{
		hp = 50;
		attackDamage = 5;
		facingLR = 0;
		action = walk_a;
		STEP_SIZE = 1;
		attackCD = false;
	}

	MonsterShrimp::~MonsterShrimp()
	{
	}

	void MonsterShrimp::LoadBitmap()
	{
		bloodBar.LoadBitmap();

		walkLeft.AddBitmap(IDB_MONSTERSHRIMPWALKL01, RGB(0, 0, 0));
		walkLeft.AddBitmap(IDB_MONSTERSHRIMPWALKL02, RGB(0, 0, 0));
		walkRight.AddBitmap(IDB_MONSTERSHRIMPWALKR01, RGB(0, 0, 0));
		walkRight.AddBitmap(IDB_MONSTERSHRIMPWALKR02, RGB(0, 0, 0));

		attackLeft.AddBitmap(IDB_MONSTERSHRIMPATTACKL01, RGB(0, 0, 0));
		attackLeft.AddBitmap(IDB_MONSTERSHRIMPATTACKL02, RGB(0, 0, 0));
		attackLeft.AddBitmap(IDB_MONSTERSHRIMPATTACKL03, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERSHRIMPATTACKR01, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERSHRIMPATTACKR02, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERSHRIMPATTACKR03, RGB(0, 0, 0));

		deadLeft.LoadBitmap(IDB_MONSTERSHRIMPDEADL, RGB(0, 0, 0));
		deadRight.LoadBitmap(IDB_MONSTERSHRIMPDEADR, RGB(0, 0, 0));
		sourceShrimpAttack.LoadBitmap(IDB_SOURCESHRIMPATTACK, RGB(0, 0, 0));
		sourceShrimpBlood.LoadBitmap(IDB_SOURCESHRIMPBLOOD, RGB(0, 0, 0));
		black.LoadBitmap(IDB_BLACK, RGB(0, 0, 0));
	}

	void MonsterShrimp::Initialize()
	{
		_x = init_x;
		_y = init_y;
		currentFloor = 0;
		BORDER = 5;
		hp = 150;
		bloodBar.setFullHP(hp);
		attackDamage = 10;
		attackDelayCount = 4;
		facingLR = 0;
		action = walk_a;
		STEP_SIZE = 2;
		walkLength = 2;
		velocity = 0;
		hasGottenSource = false;
		lightBulbInside = 15;
		hasGottenLightBulb = false;
		srand((unsigned int)time(NULL));
		canStandOn = true;
		isViolent = false;
		haveSetViolent = false;
	}

	void MonsterShrimp::OnShow(Map* m)
	{
		if (isAlive())
		{
			if (isAttacked && isSparkleEffectShow)
			{
				isAttackedEffectOnShow(m);
			}
			else
			{
				if (facingLR == 0)
				{
					if (action == walk_a)
					{
						walkLeft.SetTopLeft(_x - 140 + m->getXMovement(), _y + m->getYMovement()); //讓圖片中怪物顯示靠向左
						//walkLeft.SetDelayCount(3);
						walkLeft.OnShow();
					}
					else
					{
						attackLeft.SetTopLeft(_x + m->getXMovement() - 110, _y + m->getYMovement());
						attackLeft.SetDelayCount(attackDelayCount);
						attackLeft.OnShow();
						if (attackLeft.GetCurrentBitmapNumber() == 2)
						{
							attackJudge(100);
						}
						if (attackLeft.IsFinalBitmap())
						{
							action = walk_a;
							attackLeft.Reset();
						}
					}
				}
				else
				{
					if (action == walk_a)
					{
						walkRight.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
						walkRight.OnShow();
					}
					else
					{
						attackRight.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
						attackRight.SetDelayCount(attackDelayCount);
						attackRight.OnShow();
						if (attackRight.GetCurrentBitmapNumber() == 2)
						{
							attackJudge(100);
						}
						if (attackRight.IsFinalBitmap())
						{
							action = walk_a;
							attackRight.Reset();
						}
					}
				}
			}
			bloodBar.setXY(GetLeftX() + m->getXMovement(), GetTopY() + m->getYMovement() - 16);
			bloodBar.showBloodBar(m, hp);
			if (lossHpShowFlag)
			{
				lossHpShow(m);
			}
			lossHpTimer.CaculateTimeForFalse(&lossHpShowFlag, 0.5);
		}
		else
		{
			if (facingLR == 0)
			{
				deadLeft.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
				deadLeft.ShowBitmap();
			}
			else
			{
				deadRight.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
				deadRight.ShowBitmap();
			}
			if (!hasGottenSource)
			{
				if (randN == 0)
				{
					sourceShrimpAttack.SetTopLeft((GetLeftX() + GetRightX()) / 2 + m->getXMovement(), GetBottomY() - 64 + m->getYMovement());
					sourceShrimpAttack.ShowBitmap();
				}
				else
				{
					sourceShrimpBlood.SetTopLeft((GetLeftX() + GetRightX()) / 2 + m->getXMovement(), GetBottomY() - 64 + m->getYMovement());
					sourceShrimpBlood.ShowBitmap();
				}
			}
		}
	}

	void MonsterShrimp::OnMove(Map* m)
	{
		if (isViolent && !haveSetViolent)
		{
			hp = 350;
			attackDamage = 15;
			attackDelayCount = 3;
			walkLength = 4;
			haveSetViolent = true;
		}
		if (!m == NULL)
		{
			m->monsterFloorChanging(GetLeftX());
			if (m->getMonsterFloor() > currentFloor)
			{
				if (_y < m->getMonsterFloor() - 178)
				{
					_y += velocity * 2;
					if (velocity < 6)
						velocity++;
				}
				else
				{
					currentFloor = m->getMonsterFloor();
					_y = currentFloor - 178;			// 當y座標低於地板，更正為地板上
					velocity = 0;
				}
			}
		}

		if (isAlive())
		{
			SetCharacterDirection();
			if (action == walk_a)
			{
				facingLR = characterDirectionLR;
			}
			if (distanceToCharacter() < 190 && attackCD == false)
			{
				attackStart();
			}
			else if (distanceToCharacter() < 280 && action == walk_a)
			{
				for (int i = 0; i < walkLength; i++)
				{
					if (characterDirectionLR == 0 && (GetLeftX() - STEP_SIZE + BORDER) >= character->GetRightX() && m->isEmpty(GetLeftX() - STEP_SIZE - BORDER, GetBottomY() - BORDER))
					{
						_x -= STEP_SIZE;
					}
					else if (characterDirectionLR == 1 && (GetRightX() + STEP_SIZE - BORDER) <= character->GetLeftX() && m->isEmpty(GetRightX() + STEP_SIZE + BORDER, GetBottomY() - BORDER))
					{
						_x += STEP_SIZE;
					}
				}
				randN = rand() % 2;
			}
			attackCDTime.CaculateTimeForFalse(&attackCD, 2);
			walkLeft.OnMove();
			walkRight.OnMove();
			if (action == attack_a)
			{
				attackOnMove();
			}
			isAttackedEffectCaculation();
			//intersect();
		}
		else
		{
			if (!hasGottenLightBulb)
			{
				character->AddLightBulb(lightBulbInside);
				hasGottenLightBulb = true;
			}
			if (hasGottenSource == false)
			{

				if (randN == 0)
				{
					touchSource(m, shrimp_attack_p);
				}
				else
				{
					touchSource(m, shrimp_blood_p);
				}
			}
		}
	}

	int MonsterShrimp::GetLeftX() //顯示的圖會往左邊靠(onShow調整的)
	{
		return _x;
	}

	int MonsterShrimp::GetTopY() //需調整以對應顯示的圖(_y + (圖片高度-物體高度))
	{
		if (action == walk_a) //walk
		{
			return _y + 95;
		}
		else// if (actionNum == 1) //attack ?????????????????
		{
			return _y + 75;
		}
	}

	int MonsterShrimp::GetRightX() //加上物體本身的長度
	{
		if (action == walk_a) //walk 
		{
			return _x + 125;
		}
		else // if (actionNum == 1) //attack 
		{
			return _x + 140;
		}
	}

	int MonsterShrimp::GetBottomY()
	{
		return _y + walkLeft.Height();
	}

	void MonsterShrimp::attackOnMove()
	{
		if (facingLR == 0)
		{
			attackLeft.OnMove();
		}
		else if (facingLR == 1)
		{
			attackRight.OnMove();
		}
	}
}
