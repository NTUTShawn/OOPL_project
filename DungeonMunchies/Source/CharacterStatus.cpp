#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <vector>
#include "Util.h"
#include "Character.h"
#include "CharacterStatus.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���D��ѼҦ�
	/////////////////////////////////////////////////////////////////////////////

	CharacterStatus::CharacterStatus()
	{
	}

	CharacterStatus::~CharacterStatus()
	{
	}

	void CharacterStatus::LoadBitmap()
	{
		characterStatus.LoadBitmap(".\\res\\character_status.bmp");
	}

	void CharacterStatus::Initialize(Character* character)
	{
		_character = character;
		row = 0;
		col[3] = { 0 };
		haveFirstLine = false;
		x = 508;
		y = 434;
		mjLen = 120;
		gfLen = 150;
		sbLen = 150;
	}

	void CharacterStatus::onShow()
	{
		characterStatus.SetTopLeft(282, 113);
		characterStatus.ShowBitmap();
		showhp();
		showAttackDamage();
		showAttackRange();
		showSpeed();
		showEffect();
	}

	void CharacterStatus::showhp()
	{
		showData(450, 222, _character->GetCurrentHp(), _character->GetMaxHp());
	}

	void CharacterStatus::showAttackDamage()
	{
		showData(474, 276, _character->GetAttackDamage());
	}

	void CharacterStatus::showAttackRange()
	{
		showData(503, 329, _character->GetAttackRange());
	}

	void CharacterStatus::showSpeed()
	{
		showData(447, 381, _character->GetSpeed());
	}

	void CharacterStatus::showEffect()
	{
		x = 508;
		y = 434;
		effectCheck();
		if (haveFirstLine)
		{
			if (col[0] == 1)
			{
				showData(x, y, "�G�q��");
				x += mjLen;
			}
			if (col[1] == 1)
			{
				showData(x, y, "�t��+40%");
				x += gfLen;
			}
			if (col[2] == 1)
			{
				showData(x, y, "�̤j�ͩR+20");
				x += sbLen;
			}
			y += 45;
			x = 508;
		}
		if (_character->GetIsGuavaJuiceBlood())
		{
			showData(x, y, "�C�Q���_3�I��q");
			y += 45;
		}
		if (_character->GetIsBananaAttack())
		{
			showData(x, y, "��ԧ���+3");
			y += 45;
		}
		if (_character->GetIsShrimpAttack())
		{
			showData(x, y, "�������@�q�ɶ��A�U������+15");
			y += 45;
		}
	}

	void CharacterStatus::effectCheck()
	{
		row = 0;
		col[3] = { 0 };
		if (_character->GetIsMosquitoJump() || _character->GetIsGrassFast() || _character->GetIsShrimpBlood())
		{
			haveFirstLine = true;
			row += 1;
			if (_character->GetIsMosquitoJump())
			{
				col[0] = 1;
			}
			if (_character->GetIsGrassFast())
			{
				col[1] = 1;
			}
			if (_character->GetIsShrimpBlood())
			{
				col[2] = 1;
			}
		}
		//if (_character->GetIsGuavaJuiceBlood())
		//{
		//	row += 1;
		//}
		//if (_character->GetIsBananaAttack())
		//{
		//	row += 1;
		//}
		//if (_character->GetIsShrimpAttack())
		//{
		//	row += 1;
		//}
	}

	void CharacterStatus::showData(int x, int y, int data)
	{
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(200, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		char position[500];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(position, "%d", data);
		pDC->TextOut(x, y, position);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

	void CharacterStatus::showData(int x, int y, char* data)
	{
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(200, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		char position[500];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(position, "%s", data);
		pDC->TextOut(x, y, position);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

	void CharacterStatus::showData(int x, int y, int data1, int data2)
	{
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(200, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		char position[500];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(position, "%d / %d", data1, data2);
		pDC->TextOut(x, y, position);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}
}