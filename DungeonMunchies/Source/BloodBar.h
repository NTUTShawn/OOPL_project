#ifndef __BLOODBAR__
#define __BLOODBAR__

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѧ��													   //
	/////////////////////////////////////////////////////////////////////////////
	class Map;
	class BloodBar
	{
	public:
		BloodBar();
		void loadBloodBar();
		void showBloodBar(Map* m, int hp);
		void setFullHP(int n);					//�]�w���媺��q
		void setXY(int x, int y);				//�]�w�����x y �y��
		int getFullHP();						//�^�Ǻ��媺��q
	private:
		CMovingBitmap bloodBar[10];			//���P���ת����
		double fullHp;
		int _x, _y;
	};
}
#endif#pragma once
