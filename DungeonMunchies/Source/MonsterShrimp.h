#ifndef __MONSTERSHRIMP__
#define __MONSTERSHRIMP__

#include "Timer.h"
namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Shrimp������											   //
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
		void OnMove(Map* m) override;
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetBottomY();				// �k�U�� y �y��
		void showData();
	private:
		void attackOnMove();
		int velocity;
		CAnimation walkLeft;
		CAnimation walkRight;
		CAnimation attackLeft;
		CAnimation attackRight;
		CMovingBitmap deadLeft;
		CMovingBitmap deadRight;
		CMovingBitmap sourceShrimpAttack;
		CMovingBitmap sourceShrimpBlood;
		int randN;		
	};
}
#endif 