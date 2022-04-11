#ifndef __MONSTERGRASS__
#define __MONSTERGRASS__

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	//���ѽаѷ�BlueGoblin.h 												   //
	/////////////////////////////////////////////////////////////////////////////
	//class Monster;
	class MonsterCactus :public Monster {
	public:
		MonsterCactus();
		MonsterCactus(int x, int y, Character* c);
		~MonsterCactus();
		void LoadBitmap();
		void OnShow(Map* m) override;
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
		void Initialize()override;
		bool isIntersect() override;
		void SetXY(int x, int y);
	private:
		CMovingBitmap cactus;
	};
}
#endif 