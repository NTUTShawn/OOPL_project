namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���Ѧa�Ϻc��
    /////////////////////////////////////////////////////////////////////////////
    class MapForBoss : public Map {
    public:
        MapForBoss();
        ~MapForBoss();
        void Initialize();
        void setPos(int x, int y, int n);			//�N�a�Ϯy�Ъ��}�C�]���ǤJ���Ʀr
        bool isEmpty(int x, int y) const;
        void LoadBitmap();
        void onShow();
        void setCharacterX(int x) override;
        void setCharacterY(int y) override;
        int screenX(int x) override;
        int screenY(int y) override;
    protected:
        CMovingBitmap map;
        int X, Y;
        int mapGrid[40][18];
        CMovingBitmap white, blue;
        int gridW, gridH;
        int characterX, characterY; 
    };
}