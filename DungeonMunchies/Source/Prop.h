#ifndef __Prop__
#define __Prop__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��
    /////////////////////////////////////////////////////////////////////////////
    class Prop
    {
    public:
        Prop();
        void Initialize();
        void getProp();
        bool havingProp();
        void LoadBitmap(int code);
        void onShow();
    private:
        bool prop;
        CMovingBitmap propDetails;
    };
}
#endif