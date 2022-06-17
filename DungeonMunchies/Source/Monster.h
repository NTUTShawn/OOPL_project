#ifndef __MONSTER__
#define __MONSTER__
#include "BloodBar.h"
#include "Timer.h"
namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class�O�ĤH������    											   //
	/////////////////////////////////////////////////////////////////////////////
	class Character;
	class Map;
	class BloodBar;
	class SourceStorage;
	class Monster
	{
	public:
		Monster();
		Monster::Monster(int x, int y, int enemyHp, int attackDamage, Character* c);
		virtual ~Monster();
		virtual void LoadBitmap() = 0;				//�[���ĤHBitmap
		virtual void Initialize() = 0;				//��l��
		virtual void OnShow(Map* m) = 0;			//��ܼĤH��e���W
		virtual void OnMove(Map* m) = 0;					//�ĤH����
		virtual int  GetLeftX() = 0;				// ���W�� x �y��
		virtual int  GetTopY() = 0;					// ���W�� y �y��
		virtual int  GetRightX() = 0;				// �k�U�� x �y��
		virtual int  GetBottomY() = 0;				// �k�U�� y �y��
		//�^���O�_�M���ĤH�IĲ
		virtual void intersect();
		void SetIsIntersect(bool flag);
		bool GetIsIntersect();
		double hpProportion();
		/////////////////////////////////////////////////////////////////////////////
		// �]�wMonster���y�Ъ��禡��												   //
		/////////////////////////////////////////////////////////////////////////////
		void SetXY(int x, int y);					// x, y�y��
		int	GetBorder();
		bool GetCanStandOn();
		void SetMovingDown(bool b);					//�U
		bool GetIsMovingDown();           // �^�ǬO�_���b���W����
		void SetMovingUp(bool b);					//�W
		bool GetIsMovingUp();           // �^�ǬO�_���b���W����
		void SetMovingLeft(bool b);					//��
		bool GetIsMovingLeft();	        // �^�ǬO�_���b��������
		void SetMovingRight(bool b);				//�k
		bool GetIsMovingRight();        // �^�ǬO�_���b���k����
		void SetFacingLR(bool b);				//�k
		bool GetFacingLR();        // �^�ǬO�_���b���k����

		int distanceToCharacter();
		void SetCharacterDirection();	// �]�w����۹�Ǫ�����m(0:����b�Ǫ�����ΤU��)
		bool GetCharacterDirectionLR();	// �^�Ǩ���۹�Ǫ�����m
		bool GetCharacterDirectionTD();	// �^�Ǩ���۹�Ǫ�����m

		bool isAlive();
		bool isAttack();
		void knockBack();

		void SetIsOnTheFloor(bool b);
		bool GetIsOnTheFloor();         // �^�ǬO�_���b�a��

		//��q
		void SetCurrentHp(int x);      // �]�w�ثe��q
		int GetCurrentHp();            // ���o�ثe��q
		void lossCurrentHp(int x);
		void lossHpShow(Map* m);

		//����
		void SetIsAttacking(bool flag);		    // �]�w�O�_����
		bool GetIsAttacking();	        // �^�ǬO�_���b����
		void SetAttackDamage(int x);
		int GetAttackDamage();
		virtual void attackStart();
		virtual void attackJudge(int attackRange);
		void SetIsAttacked(bool flag);	// �]�w�O�_�������
		bool GetIsAttacked();    // �^�ǬO�_�������
		void isAttackedEffectCaculation();
		void isAttackedEffectOnShow(Map* m);

		//�g�ɤ�
		void SetIsViolent(bool flag);	// �]�w�O�_�������
		bool GetIsViolent();    // �^�ǬO�_�������

		//����
		void SetBossDead(bool flag);
		bool GetBossDead();

	protected:
		bool isAttackSuccessfullyL(int range);
		bool isAttackSuccessfullyR(int range);
		void touchSource(Map* m, int sourceCase);
		Character* character;
		int _x, _y;
		int init_x, init_y;
		int currentFloor;
		int hp;
		BloodBar bloodBar;
		int attackDamage;
		bool isIntersect;
		bool hasGottenSource; //�ݯ����O�_�w�Q���o
		int lightBulbInside;
		bool hasGottenLightBulb;
		bool canStandOn;

		Action action;
		int STEP_SIZE;              // ���ʳt��
		int walkLength;
		int BORDER;
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingDown;
		bool isMovingUp;
		bool facingLR;              // ���V ��:0, �k:1
		bool isOnTheFloor;          // �O�_���a��
		bool isAttacking;           // �O�_���b����
		Timer attackCDTime;
		bool attackCD;
		int attackDelayCount;

		Timer isAttackedTimer;
		bool isAttacked;			// �O�_�������
		Timer sparkleEffectTimer;
		bool isSparkleEffectTimerStart;
		bool isSparkleEffectShow;
		CMovingBitmap black;

		int lossHp;
		bool lossHpShowFlag;
		Timer lossHpTimer;
		bool characterDirectionLR;
		bool characterDirectionTD;

		bool isViolent;
		bool haveSetViolent;
		bool bossDead;
	};
}
#endif
