#ifndef __MONSTERBOSS__
#define __MONSTERBOSS__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�Boss������											   //
	/////////////////////////////////////////////////////////////////////////////
	//class Monster;
	class MonsterBoss :public Monster
	{
	public:
		MonsterBoss();
		MonsterBoss(int x, int y, Character* c);
		~MonsterBoss();
		void LoadBitmap();
		void Initialize() override;
		void OnShow(Map* m) override;
		void showData();
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
		void intersect() override;
		void SetXY(int x, int y);
		void OnMove();
	private:
		CAnimation walkingRight;        // �V�k�樫�ʵe
		CAnimation walkingLeft;         // �V���樫�ʵe
		CAnimation collideRight;        // �V�k�ļ��ʵe
		CAnimation collideLeft;        // �V���ļ��ʵe
		CAnimation hitRight;        // �V�k���ʵe
		CAnimation hitLeft;        // �V�����ʵe
		CAnimation hitRightEffect;        // �V�k���ʵe
		CAnimation hitLeftEffect;        // �V�����ʵe
		CAnimation thronRight;        // �V�k��ʵe
		CAnimation thronLeft;        // �V����ʵe
		CAnimation thron;        // ��ʵe

	};
}
#endif
