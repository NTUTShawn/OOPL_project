#ifndef __MONSTERBANANA__
#define __MONSTERBANANA__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Banana������											   //
	/////////////////////////////////////////////////////////////////////////////
	class MonsterBanana :public Monster
	{
	public:
		MonsterBanana();
		MonsterBanana(int x, int y, Character* c);
		~MonsterBanana();
		void LoadBitmap();
		void Initialize() override;
		void OnShow(Map* m) override;
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetBottomY();				// �k�U�� y �y��
		void OnMove(Map* m) override;
	private:
		CMovingBitmap bananaAlive;
		CMovingBitmap bananaDead;
		CMovingBitmap sourceBananaAttack;
	};
}
#endif 