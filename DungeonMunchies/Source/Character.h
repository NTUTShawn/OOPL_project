namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���C��������H������
    /////////////////////////////////////////////////////////////////////////////
    class Character {
    public:
        Character();
        int  GetX1();					// ���W�� x �y��
        int  GetY1();					// ���W�� y �y��
        int  GetX2();					// �k�U�� x �y��
        int  GetY2();					// �k�U�� y �y��
        void Initialize();				// �]�w��l��
        void LoadBitmap();				// ���J�ϧ�
        void OnMove();					// ����
        void OnShow();					// �N�ϧζK��e��
        void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
        void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
        void SetMovingRight(bool flag); // �]�w�O�_���b���k����
        void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
        void SetXY(int nx, int ny);		// �]�w���W���y��
    protected:
        CAnimation animation;
        int x, y;
        bool isMovingDown;			// �O�_���b���U����
        bool isMovingLeft;			// �O�_���b��������
        bool isMovingRight;			// �O�_���b���k����
        bool isMovingUp;			// �O�_���b���W����
    };
}