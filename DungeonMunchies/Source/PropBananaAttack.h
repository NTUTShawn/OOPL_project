#ifndef __PROPBANANAATTACK__
#define __PROPBANANAATTACK__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��BananaAttack
    /////////////////////////////////////////////////////////////////////////////
    class Character;

    class PropBananaAttack : public Prop {
    public:
        PropBananaAttack();
        ~PropBananaAttack();
        void Initialize();
        void effect(Character* character) override;
    private:

    };
}
#endif
