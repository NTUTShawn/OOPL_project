#ifndef __MONSTERTREE__
#define __MONSTERTREE__

#include "Timer.h"
namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Shrimp������											   //
	/////////////////////////////////////////////////////////////////////////////
	//class Monster;
	class MonsterTree :public Monster
	{
	public:
		MonsterTree();
		MonsterTree(int x, int y, Character* c);
		~MonsterTree();
		void LoadBitmap();
		void Initialize() override;
		void OnShow(Map* m) override;
		void OnMove();
		void SetFacingLR(bool flag);
		bool GetFacingLR();
		void SetActionNum(int num);
		bool GetActionNum();
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
		void attack();
		void showData();
	private:
		int actionNum; // 0��ܦb�����A1������
		CMovingBitmap sleepLeft;
		CMovingBitmap sleepRight;
		CAnimation walkLeft;
		CAnimation walkRight;
		CAnimation attackLeft;
		CAnimation attackRight;
		CMovingBitmap deadLeft;
		CMovingBitmap deadRight;
		Timer attackCDTime;
		bool attackCD;
	};
}
#endif 