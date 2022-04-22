#ifndef __CHARACTER__
#define __CHARACTER__

#include "Map.h"
#include "Counter.h"
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���C��������H������
    /////////////////////////////////////////////////////////////////////////////
    class Source;
    class SourceStorage;
    class Prop;
    class PropStorage;
    
    class Character {
    public:
        Character();
        ~Character();
        Map* GetMap();				    // �a��
        void Initialize();				// �]�w��l��
        void LoadBitmap();				// ���J�ϧ�
        void OnMove(Map *m);		    // ����
        void OnShow();			        // �N�ϧζK��e��
        void BloodShow();

        int  GetLeftX();				// ���W�� x �y��
        int  GetTopY();					// ���W�� y �y��
        int  GetRightX();				// �k�U�� x �y��
        int  GetButtonY();				// �k�U�� y �y��
        void GetMovingDown();	        // �^�ǬO�_���b���U����
        bool GetIsMovingLeft();	        // �^�ǬO�_���b��������
        bool GetIsMovingRight();        // �^�ǬO�_���b���k����
        bool GetIsMovingUp();           // �^�ǬO�_���b���W����
        bool GetIsRolling();            // �^�ǬO�_���b½�u
        bool GetIsOnTheFloor();         // �^�ǬO�_���b�a��
        bool GetIsRising();	            // �^�ǬO�_���b�W��
        bool GetIsAttacking();	        // �^�ǬO�_���b����
        bool GetIsAttackedFromRight();    // �^�ǧ����O�_�Ӧۥk��
        bool GetIsAttackedFromLeft();	    // �^�ǧ����O�_�Ӧۥ���
        bool GetIsAttackedFromButton();	// �^�ǧ����O�_�ӦۤU��
        int GetMaxHp();                // ���o�̤j��q
        int GetCurrentHp();            // ���o�ثe��q
        int GetAtk();                  // ���o�����O

        void SetMap(Map *m);
        void SetMovingDown(bool flag);	        // �]�w�O�_���b���U����
        void SetMovingLeft(bool flag);	        // �]�w�O�_���b��������
        void SetMovingRight(bool flag);         // �]�w�O�_���b���k����
        void SetFacingDirection(int mouseX);    // �]�w�����V
        void SetMovingUp(bool flag);	        // �]�w�O�_���b���W����
        void SetRolling(bool flag);	            // �]�w�O�_½�u
        void SetXY(int x, int y);		        // �]�w���W���y��
        void SetAttacking(bool flag);		    // �]�w�O�_����
        void SetIsAttackedFromRight(bool flag);	// �]�w�����O�_�Ӧۥk��
        void SetIsAttackedFromLeft(bool flag);	// �]�w�����O�_�Ӧۥ���
        void SetIsAttackedFromButton(bool flag);	// �]�w�����O�_�ӦۤU��
        void SetCurrentHp(int x);               // �]�w�ثe��q
        void SetAtk(int x);                     // �]�w�����O

        void Rolling(Map *m, bool flag);        // ½�u�ʧ@
        void addAtk(int ATK);                   // ���ɧ����O
        void restoreCurrentHp();                // ��_�ثe��q
        void lossCurrentHp(int n);              // �l��
        void Attack(bool flag);

        /*�\�I��O*/
        SourceStorage* GetSourceStorage();	        // �^�ǯ����x�s�Ŷ�
        PropStorage* GetPropStorage();	            // �^�ǹD���x�s�Ŷ�
        void EatMosquitoJump(bool flag);        // �Y�U�G�q����O
        bool CanDoubleJump();                   // �^�ǬO�_�i�H�G�q��
        void SetDoubleJump(bool flag);          // �]�w�O�_�i�H�G�q��
        void EatGrassFast(bool flag);           // �Y�U���ʳt�״��ɯ�O
        void IncreaseSpeed(double m);           // ���ɲ��ʳt��(���v)
        void EatShrimpBlood(bool flag);         // �Y�U��q���ɯ�O
        void addMaxHp(int blood);               // ���ɦ�q�W��
        void EatGuavaJuiceBlood(bool flag);     // �Y�U�C�Q��^�T�w���O
        void healBloodEveryTenSeconds();        // �C�Q��^�T�w��
        
        

    protected:
        CMovingBitmap standLeft;	    // ���߭��V��
        CMovingBitmap standRight;	    // ���߭��V�k
        CMovingBitmap bloodFrame;	    // �����q��
        CMovingBitmap characterBlood[10];   // �����q
        CAnimation walkingLeft;         // �V���樫�ʵe
        CAnimation walkingRight;        // �V�k�樫�ʵe
        CAnimation leftJump;            // �����ʵe
        CAnimation rightJump;           // �k���ʵe
        CAnimation leftRolling;         // ���u�ʵe
        CAnimation rightRolling;        // �k�u�ʵe
        CAnimation leftAttacking;       // �V�������ʵe
        CAnimation rightAttacking;      // �V�k�����ʵe
        //CAnimation animation;           // for test
        Map* currentMap;

		int characterX, characterY;
		int characterW, characterH;
        int STEP_SIZE;              // ���ʳt��
		bool isMovingDown;		    // �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isRolling;             // �O�_���b½�u
		bool facingLR;              // ���V ��:0, �k:1
		bool isOnTheFloor;          // �O�_���a��
		bool isRising;              // �O�_���b�W��
		bool isAttacking;           // �O�_���b����
		bool isAttackedFromRight;
		bool isAttackedFromLeft;
		bool isAttackedFromButton;
		int  velocity;
		int  rolling_time;

        Counter healBloodTime;

        int currentHp;
        int maxHp;
        int atk;
		bool doubleJump;
		bool DJtemp;
		bool healBlood;

		SourceStorage* sourceStorage;
		PropStorage* propStorage;
	};
}

#endif