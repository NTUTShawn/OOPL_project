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
        void OnMove(Map *m);					// ����
        void OnShow();					// �N�ϧζK��e��
        int  GetLeftX();					// ���W�� x �y��
        int  GetTopY();					// ���W�� y �y��
        int  GetRightX();					// �k�U�� x �y��
        int  GetButtonY();					// �k�U�� y �y��
        void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
        void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
        void SetMovingRight(bool flag); // �]�w�O�_���b���k����
        void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
        void SetXY(int x, int y);		// �]�w���W���y��
    protected:
        CAnimation animation;
        int characterX, characterY;
        int characterW, characterH;
        bool isMovingDown;			// �O�_���b���U����
        bool isMovingLeft;			// �O�_���b��������
        bool isMovingRight;			// �O�_���b���k����
        bool isMovingUp;			// �O�_���b���W����
        bool isRising;
        int  velocity;
        int  floor;
    };
}