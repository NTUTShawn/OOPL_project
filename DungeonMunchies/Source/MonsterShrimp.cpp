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
#include "Util.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Cactus������											   //
	/////////////////////////////////////////////////////////////////////////////
	MonsterShrimp::MonsterShrimp()
	{
		_x = 400;
		_y = 400;
		hp = 10;
		attackDamage = 5;
	}

	MonsterShrimp::MonsterShrimp(int x, int y, Character* c) : Monster(x, y, 12, 5, c)
	{
	}

	MonsterShrimp::~MonsterShrimp()
	{
	}

	void MonsterShrimp::LoadBitmap()
	{
		bloodBar.LoadBitmap();

		walkLeft.AddBitmap(".\\res\\monster_shrimp_walk01_left.bmp", RGB(0, 0, 0));
		walkLeft.AddBitmap(".\\res\\monster_shrimp_walk02_left.bmp", RGB(0, 0, 0));
		walkRight.AddBitmap(".\\res\\monster_shrimp_walk01_right.bmp", RGB(0, 0, 0));
		walkRight.AddBitmap(".\\res\\monster_shrimp_walk02_right.bmp", RGB(0, 0, 0));

		attackLeft.AddBitmap(".\\res\\monster_shrimp_attack02_left.bmp", RGB(0, 0, 0));
		attackLeft.AddBitmap(".\\res\\monster_shrimp_attack02_left.bmp", RGB(0, 0, 0));
		attackLeft.AddBitmap(".\\res\\monster_shrimp_attack02_left.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_shrimp_attack02_right.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_shrimp_attack02_right.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_shrimp_attack02_right.bmp", RGB(0, 0, 0));

		deadLeft.LoadBitmap(".\\res\\monster_shrimp_dead_left.bmp", RGB(0, 0, 0));
		deadRight.LoadBitmap(".\\res\\monster_shrimp_dead_right.bmp", RGB(0, 0, 0));
	}

	void MonsterShrimp::Initialize()
	{
		_x = init_x;
		_y = init_y;
		hp = 10;
		attackDamage = 5;
		facingLR = 1;
		actionNum = 0;
		bloodBar.setFullHP(hp);
	}

	void MonsterShrimp::OnShow(Map* m)
	{
		if (isAlive())
		{
			if (facingLR == 0)
			{
				walkLeft.SetTopLeft(_x - 200, _y);
				//walkLeft.SetDelayCount(3);
				walkLeft.OnShow();
			}
			else
			{
				walkRight.SetTopLeft(_x, _y);
				//walkLeft.SetDelayCount(3);
				walkRight.OnShow();
			}
			bloodBar.setXY(GetLeftX(), GetTopY() - 16);
			bloodBar.showBloodBar(m, hp);
		}
		if (!isAlive())
		{
			if (facingLR == 0)
			{
				deadLeft.SetTopLeft(_x, _y);
				deadLeft.ShowBitmap();
			}
			else
			{
				deadRight.SetTopLeft(_x, _y);
				deadRight.ShowBitmap();
			}
			//cactusDead.SetTopLeft(_x, _y + (cactusAlive.Height() - cactusDead.Height()));
			//cactusDead.ShowBitmap();
		}
		showData();
	}

	void MonsterShrimp::showData()
	{
		int CharacterLeftX = character->GetLeftX();
		int CharacterRightX = character->GetRightX();
		int CharacterTopY = character->GetTopY();
		int CharacterButtonY = character->GetButtonY();
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(120, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(230, 220, 200));
		pDC->SetTextColor(RGB(0, 0, 0));
		char position[500];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(position, "CharacterLeftX:%d CharacterRightX:%d CharacterTopY:%d CharacterButtonY:%d \r\n\
			ShrimpLeftX:%d ShrimpRightX:%d ShrimpTopY:%d ShrimpButtonY:%d"
			, CharacterLeftX, CharacterRightX, CharacterTopY, CharacterButtonY,
			GetLeftX(), GetRightX(), GetTopY(), GetButtonY());
		//sprintf(str, "CharacterLeftX : %d", CharacterLeftX);
		pDC->TextOut(200, 100, position);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

	void MonsterShrimp::SetFacingLR(bool flag)
	{
		facingLR = flag;
	}

	bool MonsterShrimp::GetFacingLR()
	{
		return facingLR;
	}

	void MonsterShrimp::SetActionNum(int num)
	{
		actionNum = num;
	}

	bool MonsterShrimp::GetActionNum()
	{
		return actionNum;
	}

	int MonsterShrimp::GetLeftX() //��ܪ��Ϸ|�۰ʩ�����a�A�����վ�
	{
		return _x;
	}

	int MonsterShrimp::GetTopY() //�ݽվ�H������ܪ���(_y + (�Ϥ�����-���鰪��))
	{
		//return _y;
		if (actionNum == 0) //walk
		{
			return _y + 130; //380-150
		}
		else// if (actionNum == 1) //attack
		{
			return _y + 95;
		}
	}

	int MonsterShrimp::GetRightX()
	{
		if (actionNum == 0) //walk 
		{
			return _x + 185; //�[�W���饻��������
		}
		else // if (actionNum == 1) //attack 
		{
			return _x + 230;
		}
	}

	int MonsterShrimp::GetButtonY()
	{
		return _y + walkLeft.Height();
	}

	void MonsterShrimp::intersect()
	{
		if (isAlive())
		{
			if (character->GetRightX() >= GetLeftX() && character->GetRightX() <= GetRightX()
				&& character->GetButtonY() >= GetTopY() - 20 && character->GetButtonY() <= GetButtonY())
			{ //����k��I��Ǫ�
				character->SetIsAttackedFromRight(true);
				isIntersect = true;
			}
			if (character->GetLeftX() <= GetRightX() && character->GetLeftX() >= GetLeftX()
				&& character->GetButtonY() >= GetTopY() - 20 && character->GetButtonY() <= GetButtonY())
			{ //���⥪��I��Ǫ�
				character->SetIsAttackedFromLeft(true);
				isIntersect = true;
			}
			if ((character->GetRightX() >= GetLeftX() && character->GetRightX() <= GetRightX() ||
				character->GetLeftX() <= GetRightX() && character->GetLeftX() >= GetLeftX())
				&& character->GetButtonY() >= GetTopY() - 20 && character->GetButtonY() <= GetButtonY())
			{ //����U��I��Ǫ�
				character->SetIsAttackedFromButton(true);
				isIntersect = true;
			}
			if (isIntersect && !character->GetIsInvincible())
			{
				character->lossCurrentHp(attackDamage);
			}
		}
		isIntersect = false;
	}

	void MonsterShrimp::OnMove()
	{
		if (isAlive())
		{
			walkLeft.OnMove();
			walkRight.OnMove();

			attackLeft.OnMove();
			attackRight.OnMove();

			intersect();
		}
	}
}
