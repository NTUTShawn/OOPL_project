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
        void setPropFlag(bool flag);
        bool getPropFlag();
        void LoadBitmap(int code);
        void onShow();
    private:
        bool propFlag;
        CMovingBitmap propDetails;
    };
}
#endif