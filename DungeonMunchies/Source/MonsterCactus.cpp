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
		hp = 50;
		attackDamage = 5;
		BORDER = 20;
		HORIZONTAL_GAP = 0;
	}

	MonsterCactus::MonsterCactus(int x, int y, Character* c) : Monster(x, y, 12, 5, c)
	{
		BORDER = 20;
		HORIZONTAL_GAP = 0;
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
		RelativeMovement = 0;
		hp = 100;
		attackDamage = 5;
		bloodBar.setFullHP(hp);
	}

	void MonsterCactus::OnShow(Map* m)
	{
		if (isAlive())
		{
			cactusAlive.SetTopLeft(_x + RelativeMovement, _y);
			cactusAlive.ShowBitmap();
			bloodBar.setXY(GetLeftX() + RelativeMovement, GetTopY() - 16);
			bloodBar.showBloodBar(m, hp);
		}
		if (!isAlive())
		{
			cactusDead.SetTopLeft(_x + RelativeMovement, _y + (cactusAlive.Height() - cactusDead.Height()));
			cactusDead.ShowBitmap();
		}
		showData();
	}

	void MonsterCactus::showData()
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
		sprintf(position, "CactusLeftX:%d CactusRightX:%d CactusTopY:%d CactusButtonY:%d CactusHp: %d"
			, GetLeftX(), GetRightX(), GetTopY(), GetButtonY(), GetCurrentHp());
		//sprintf(str, "CharacterLeftX : %d", CharacterLeftX);
		pDC->TextOut(200, 50, position);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
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

	void MonsterCactus::OnMove()
	{
		if (isAlive())
		{
			intersect();
		}
		if (!character->GetMap() == NULL)
		{
			character->GetMap()->monsterFloorChanging(GetLeftX());
			_y = character->GetMap()->getMonsterFloor() -80;
		}
	}
}
