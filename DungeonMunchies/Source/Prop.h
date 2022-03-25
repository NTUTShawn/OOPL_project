#ifndef __Prop__
#define __Prop__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // 這個class為道具
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