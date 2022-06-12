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
#include "MonsterMosquito.h"
#include "Util.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Mosquito������											   //
	/////////////////////////////////////////////////////////////////////////////
	MonsterMosquito::MonsterMosquito()
	{
		_x = 400;
		_y = 400;
		hp = 50;
		attackDamage = 5;
		BORDER = 20;
	}

	MonsterMosquito::MonsterMosquito(int x, int y, Character* c) : Monster(x, y, 50, 5, c)
	{
		BORDER = 20;
	}

	MonsterMosquito::~MonsterMosquito()
	{
	}

	void MonsterMosquito::LoadBitmap()
	{
		bloodBar.LoadBitmap();
		faceLeft.AddBitmap(".\\res\\monster_mosquito01_left.bmp", RGB(0, 0, 0));
		faceLeft.AddBitmap(".\\res\\monster_mosquito02_left.bmp", RGB(0, 0, 0));
		faceRight.AddBitmap(".\\res\\monster_mosquito01_right.bmp", RGB(0, 0, 0));
		faceRight.AddBitmap(".\\res\\monster_mosquito02_right.bmp", RGB(0, 0, 0));
		sourceMosquitoJump.LoadBitmap(".\\res\\source_mosquito_jump.bmp", RGB(0, 0, 0));
		black.LoadBitmap(".\\res\\black.bmp", RGB(0, 0, 0));
	}

	void MonsterMosquito::Initialize()
	{
		_x = init_x;
		_y = init_y;
		currentFloor = 0;
		BORDER = 5;
		hp = 20;
		attackDamage = 3;
		facingLR = 0;
		bloodBar.setFullHP(hp);
		STEP_SIZE = 5;
		velocity = 0;
		lightBulbInside = 20;
		hasGottenLightBulb = false;
		hasGottenSource = false;
		flyCase = 2;
		shouldFlyCaseChange = false;
		canStandOn = false;
	}

	void MonsterMosquito::OnMove(Map* m)
	{
		if (!m == NULL)
		{
			m->monsterFloorChanging((GetLeftX() + GetRightX()) / 2);
			currentFloor = m->getMonsterFloor();
		}
		if (isAlive())
		{
			if (shouldFlyCaseChange)
			{
				flyTimer.Start();
				flyCaseChanger();
				shouldFlyCaseChange = false;
			}
			if (flyCase == 1) // ���W
			{
				moveUp(m);
				moveLeft(m);
			}
			else if (flyCase == 2) // ���U
			{
				moveDown(m);
				moveLeft(m);
			}
			else if (flyCase == 3) // �k�U
			{
				moveDown(m);
				moveRight(m);
			}
			else if (flyCase == 4) // �k�W
			{
				moveUp(m);
				moveRight(m);
			}
			flyTimer.CaculateTimeForTrue(&shouldFlyCaseChange, (rand() % 200) / 100);
			intersect();
			isAttackedEffectCaculation();
			faceLeft.OnMove();
			faceRight.OnMove();
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
				touchSource(m, mosquito_jump_p);
			}
		}
	}

	void MonsterMosquito::OnShow(Map* m)
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
					faceLeft.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
					faceLeft.SetDelayCount(1);
					faceLeft.OnShow();
				}
				else
				{
					faceRight.SetTopLeft(_x + m->getXMovement(), _y + m->getYMovement());
					faceRight.SetDelayCount(1);
					faceRight.OnShow();
				}
			}
			bloodBar.setXY(GetLeftX() + m->getXMovement(), GetTopY() + m->getYMovement() - 25);
			bloodBar.showBloodBar(m, hp);
			if (lossHpShowFlag)
			{
				lossHpShow(m);
			}
			lossHpTimer.CaculateTimeForFalse(&lossHpShowFlag, 0.5);
		}
		else
		{
			if (!hasGottenSource)
			{
				sourceMosquitoJump.SetTopLeft((GetLeftX() + GetRightX()) / 2 + m->getXMovement(), currentFloor - 64 + m->getYMovement());
				sourceMosquitoJump.ShowBitmap();
			}
		}
		//showData();
	}

	void MonsterMosquito::showData()
	{
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(120, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(230, 220, 200));
		pDC->SetTextColor(RGB(0, 0, 0));
		char position[600];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(position, "MosquitoLeftX:%d MosquitoRightX:%d MosquitoTopY:%d MosquitoBottomY:%d MosquitoHp: %d flyTimer(%f, %f, %f)"
			, GetLeftX(), GetRightX(), GetTopY(), GetBottomY(), GetCurrentHp(), (double)flyTimer.GetStartTime(), (double)flyTimer.GetFinishTime(), (double)flyTimer.GetTime());
		//sprintf(str, "CharacterLeftX : %d", CharacterLeftX);
		pDC->TextOut(200, 50, position);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

	int MonsterMosquito::GetLeftX()
	{
		return _x + 18;
	}

	int MonsterMosquito::GetTopY()
	{
		return _y + 28;
	}

	int MonsterMosquito::GetRightX()
	{
		return _x + 80;
	}

	int MonsterMosquito::GetBottomY()
	{
		return _y + 68;
	}
	void MonsterMosquito::moveUp(Map* m)
	{
		if (m->isEmpty(GetLeftX(), GetTopY() - STEP_SIZE) && m->isEmpty(GetRightX(), GetTopY() - STEP_SIZE)) //�V�W����
		{
			_y -= STEP_SIZE;
		}
	}
	void MonsterMosquito::moveDown(Map* m)
	{
		if (m->isEmpty(GetLeftX(), GetBottomY() + STEP_SIZE)) //�V�U����
		{
			_y += STEP_SIZE;
		}
	}
	void MonsterMosquito::moveLeft(Map* m)
	{
		if (m->isEmpty(GetLeftX() - STEP_SIZE, GetTopY()) && m->isEmpty(GetLeftX() - STEP_SIZE, GetBottomY())) //�V������
		{
			_x -= STEP_SIZE;
		}
	}
	void MonsterMosquito::moveRight(Map* m)
	{
		if (m->isEmpty(GetRightX() + STEP_SIZE, GetTopY()) && m->isEmpty(GetRightX() + STEP_SIZE, GetBottomY())) //�V�k����
		{
			_x += STEP_SIZE;
		}
	}
	void MonsterMosquito::flyCaseChanger()
	{
		if (flyCase < 4)
		{
			flyCase++;
		}
		else
		{
			flyCase = 1;
		}
	}
}
