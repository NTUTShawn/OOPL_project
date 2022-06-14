#ifndef __CHARACTER__
#define __CHARACTER__

#include "Map.h"
#include "Timer.h"
#include "Util.h"
namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C��������H������
	/////////////////////////////////////////////////////////////////////////////
	class Source;
	class SourceStorage;
	class Prop;
	class PropStorage;
	class Monster;

	class Character
	{
	public:
		Character();
		~Character();
		Map* GetMap();				    // �a��
		void Initialize();				// �]�w��l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove(Map* m, vector<Monster*>* monsters);		    // ����
		void OnShow(Map* m);			        // �N�ϧζK��e��
		void ResetPosition(Map* m);			// �a�Ϥ����ɡA���m��m
		void showData();
		void BloodShow();
		void ScreenCXY(Map* m);

		/*map*/
		void shouldShowMagnifier(Map* m);
		void shouldShowMessageIconFlag(Map* m);
		void SetMapCanShowMessage(Map* m);
		void SetMapAutoShowMessage(Map* m);

		int  GetLeftX();				// ���W�� x �y��
		int  GetTopY();					// ���W�� y �y��
		int  GetRightX();				// �k�U�� x �y��
		int  GetBottomY();				// �k�U�� y �y��
		int  GetCharacterStage();				

		void GetMovingDown();	        // �^�ǬO�_���b���U����
		bool GetIsMovingLeft();	        // �^�ǬO�_���b��������
		bool GetIsMovingRight();        // �^�ǬO�_���b���k����
		bool GetIsMovingUp();           // �^�ǬO�_���b���W����
		bool GetIsOnTheFloor();         // �^�ǬO�_���b�a��
		bool GetIsRising();	            // �^�ǬO�_���b�W��
		bool GetCanGoToNextMap();		// �^�ǬO�_�i�H�e���U�@��
		bool GetCanCraft();				// �^�ǬO�_��X��

		int GetMaxHp();                // ���o�̤j��q
		int GetCurrentHp();            // ���o�ثe��q
		bool GetIsInvincible();         //�^�ǬO�_���L�Ī��A

		void SetMap(Map* m);
		void SetMovingDown();					// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	        // �]�w�O�_���b��������
		void SetMovingRight(bool flag);         // �]�w�O�_���b���k����
		void SetFacingDirection(int mouseX);    // �]�w�����V
		void SetMovingUp(bool flag);	        // �]�w�O�_���b���W����
		void SetXY(int x, int y);		        // �]�w���W���y��
		void SetCanGoToNextMap(bool flag);		// �]�w�O�_��e���U�@��
		void SetCanCraft(bool flag);			// �]�w�O�_��X��


		void SetCurrentHp(int x);               // �]�w�ثe��q
		void SetIsInvincible(bool flag);         //�]�w�O�_���L�Ī��A

		void restoreCurrentHp(int n);           // ��_�ثe��q
		void lossCurrentHp(int n);              // �l��
		void hpLimit();

		bool isIntersect(int lX, int rX, int tY, int bY); //�ݪ���O�_�M���⭫�|

		void characterHasSword(bool flag);

		/*�欰*/
		//�P�w�O�_�i�H���k����
		bool CanMovingLeft(Map* m, vector<Monster*>* monsters);
		bool CanMovingRight(Map* m, vector<Monster*>* monsters);

		//�t��
		void SetSpeed(int x);
		int GetSpeed();
		//½�u
		void SetRolling(bool flag);	            // �]�w�O�_½�u
		bool GetIsRolling();            // �^�ǬO�_���b½�u
		void Rolling(Map* m, bool flag, vector<Monster*>* monsters);        // ½�u�ʧ@
		//����
		void SetAttacking(bool flag);		    // �]�w�O�_����
		bool GetIsAttacking();	        // �^�ǬO�_���b����
		void SetAttackDamage(int x);                     // �]�w�����O
		int GetAttackDamage();                  // ���o�����O
		void addAttackDamage(int x);                   // ���ɧ����O
		void SetAttackRange(int x);
		int GetAttackRange();
		void attack(vector<Monster*>* monsters);
		void attackOnMove();
		//�������
		void SetIsAttackedFromRight(bool flag);	// �]�w�����O�_�Ӧۥk��
		bool GetIsAttackedFromRight();    // �^�ǧ����O�_�Ӧۥk��
		void SetIsAttackedFromLeft(bool flag);	// �]�w�����O�_�Ӧۥ���
		bool GetIsAttackedFromLeft();	    // �^�ǧ����O�_�Ӧۥ���
		void SetIsAttackedFromBottom(bool flag);	// �]�w�����O�_�ӦۤU��
		bool GetIsAttackedFromBottom();	// �^�ǧ����O�_�ӦۤU��
		void isAttackedEffectCaculation();
		void isAttackedEffectOnShow();


		/*�\�I��O*/
		SourceStorage* GetSourceStorage();	        // �^�ǯ����x�s�Ŷ�
		PropStorage* GetPropStorage();	            // �^�ǹD���x�s�Ŷ�
		void EatMosquitoJump(bool flag);        // �Y�U�G�q����O
		bool CanDoubleJump();                   // �^�ǬO�_�i�H�G�q��
		void SetDoubleJump(bool flag);          // �]�w�O�_�i�H�G�q��
		void EatGrassFast(bool flag);           // �Y�U���ʳt�״��ɯ�O
		void ChangeSpeed(double m);           // ���ɲ��ʳt��(���v)
		void EatShrimpBlood(bool flag);         // �Y�U��q���ɯ�O
		void addMaxHp(int blood);               // ���ɦ�q�W��
		void EatGuavaJuiceBlood(bool flag);     // �Y�U�C�Q��^�T�w���O
		void healBloodEveryTenSeconds();        // �C�Q��^�T�w��
		void EatBananaAttack(bool flag);
		void EatShrimpAttack(bool flag);

		void SetIsMosquitoJump(bool flag);
		bool GetIsMosquitoJump();
		void SetIsGrassFast(bool flag);
		bool GetIsGrassFast();
		void SetIsShrimpBlood(bool flag);
		bool GetIsShrimpBlood();
		void SetIsGuavaJuiceBlood(bool flag);
		bool GetIsGuavaJuiceBlood();
		void SetIsBananaAttack(bool flag);
		bool GetIsBananaAttack();
		void SetIsShrimpAttack(bool flag);
		bool GetIsShrimpAttack();
		void SetLightBulbNum(int num);
		int GetLightBulbNum();
		void AddLightBulb(int num);
		void ConsumeLightBulb(int num);
		void SetAllSourceNumToHundred();

	protected:
		bool isAttackSuccessfullyL(int range, Monster* monster);
		bool isAttackSuccessfullyR(int range, Monster* monster);
		CMovingBitmap bloodFrame;	    // �����q��
		CMovingBitmap characterBlood[10];   // �����q
		CAnimation leftRolling;         // ���u�ʵe
		CAnimation rightRolling;        // �k�u�ʵe
		CMovingBitmap standLeft[2];
		CMovingBitmap standRight[2];
		CAnimation walkingLeft[2];
		CAnimation walkingRight[2];
		CAnimation leftJump[2];
		CAnimation rightJump[2];
		CAnimation leftAttacking[2];
		CAnimation rightAttacking[2];

		Map* currentMap;

		int characterX, characterY;
		int screenCX, screenCY;
		int characterW, characterH;
		bool mapScreenCanMoving;
		bool canGoToNextMap;
		bool canCraft;
		int STEP_SIZE;              // ���ʳt��
		int BORDER;
		int monsterTop;
		bool isMovingDown;		    // �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isRolling;             // �O�_���b½�u
		Timer rollingTimer;
		bool facingLR;              // ���V ��:0, �k:1
		bool isOnTheFloor;          // �O�_���a��
		bool isRising;              // �O�_���b�W��
		bool isAttacking;           // �O�_���b����
		int attackRange;
		bool isAttackedFromRight;
		bool isAttackedFromLeft;
		bool isAttackedFromBottom;
		Timer isAttackedTimer;
		bool isAttacked;			// �O�_�������
		Timer sparkleEffectTimer;
		bool isSparkleEffectTimerStart;
		bool isSparkleEffectShow;
		CMovingBitmap black;

		int  velocity;
		int  rolling_time;
		Action action;

		Timer healBloodTimer;
		bool healBlood;

		Timer invincibleTimer;
		bool isInvincible;

		int currentHp;
		int maxHp;
		int attackDamage;
		bool doubleJump;
		bool DJtemp;

		/*�\�I*/
		bool isMosquitoJump;
		bool isGrassFast;
		bool isShrimpBlood;
		bool isGuavaJuiceBlood;
		bool isBananaAttack;
		Timer ShrimpAttackTimer;
		bool shrimpAttack;
		bool isShrimpAttack;

		int characterStage;

		int lightBulbNum;

		SourceStorage* sourceStorage;
		PropStorage* propStorage;
	};
}

#endif