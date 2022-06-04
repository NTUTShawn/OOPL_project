#ifndef __MONSTERBANANA__
#define __MONSTERBANANA__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//這個class是怪物Banana的物件											   //
	/////////////////////////////////////////////////////////////////////////////
	//class Monster;

	class MonsterBanana :public Monster
	{
	public:
		MonsterBanana();
		MonsterBanana(int x, int y, Character* c);
		~MonsterBanana();
		void LoadBitmap();
		void Initialize() override;
		void OnShow(Map* m) override;
		void showData();
		int  GetLeftX();				// 左上角 x 座標
		int  GetTopY();					// 左上角 y 座標
		int  GetRightX();				// 右下角 x 座標
		int  GetButtonY();				// 右下角 y 座標
		void OnMove(Map* m) override;
		//Map* GetMap();
	private:
		CMovingBitmap bananaAlive;
		CMovingBitmap bananaDead;
		CMovingBitmap sourceBananaAttack;
		//Map* currentMap;
	};
}
#endif 