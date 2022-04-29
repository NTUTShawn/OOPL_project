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
#include "MonsterCactus.h"
#include "Util.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Cactus������											   //
	/////////////////////////////////////////////////////////////////////////////
	MonsterCactus::MonsterCactus()
	{
		_x = 400;
		_y = 400;
		hp = 10;
		attackDamage = 5;
	}

	MonsterCactus::MonsterCactus(int x, int y, Character* c) : Monster(x, y, 12, 5, c)
	{
	}

	MonsterCactus::~MonsterCactus()
	{
	}

	void MonsterCactus::LoadBitmap()
	{
		bloodBar.LoadBitmap();
		cactusAlive.LoadBitmap(IDB_MONSTERCACTUSALIVE, RGB(0, 0, 0));
		cactusDead.LoadBitmap(IDB_MONSTERCACTUSDEAD, RGB(0, 0, 0));
	}

	void MonsterCactus::Initialize()
	{
		_x = init_x;
		_y = init_y;
		hp = 10;
		attackDamage = 5;
		bloodBar.setFullHP(hp);
	}

	void MonsterCactus::OnShow(Map* m)
	{
		if (isAlive())
		{
			cactusAlive.SetTopLeft(_x, _y);
			cactusAlive.ShowBitmap();
			bloodBar.setXY(GetLeftX(), GetTopY() - 16);
			bloodBar.showBloodBar(m, hp);
		}
		if (!isAlive())
		{
			cactusDead.SetTopLeft(_x, _y + (cactusAlive.Height() - cactusDead.Height()));
			cactusDead.ShowBitmap();
		}
		showData();
	}

	void MonsterCactus::showData()
	{
		//int CharacterLeftX = character->GetLeftX();
		//int CharacterRightX = character->GetRightX();
		//int CharacterTopY = character->GetTopY();
		//int CharacterButtonY = character->GetButtonY();
		//CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		//CFont f, * fp;
		//f.CreatePointFont(120, "Times New Roman");	// ���� font f; 160���16 point���r
		//fp = pDC->SelectObject(&f);					// ��� font f
		//pDC->SetBkColor(RGB(230, 220, 200));
		//pDC->SetTextColor(RGB(0, 0, 0));
		//char position[500];								// Demo �Ʀr��r�ꪺ�ഫ
		//sprintf(position, "CharacterLeftX:%d CharacterRightX:%d CharacterTopY:%d CharacterButtonY:%d \r\n\
		//	CactusLeftX:%d CactusRightX:%d CactusTopY:%d CactusButtonY:%d"
		//	, CharacterLeftX, CharacterRightX, CharacterTopY, CharacterButtonY,
		//	GetLeftX(), GetRightX(), GetTopY(), GetButtonY());
		////sprintf(str, "CharacterLeftX : %d", CharacterLeftX);
		//pDC->TextOut(200, 100, position);
		//pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		//CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

	int MonsterCactus::GetLeftX()
	{
		return _x;
	}

	int MonsterCactus::GetTopY()
	{
		return _y;
	}

	int MonsterCactus::GetRightX()
	{
		return _x + cactusAlive.Width();
	}

	int MonsterCactus::GetButtonY()
	{
		return _y + cactusAlive.Height();
	}

	void MonsterCactus::intersect()
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

	void MonsterCactus::OnMove()
	{
		if (isAlive())
		{
			intersect();
		}
	}
}
