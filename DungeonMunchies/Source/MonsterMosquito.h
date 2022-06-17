#ifndef __MONSTERMOSQUITO__
#define __MONSTERMOSQUITO__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Mosquito������											   //
	/////////////////////////////////////////////////////////////////////////////
	class MonsterMosquito :public Monster
	{
	public:
		MonsterMosquito();
		MonsterMosquito(int x, int y, Character* c);
		~MonsterMosquito();
		void LoadBitmap();
		void Initialize() override;
		void OnMove(Map* m) override;
		void OnShow(Map* m) override;
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetBottomY();				// �k�U�� y �y��
	private:
		void moveUp(Map* m);
		void moveDown(Map* m);
		void moveLeft(Map* m);
		void moveRight(Map* m);
		void flyCaseChanger();
		int velocity;
		int flyCase;
		bool shouldFlyCaseChange;
		Timer flyTimer;
		CAnimation faceLeft;
		CAnimation faceRight;
		CMovingBitmap sourceMosquitoJump;
	};
}
#endif 