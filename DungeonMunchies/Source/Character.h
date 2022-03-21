#ifndef CHARACTER_H
#define CHARACTER_H

#include "Map.h"
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���C��������H������
    /////////////////////////////////////////////////////////////////////////////
    class Character {
    public:
        Character();
        void Initialize();				// �]�w��l��
        void LoadBitmap();				// ���J�ϧ�
        void OnMove(Map *m);		    // ����
        void OnShow();					// �N�ϧζK��e��
        int  GetLeftX();				// ���W�� x �y��
        int  GetTopY();					// ���W�� y �y��
        int  GetRightX();				// �k�U�� x �y��
        int  GetButtonY();				// �k�U�� y �y��
        void GetMovingDown(bool flag);	// �^�ǬO�_���b���U����
        bool GetIsMovingLeft();	        // �^�ǬO�_���b��������
        bool GetIsMovingRight();        // �^�ǬO�_���b���k����
        bool GetIsMovingUp();           // �^�ǬO�_���b���W����
        bool GetIsRolling();            // �^�ǬO�_���b½�u
        bool GetIsOnTheFloor();         // �^�ǬO�_���b�a��
        bool GetIsRising();	            // �^�ǬO�_���b�W��

        void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
        void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
        void SetMovingRight(bool flag); // �]�w�O�_���b���k����
        void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
        void SetRolling(bool flag);	    // �]�w�O�_½�u
        void SetXY(int x, int y);		// �]�w���W���y��

    protected:
        CMovingBitmap standLeft;	   // ���߭��V��
        CMovingBitmap standRight;	   // ���߭��V�k
        CAnimation walkingLeft;
        CAnimation walkingRight;
        CAnimation leftJump;
        CAnimation rightJump;
        CAnimation leftRolling;
        CAnimation rightRolling;

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
        int  velocity;
        int  floor;
    };
}

#endif