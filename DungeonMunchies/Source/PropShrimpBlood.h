#ifndef __PROPSHRIMPBLOOD__
#define __PROPSHRIMPBLOOD__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��ShrimpBlood
    /////////////////////////////////////////////////////////////////////////////
    class Character;

    class PropShrimpBlood : public Prop {
    public:
        PropShrimpBlood();
        ~PropShrimpBlood();
        void Initialize();
        void effect(Character* character, bool flag) override;
    private:

    };
}
#endif