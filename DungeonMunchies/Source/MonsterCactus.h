#ifndef __MONSTERGRASS__
#define __MONSTERGRASS__

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
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
		bool isIntersect() override;
		void SetXY(int x, int y);
		void OnMove(Map* m);
	private:
		CMovingBitmap cactusAlive;
		CMovingBitmap cactusDead;
	};
}
#endif 