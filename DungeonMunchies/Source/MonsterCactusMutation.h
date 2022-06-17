#ifndef __MonsterCactusMUTATION__
#define __MonsterCactusMUTATION__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�CactusMutation������											   //
	/////////////////////////////////////////////////////////////////////////////
	class MonsterCactusMutation :public Monster
	{
	public:
		MonsterCactusMutation();
		MonsterCactusMutation(int x, int y, Character* c);
		~MonsterCactusMutation();
		void LoadBitmap();
		void Initialize() override;
		void OnShow(Map* m) override;
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetBottomY();				// �k�U�� y �y��
		void OnMove(Map* m) override;
	private:
		CMovingBitmap cactusAlive;
		CMovingBitmap cactusDead;
		CMovingBitmap sourceGreenSword;
	};
}
#endif 