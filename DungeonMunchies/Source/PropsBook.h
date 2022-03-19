#ifndef __PropsBook__
#define __PropsBook__
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѧa�Ϻc��
	/////////////////////////////////////////////////////////////////////////////
	class PropsBook
	{
	public:
		PropsBook();
		void Initialize();
		void setXY(int x, int y);
		void setXY(CPoint mousePosition);
		int getMX();
		int getMY();
		void LoadBitmap();
		void onShow();
	private:
		int mx, my;
		CMovingBitmap propsBook;
		CMovingBitmap sourceGrassFast;
	};
}
#endif
