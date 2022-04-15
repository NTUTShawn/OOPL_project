#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <vector>
#include "Util.h"
#include "SourceStorage.h"
#include "Prop.h"
#include "PropMosquitoJump.h"
#include "PropShrimpBlood.h"
#include "PropGrassFast.h"
#include "PropBananaAttack.h"
#include "PropShrimpAttack.h"
#include "PropGuavaJuiceBlood.h"
#include "PropsBook.h"
#include "PropStorage.h"
#include "Character.h"
#include "Source.h"
#include "SourceStorage.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���D��ѼҦ�
	/////////////////////////////////////////////////////////////////////////////

	PropsBook::PropsBook()
	{
		Case = mosquito_jump_p;
	}

	PropsBook::~PropsBook()
	{
	}

	void PropsBook::LoadBitmap() {
		propsBook.LoadBitmap(IDB_PROPSBOOK);
		propsBookChoice.LoadBitmap(IDB_PROPSBOOKCHOICE, RGB(0, 0, 0));
		propHave.LoadBitmap(IDB_PROPHAVE);
		propsPot1.LoadBitmap(IDB_PROPSPOT1);

		MosquitoJumpIcon.LoadBitmap(IDB_PROPMOSQUITOJUMPICON);
		ShrimpBloodIcon.LoadBitmap(IDB_PROPSHRIMPBLOODICON);
		GrassFastIcon.LoadBitmap(IDB_PROPGRASSFASTICON);
		BananaAttackIcon.LoadBitmap(IDB_PROPBANANAATTACKICON);
		ShrimpAttackIcon.LoadBitmap(IDB_PROPSHRIMPATTACKICON);
		GuavaJuiceBloodIcon.LoadBitmap(IDB_PROPGUAVAJUICEBLOODICON);

		MosquitoJumpDetails.LoadBitmap(IDB_PROPMOSQUITOJUMP);
		ShrimpBloodDetails.LoadBitmap(IDB_PROPSHRIMPBLOOD);
		GrassFastDetails.LoadBitmap(IDB_PROPGRASSFAST);
		BananaAttackDetails.LoadBitmap(IDB_PROPBANANAATTACK);
		ShrimpAttackDetails.LoadBitmap(IDB_PROPSHRIMPATTACK);
		GuavaJuiceBloodDetails.LoadBitmap(IDB_PROPGUAVAJUICEBLOOD);
	}

	void PropsBook::Initialize(Character* character) {
		Case = mosquito_jump_p;
		choicex = 177;
		choicey = 127;
		setIconList();
		propStorage = character->GetPropStorage();
		sourceStorage = character->GetSourceStorage();
		_character = character;
	}

	void PropsBook::setXY(CPoint mousePosition) {
		mx = mousePosition.x;
		my = mousePosition.y;
	}

	void PropsBook::setXY(int x, int y) {
		mx = x;
		my = y;
	}

	int PropsBook::getMX() {
		return mx;
	}

	int PropsBook::getMY() {
		return my;
	}

	void PropsBook::setCase() {
		int column = (mx - 177) / 62;
		int row = (my - 127) / 62;
		if (row == 0 && column == 0) {
			Case = mosquito_jump_p;
		}
		else if (row == 0 && column == 1) {
			Case = shrimp_blood_p;
		}
		else if (row == 0 && column == 2) {
			Case = grass_fast_p;
		}
		else if (row == 0 && column == 3) {
			Case = banana_attack_p;
		}
		else if (row == 0 && column == 4) {
			Case = shrimp_attack_p;
		}
		else if (row == 0 && column == 5) {
			Case = guava_juice_blood_p;
		}
		choicex = column * 62 + 177;
		choicey = row * 62 + 128;
	}

	void PropsBook::setCase(CPoint mousePosition) {
		setXY(mousePosition);
		if (mx > 177 && my > 127 && mx < 543 && my < 185) {
			setCase();
		}
		else if (mx > 900 && my > 580 && mx < 1023 && my < 623) {
			cook();
		}
	}

	void PropsBook::setIconList() {
		iconList.push_back(MosquitoJumpIcon);
		iconList.push_back(ShrimpBloodIcon);
		iconList.push_back(GrassFastIcon);
		iconList.push_back(BananaAttackIcon);
		iconList.push_back(ShrimpAttackIcon);
		iconList.push_back(GuavaJuiceBloodIcon);
		iconList = setIconPosition(iconList);
	}
	
	vector<CMovingBitmap> PropsBook::setIconPosition(vector<CMovingBitmap> iconList) {
		int iconx, icony;
		int counter = 0;
		for (int row = 0; row < 7; row++) {
			icony = row * 62 + 127;
			for (int column = 0; column < 7; column++) {
				iconx = column * 62 + 177;
				iconList[counter].SetTopLeft(iconx, icony);
				if (counter == (iconList).size()-1) {
					return iconList;
				}
				counter++;
			}
		}
		return iconList;
	}

	void PropsBook::cook() { //�ιL����A��
		switch (Case) {
		case mosquito_jump_p:
			if (!(propStorage->getProp(mosquito_jump_p)->getPropFlag()) && sourceStorage->getSource(mosquito_jump_p)->getNum() >= 5) {
				sourceStorage->getSource(mosquito_jump_p)->consume(5);
				propStorage->getProp(mosquito_jump_p)->setPropFlag(true);
				propStorage->getProp(mosquito_jump_p)->effect(_character);
			}
			break;
		case shrimp_blood_p:
			if (!(propStorage->getProp(shrimp_blood_p)->getPropFlag()) && sourceStorage->getSource(shrimp_blood_p)->getNum() >= 1) {
				sourceStorage->getSource(shrimp_blood_p)->consume(1);
				propStorage->getProp(shrimp_blood_p)->setPropFlag(true);
				propStorage->getProp(shrimp_blood_p)->effect(_character);
			}
			break;
		case grass_fast_p:
			if (!(propStorage->getProp(grass_fast_p)->getPropFlag()) && sourceStorage->getSource(grass_fast_p)->getNum() >= 5) {
				sourceStorage->getSource(grass_fast_p)->consume(5);
				propStorage->getProp(grass_fast_p)->setPropFlag(true);
				propStorage->getProp(grass_fast_p)->effect(_character);
			}
			break;
		case banana_attack_p:
			if (!(propStorage->getProp(banana_attack_p)->getPropFlag()) && sourceStorage->getSource(banana_attack_p)->getNum() >= 1) {
				sourceStorage->getSource(banana_attack_p)->consume(1);
				propStorage->getProp(banana_attack_p)->setPropFlag(true);
				propStorage->getProp(banana_attack_p)->effect(_character);
			}
			break;
		case shrimp_attack_p:
			if (!(propStorage->getProp(shrimp_attack_p)->getPropFlag()) && sourceStorage->getSource(guava_juice_blood_p)->getNum() >= 1) {
				sourceStorage->getSource(shrimp_attack_p)->consume(1);
				propStorage->getProp(shrimp_attack_p)->setPropFlag(true);
				propStorage->getProp(shrimp_attack_p)->effect(_character);
			}
			break;
		case guava_juice_blood_p:
			if (!(propStorage->getProp(guava_juice_blood_p)->getPropFlag()) && sourceStorage->getSource(guava_juice_blood_p)->getNum() >= 1) {
				sourceStorage->getSource(guava_juice_blood_p)->consume(1);
				propStorage->getProp(guava_juice_blood_p)->setPropFlag(true);
				propStorage->getProp(guava_juice_blood_p)->effect(_character);
			}
			break;
		default:
			break;
		}
	}

	void PropsBook::sourceNumShow(int sourceCase) {
		int sourceNum = sourceStorage->getSource(sourceCase)->getNum();
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(100, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(230, 220, 200));
		pDC->SetTextColor(RGB(0, 0, 0));
		CString cstr(to_string(sourceNum).c_str());
		pDC->TextOut(890, 395, cstr);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

    void PropsBook::onShow() {
		propsBook.SetTopLeft(0, 0);
		propsBook.ShowBitmap();
		propHave.SetTopLeft(675, 350);
		propsPot1.SetTopLeft(806,530);
		MosquitoJumpDetails.SetTopLeft(673, 38);
		ShrimpBloodDetails.SetTopLeft(673, 38);
		GrassFastDetails.SetTopLeft(673, 38);
		BananaAttackDetails.SetTopLeft(673, 38);
		ShrimpAttackDetails.SetTopLeft(673, 38);
		GuavaJuiceBloodDetails.SetTopLeft(673, 38);

		for (unsigned int i = 0; i < iconList.size(); i++) {
			if (propStorage->getProp(i)->getPropFlag()) {
				iconList[i].ShowBitmap();
			}
		}

		switch (Case) {
		case mosquito_jump_p:
			MosquitoJumpDetails.ShowBitmap();
			sourceNumShow(mosquito_jump_p);
			if (propStorage->getProp(mosquito_jump_p)->getPropFlag()) {
				propHave.ShowBitmap();
				propsPot1.ShowBitmap();
			}
			break;
		case shrimp_blood_p:
			ShrimpBloodDetails.ShowBitmap();
			sourceNumShow(shrimp_blood_p);
			if (propStorage->getProp(shrimp_blood_p)->getPropFlag()) {
				propHave.ShowBitmap();
				propsPot1.ShowBitmap();
			}
			break;
		case grass_fast_p:
			GrassFastDetails.ShowBitmap();
			sourceNumShow(grass_fast_p);
			if (propStorage->getProp(grass_fast_p)->getPropFlag()) {
				propHave.ShowBitmap();
				propsPot1.ShowBitmap();
			}
			break;
		case banana_attack_p:
			BananaAttackDetails.ShowBitmap();
			sourceNumShow(banana_attack_p);
			if (propStorage->getProp(banana_attack_p)->getPropFlag()) {
				propHave.ShowBitmap();
				propsPot1.ShowBitmap();
			}
			break;
		case shrimp_attack_p:
			ShrimpAttackDetails.ShowBitmap();
			sourceNumShow(shrimp_attack_p);
			if (propStorage->getProp(shrimp_attack_p)->getPropFlag()) {
				propHave.ShowBitmap();
				propsPot1.ShowBitmap();
			}
			break;
		case guava_juice_blood_p:
			GuavaJuiceBloodDetails.ShowBitmap();
			sourceNumShow(guava_juice_blood_p);
			if (propStorage->getProp(guava_juice_blood_p)->getPropFlag()) {
				propHave.ShowBitmap();
				propsPot1.ShowBitmap();
			}
			break;
		default:
			break;
		}
		propsBookChoice.SetTopLeft(choicex, choicey);
		propsBookChoice.ShowBitmap();
    }
}