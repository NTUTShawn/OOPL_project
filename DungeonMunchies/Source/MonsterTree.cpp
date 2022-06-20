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
#include "MonsterTree.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Tree������											   //
	/////////////////////////////////////////////////////////////////////////////
	MonsterTree::MonsterTree()
	{
		_x = 400;
		_y = 400;
		hp = 10;
		attackDamage = 5;
		facingLR = 0;
		action = sleep_a;
		STEP_SIZE = 1;
		attackCD = false;
	}

	MonsterTree::MonsterTree(int x, int y, Character* c) : Monster(x, y, 50, 5, c)
	{
		hp = 50;
		attackDamage = 5;
		facingLR = 0;
		action = sleep_a;
		STEP_SIZE = 1;
		attackCD = false;
	}

	MonsterTree::~MonsterTree()
	{
	}

	void MonsterTree::LoadBitmap()
	{
		bloodBar.LoadBitmap();
		sleepLeft.LoadBitmap(IDB_MONSTERTREESLEEPL, RGB(0, 0, 0));
		sleepRight.LoadBitmap(IDB_MONSTERTREESLEEPR, RGB(0, 0, 0));

		walkLeft.AddBitmap(IDB_MONSTERTREEWALKL01, RGB(0, 0, 0));
		walkLeft.AddBitmap(IDB_MONSTERTREEWALKL02, RGB(0, 0, 0));
		walkLeft.AddBitmap(IDB_MONSTERTREEWALKL03, RGB(0, 0, 0));
		walkLeft.AddBitmap(IDB_MONSTERTREEWALKL04, RGB(0, 0, 0));
		walkRight.AddBitmap(IDB_MONSTERTREEWALKR01, RGB(0, 0, 0));
		walkRight.AddBitmap(IDB_MONSTERTREEWALKR02, RGB(0, 0, 0));
		walkRight.AddBitmap(IDB_MONSTERTREEWALKR03, RGB(0, 0, 0));
		walkRight.AddBitmap(IDB_MONSTERTREEWALKR04, RGB(0, 0, 0));

		attackLeft.AddBitmap(IDB_MONSTERTREEATTACKL01, RGB(0, 0, 0));
		attackLeft.AddBitmap(IDB_MONSTERTREEATTACKL02, RGB(0, 0, 0));
		attackLeft.AddBitmap(IDB_MONSTERTREEATTACKL03, RGB(0, 0, 0));
		attackLeft.AddBitmap(IDB_MONSTERTREEATTACKL04, RGB(0, 0, 0));
		attackLeft.AddBitmap(IDB_MONSTERTREEATTACKL05, RGB(0, 0, 0));
		attackLeft.AddBitmap(IDB_MONSTERTREEATTACKL06, RGB(0, 0, 0));
		attackLeft.AddBitmap(IDB_MONSTERTREEATTACKL07, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERTREEATTACKR01, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERTREEATTACKR02, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERTREEATTACKR03, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERTREEATTACKR04, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERTREEATTACKR05, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERTREEATTACKR06, RGB(0, 0, 0));
		attackRight.AddBitmap(IDB_MONSTERTREEATTACKR07, RGB(0, 0, 0));

		deadLeft.LoadBitmap(IDB_MONSTERTREEDEADL, RGB(0, 0, 0));
		deadRight.LoadBitmap(IDB_MONSTERTREEDEADR, RGB(0, 0, 0));
		sourceGuavaJuiceBlood.LoadBitmap(IDB_SOURCEGUAVAJUICEBLOOD, RGB(0, 0, 0));
		black.LoadBitmap(IDB_BLACK, RGB(0, 0, 0));
	}

	void MonsterTree::Initialize()
	{
		_x = init_x;
		_y = init_y;
		currentFloor = 0;
		BORDER = 5;
		hp = 50;
		attackDamage = 8;
		attackDelayCount = 4;
		facingLR = 0;
		action = sleep_a;
		bloodBar.setFullHP(hp);
		STEP_SIZE = 2;
		walkLength = 2;
		velocity = 0;
		lightBulbInside = 15;
		hasGottenLightBulb = false;
		hasGottenSource = false;
		canStandOn = true;
		isViolent = false;
		haveSetViolent = false;
	}

	void MonsterTree::OnShow(Map* m)
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
					if (action == sleep_a)
					{
						sleepLeft.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
						sleepLeft.ShowBitmap();
					}
					else if (action == walk_a)
					{
						walkLeft.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement()); //���Ϥ����Ǫ���ܾa�V��
						//walkLeft.SetDelayCount(3);
						walkLeft.OnShow();
					}
					else
					{
						attackLeft.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
						attackLeft.SetDelayCount(attackDelayCount);
						attackLeft.OnShow();
						if (attackLeft.GetCurrentBitmapNumber() == 4)
						{
							attackJudge(90);
						}
						if (attackLeft.IsFinalBitmap())
						{
							action = actionController();
							attackLeft.Reset();
						}
					}
				}
				else
				{
					if (action == sleep_a)
					{
						sleepRight.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
						sleepRight.ShowBitmap();
					}
					else if (action == walk_a)
					{
						walkRight.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
						walkRight.OnShow();
					}
					else
					{
						attackRight.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
						attackRight.SetDelayCount(attackDelayCount);
						attackRight.OnShow();
						if (attackRight.GetCurrentBitmapNumber() == 4)
						{
							attackJudge(90);
						}
						if (attackRight.IsFinalBitmap())
						{
							action = actionController();
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
				sourceGuavaJuiceBlood.SetTopLeft((GetLeftX() + GetRightX()) / 2 + m->getXMovement(), GetBottomY() - 64 + m->getYMovement());
				sourceGuavaJuiceBlood.ShowBitmap();
			}
		}
	}

	void MonsterTree::OnMove(Map* m)
	{
		if (isViolent && !haveSetViolent)
		{
			hp = 220;
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
				if (_y < m->getMonsterFloor() - 210)
				{
					_y += velocity * 2;
					if (velocity < 6)
						velocity++;
				}
				else
				{
					currentFloor = m->getMonsterFloor();
					_y = currentFloor - 210;			// ��y�y�ЧC��a�O�A�󥿬��a�O�W
					velocity = 0;
				}
			}
		}
		if (isAlive())
		{
			SetCharacterDirection();
			if (distanceToCharacter() < 280 && action == sleep_a)
			{
				action = walk_a;
			}
			if (distanceToCharacter() >= 280 && action == walk_a)
			{
				action = sleep_a;
			}
			if (action == walk_a)
			{
				facingLR = characterDirectionLR;
			}
			if (distanceToCharacter() < 130 && attackCD == false && action != attack_a)
			{
				attackStart();
			}
			else if (distanceToCharacter() < 280 && action == walk_a)
			{
				for (int i = 0; i < walkLength; i++)
				{
					if (characterDirectionLR == 0 && (GetLeftX() - STEP_SIZE + BORDER) >= character->GetRightX() && m->isEmpty(GetLeftX() - STEP_SIZE - BORDER, GetBottomY()))
					{
						_x -= STEP_SIZE;
					}
					else if (characterDirectionLR == 1 && (GetRightX() + STEP_SIZE - BORDER - 5) <= character->GetLeftX() && m->isEmpty(GetRightX() + STEP_SIZE + BORDER, GetBottomY()))
					{
						_x += STEP_SIZE;
					}
				}
			}
			attackCDTime.CaculateTimeForFalse(&attackCD, 3);

			if (action == walk_a)
			{
				walkOnMove();
			}

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
			if (!hasGottenSource)
			{
				touchSource(m, guava_juice_blood_p);
			}
		}
	}

	int MonsterTree::GetLeftX() //�H�����鬰�D(�����d�򤣭n��b�̭�)
	{
		if (facingLR == 0) //left
		{
			return _x + 87;
		}
		else
		{
			return _x + 60;
		}
	}

	int MonsterTree::GetTopY() //�ݽվ�H������ܪ���(_y + (�Ϥ�����-���鰪��))
	{
		if (action == walk_a) //left
		{
			return _y + 72;
		}
		else
		{
			return _y + 50;
		}
	}

	int MonsterTree::GetRightX() //�[�W���饻��������
	{
		if (facingLR == 0) //left
		{
			return _x + 175;
		}
		else
		{
			return _x + 145;
		}
	}

	int MonsterTree::GetBottomY()
	{
		return _y + walkLeft.Height();
	}

	Action MonsterTree::actionController()
	{
		if (distanceToCharacter() < 280)
		{
			return walk_a;
		}
		else
		{
			return sleep_a;
		}
	}

	void MonsterTree::walkOnMove()
	{
		if (facingLR == 0)
		{
			walkLeft.OnMove();
		}
		else if (facingLR == 1)
		{
			walkRight.OnMove();
		}
	}

	void MonsterTree::attackOnMove()
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
