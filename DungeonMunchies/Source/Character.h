#ifndef __CHARACTER__
#define __CHARACTER__

#include "Map.h"
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
        void Initialize();				// �]�w��l��
        void LoadBitmap();				// ���J�ϧ�
        void OnMove(Map *m);		    // ����
        void OnShow();					// �N�ϧζK��e��
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
        SourceStorage* GetSourceStorage();	        // �^�ǯ����x�s�Ŷ�
        PropStorage* GetPropStorage();	        // �^�ǹD���x�s�Ŷ�

        void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
        void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
        void SetMovingRight(bool flag); // �]�w�O�_���b���k����
        void SetFacingDirection(int mouseX); // �]�w�����V
        void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
        void SetRolling(bool flag);	    // �]�w�O�_½�u
        void SetXY(int x, int y);		// �]�w���W���y��
        void SetAttacking(bool flag);		// �]�w�O�_����
        void Rolling(Map *m, bool flag);    // ½�u�ʧ@
        void Attack(bool flag);

    protected:
        CMovingBitmap standLeft;	    // ���߭��V��
        CMovingBitmap standRight;	    // ���߭��V�k
        CAnimation walkingLeft;         // �V���樫�ʵe
        CAnimation walkingRight;        // �V�k�樫�ʵe
        CAnimation leftJump;            // �����ʵe
        CAnimation rightJump;           // �k���ʵe
        CAnimation leftRolling;         // ���u�ʵe
        CAnimation rightRolling;        // �k�u�ʵe
        CAnimation leftAttacking;        // �V�������ʵe
        CAnimation rightAttacking;       // �V�k�����ʵe

        int characterX, characterY;
        int characterW, characterH;
        bool isMovingDown;		    // �O�_���b���U����
        bool isMovingLeft;			// �O�_���b��������
        bool isMovingRight;			// �O�_���b���k����
        bool isMovingUp;			// �O�_���b���W����
        bool isRolling;             // �O�_���b½�u
        bool facingLR;              // ���V ��:0, �k:1
        bool isOnTheFloor;          // �O�_���a��
        bool isRising;              // �O�_���b�W��
        bool isAttacking;           // �O�_���b����
        int  velocity;
        int  floor;
        int  rolling_time;

        SourceStorage* sourceStorage;
        PropStorage* propStorage;
    };
}

#endif