namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���C��������H������
    /////////////////////////////////////////////////////////////////////////////
    class Character {
    public:
        Character();
        void LoadBitmap();
        void onMove();
        void onShow();
        //protected:
        //    void OnShow();                                    // ��ܳo�Ӫ��A���C���e��
    private:
        CMovingBitmap character;
        int x, y;
    };
}