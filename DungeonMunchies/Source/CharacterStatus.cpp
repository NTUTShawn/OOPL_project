#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <vector>
#include "Character.h"
#include "CharacterStatus.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為道具書模式
	/////////////////////////////////////////////////////////////////////////////

	CharacterStatus::CharacterStatus()
	{
	}

	CharacterStatus::~CharacterStatus()
	{
	}

	void CharacterStatus::LoadBitmap()
	{
		characterStatus.LoadBitmap(IDB_HEROSTATUS);
	}

	void CharacterStatus::Initialize(Character* character)
	{
		_character = character;
		_stage = stage_1;
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
		showStage();
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
				showData(x, y, "二段跳");
				x += mjLen;
			}
			if (col[1] == 1)
			{
				showData(x, y, "速度+40%");
				x += gfLen;
			}
			if (col[2] == 1)
			{
				showData(x, y, "最大生命+20");
				x += sbLen;
			}
			y += 45;
			x = 508;
		}
		if (_character->GetIsGuavaJuiceBlood())
		{
			showData(x, y, "每十秒恢復3點血量");
			y += 45;
		}
		if (_character->GetIsBananaAttack())
		{
			showData(x, y, "近戰攻擊+3");
			y += 45;
		}
		if (_character->GetIsShrimpAttack())
		{
			showData(x, y, "不攻擊一段時間，下次攻擊+15");
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
			else
			{
				col[0] = 0;
			}
			if (_character->GetIsGrassFast())
			{
				col[1] = 1;
			}
			else
			{
				col[1] = 0;
			}
			if (_character->GetIsShrimpBlood())
			{
				col[2] = 1;
			}
			else
			{
				col[2] = 0;
			}
		}
	}

	void CharacterStatus::showData(int x, int y, int data)
	{
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CFont f, * fp;
		f.CreatePointFont(200, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		char position[500];								// Demo 數字對字串的轉換
		sprintf(position, "%d", data);
		pDC->TextOut(x, y, position);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}

	void CharacterStatus::showData(int x, int y, char* data)
	{
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CFont f, * fp;
		f.CreatePointFont(200, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		char position[500];								// Demo 數字對字串的轉換
		sprintf(position, "%s", data);
		pDC->TextOut(x, y, position);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}

	void CharacterStatus::showData(int x, int y, int data1, int data2)
	{
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CFont f, * fp;
		f.CreatePointFont(200, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		char position[500];								// Demo 數字對字串的轉換
		sprintf(position, "%d / %d", data1, data2);
		pDC->TextOut(x, y, position);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}

	void CharacterStatus::setStage(Stage stage)
	{
		_stage = stage;
	}

	Stage CharacterStatus::getStage()
	{
		return _stage;
	}

	void CharacterStatus::showStage()
	{
		if (_stage == stage_1)
		{
			cstage = "第一關";
		}
		else if (_stage == stage_2)
		{
			cstage = "第二關";
		}
		else if (_stage == stage_3)
		{
			cstage = "第三關";
		}
		else if (_stage == stage_4)
		{
			cstage = "第四關";
		}
		else if (_stage == stage_5)
		{
			cstage = "第五關";
		}
		else if (_stage == stage_6)
		{
			cstage = "第六關";
		}
		else if (_stage == stage_boss)
		{
			cstage = "王關";
		}
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CFont f, * fp;
		f.CreatePointFont(240, "標楷體");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		char position[500];								// Demo 數字對字串的轉換
		sprintf(position, "%s", cstage);
		pDC->TextOut(478, 150, position);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}
}