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
		void OnMove(Map* m) override;
		void SetFacingLR(bool flag);
		bool GetFacingLR();
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
		Action actionController();
		void showData();
	private:
		void walkOnMove();
		void attackOnMove();
		int velocity;
		CMovingBitmap sleepLeft;
		CMovingBitmap sleepRight;
		CAnimation walkLeft;
		CAnimation walkRight;
		CAnimation attackLeft;
		CAnimation attackRight;
		CMovingBitmap deadLeft;
		CMovingBitmap deadRight;
		CMovingBitmap sourceGuavaJuiceBlood;
	};
}
#endif 