#ifndef __PROPSHRIMPATTACK__
#define __PROPSHRIMPATTACK__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��ShrimpAttack
    /////////////////////////////////////////////////////////////////////////////
    class Character;

    class PropShrimpAttack : public Prop {
    public:
        PropShrimpAttack();
        ~PropShrimpAttack();
        void Initialize();
        void effect(Character* character) override;
    private:

    };
}
#endif
