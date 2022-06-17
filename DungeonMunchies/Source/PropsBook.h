#ifndef __PropsBook__
#define __PropsBook__
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class����y�x�Ҧ�
	/////////////////////////////////////////////////////////////////////////////

	class Prop;
	class PropMosquitoJump;
	class PropShrimpBlood;
	class PropGrassFast;
	class PropBananaAttack;
	class PropShrimpAttack;
	class PropGuavaJuiceBlood;
	class PropStorage;
	class Character;
	class Source;
	class SourceStorage;

	class PropsBook
	{
	public:
		PropsBook();
		~PropsBook();
		void LoadBitmap();
		void Initialize(Character* character);
		void setXY(int x, int y);
		void setXY(CPoint mousePosition);
		int getMX();
		int getMY();
		void setCase();
		void setCase(CPoint mousePosition);
		void setIconList();
		vector<CMovingBitmap> setIconPosition(vector<CMovingBitmap> iconList);
		void cook();
		void sourceNumShow(int sourceCase);
		void propListOnShow();
		void propCancellation();
		CMovingBitmap* propBitmap(PropCase pc); //�^�Ǹ�bitmap�O��prop
		void onShow();
		void LightBulbOnShow();

		//cheat
		void getAllProps();
		void loseAllProps();
	private:
		int mx, my;
		int choicex, choicey;
		PropCase Case;

		CMovingBitmap propsBook;
		CMovingBitmap propsBookChoice;
		CMovingBitmap propHave;
		CMovingBitmap propsPot1;

		CMovingBitmap MosquitoJumpIcon;
		CMovingBitmap ShrimpBloodIcon;
		CMovingBitmap GrassFastIcon;
		CMovingBitmap BananaAttackIcon;
		CMovingBitmap ShrimpAttackIcon;
		CMovingBitmap GuavaJuiceBloodIcon;
		vector<CMovingBitmap> iconList;

		CMovingBitmap MosquitoJumpIconS;
		CMovingBitmap ShrimpBloodIconS;
		CMovingBitmap GrassFastIconS;
		CMovingBitmap BananaAttackIconS;
		CMovingBitmap ShrimpAttackIconS;
		CMovingBitmap GuavaJuiceBloodIconS;
		vector<PropCase> propList;
		int px;

		CMovingBitmap MosquitoJumpDetails;
		CMovingBitmap ShrimpBloodDetails;
		CMovingBitmap GrassFastDetails;
		CMovingBitmap BananaAttackDetails;
		CMovingBitmap ShrimpAttackDetails;
		CMovingBitmap GuavaJuiceBloodDetails;

		Character* _character;
		PropStorage* propStorage;
		SourceStorage* sourceStorage;
	};
}
#endif
