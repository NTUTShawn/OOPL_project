#ifndef __MONSTERSHRIMP__
#define __MONSTERSHRIMP__

#include "Counter.h"
namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Cactus������											   //
	/////////////////////////////////////////////////////////////////////////////
	//class Monster;
	class MonsterShrimp :public Monster
	{
	public:
		MonsterShrimp();
		MonsterShrimp(int x, int y, Character* c);
		~MonsterShrimp();
		void LoadBitmap();
		void Initialize() override;
		void OnShow(Map* m) override;
		void OnMove();
		void showData();
		void SetFacingLR(bool flag);
		bool GetFacingLR();
		void SetActionNum(int num);
		bool GetActionNum();
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
		void SetXY(int x, int y);
		void attack();
	private:
		int actionNum; // 0��ܦb�����A1������
		CAnimation walkLeft;
		CAnimation walkRight;
		CAnimation attackLeft;
		CAnimation attackRight;
		CMovingBitmap deadLeft;
		CMovingBitmap deadRight;
		Counter attackCDTime;
		bool attackCD;
	};
}
#endif 