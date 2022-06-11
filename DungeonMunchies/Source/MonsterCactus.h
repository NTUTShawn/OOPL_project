#ifndef __MONSTERCACTUS__
#define __MONSTERCACTUS__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Cactus������											   //
	/////////////////////////////////////////////////////////////////////////////
	//class Monster;
	
	class MonsterCactus :public Monster
	{
	public:
		MonsterCactus();
		MonsterCactus(int x, int y, Character* c);
		~MonsterCactus();
		void LoadBitmap();
		void Initialize() override;
		void OnShow(Map* m) override;
		void showData();
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetBottomY();				// �k�U�� y �y��
		void OnMove(Map* m) override;
	private:
		CMovingBitmap cactusAlive;
		CMovingBitmap cactusDead;
		CMovingBitmap sourceGrassFast;
	};
}
#endif 