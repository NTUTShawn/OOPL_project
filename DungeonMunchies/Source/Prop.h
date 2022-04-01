#ifndef __PROP__
#define __PROP__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��
    /////////////////////////////////////////////////////////////////////////////
    class Character;

    class Prop
    {
    public:
        Prop();
        void LoadBitmap(int code);
        void Initialize();
        void setPropFlag(bool flag);
        bool getPropFlag();
        virtual void effect(Character* character);
        void onShow();
    private:
        bool propFlag;
        CMovingBitmap propDetails;
    };
}
#endif