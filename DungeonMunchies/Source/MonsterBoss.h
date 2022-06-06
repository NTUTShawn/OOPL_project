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
		void OnMove(Map* m) override;
		void OnShow(Map* m) override;
		void showData();
		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetButtonY();				// �k�U�� y �y��
		
	private:
		/*�欰*/
		/*����*/
		void walk(Map* m);
		void walkOnMove();
		void walkOnShow(Map* m);
		bool CanWalkL(Map* m);
		bool CanWalkR(Map* m);
		/*����*/
		void ResetAtkCounter();
		void atkCount(int i);
		//hit
		void hitStart();
		void hitOnMove();
		void hitOnShow(Map* m);
		void hitJudge();
		//collide
		void collideStart();
		void collideOnMove();
		void collideOnShow(Map* m);
		void collideJudge();
		void rushMove(Map* m);
		//thron
		void thronStart();
		void thronBossOnMove();
		void thronBossOnShow(Map* m);
		void thronOnShow(Map* m);
		void thronJudge();
		void SetCMidX();
		//dead
		void deadOnMove();
		void deadOnShow(Map* m);
		
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
		CAnimation deadRight;
		CAnimation deadLeft;

		/*����*/
		int atkCounter[3]; //�p������w�s��ϥδX�� (0:hit ; 1:collide ; 2:thronBoss)
		//hit
		int hitDamage;
		int hitDelayCount;
		bool hitCD;
		Timer hitCDTimer;
		//collide
		int rushDistance;
		int rushStepSize;
		//thron
		int thronDamage;
		int thronCount;
		int cMidX, floor;
		bool thronExist;
	};
}
#endif
