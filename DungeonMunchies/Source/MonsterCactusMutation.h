#ifndef __MonsterCactusMUTATION__
#define __MonsterCactusMUTATION__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Cactus������											   //
	/////////////////////////////////////////////////////////////////////////////
	//class Monster;

	class MonsterCactusMutation :public Monster
	{
	public:
		MonsterCactusMutation();
		MonsterCactusMutation(int x, int y, Character* c);
		~MonsterCactusMutation();
		void LoadBitmap();
		void Initialize() override;
		void OnShow(Map* m) override;
		void showData();
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
		void OnMove(Map* m) override;
	private:
		CMovingBitmap cactusAlive;
		CMovingBitmap cactusDead;
		CMovingBitmap sourceGreenSword;
	};
}
#endif 