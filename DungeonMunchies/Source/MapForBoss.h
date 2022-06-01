namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���Ѧa�Ϻc��
    /////////////////////////////////////////////////////////////////////////////
    class MapForBoss : public Map {
    public:
        MapForBoss();
        ~MapForBoss();
        void LoadBitmap();
        void Initialize();
        void setPos(int x, int y, int n);			//�N�a�Ϯy�Ъ��}�C�]���ǤJ���Ʀr
        bool isEmpty(int x, int y) const;
        bool isPortal(int x, int y) const;
        bool isBridge(int x, int y) const;
        bool isCraftTable(int x, int y) const;
        void onShow();
        void setCharacterX(int x) override;
        void setCharacterY(int y) override;
        void monsterFloorChanging(int x);
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