#ifndef __MONSTERMOSQUITO__
#define __MONSTERMOSQUITO__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Mosquito������											   //
	/////////////////////////////////////////////////////////////////////////////
	//class Monster;

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
		void showData();
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
	private:
		int velocity;
		CAnimation faceLeft;
		CAnimation faceRight;
		CMovingBitmap sourceMosquitoJump;
	};
}
#endif 