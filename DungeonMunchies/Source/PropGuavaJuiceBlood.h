#ifndef __PROPGUAVAJUICEBLOOD__
#define __PROPGUAVAJUICEBLOOD__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��GuavaJuiceBlood
    /////////////////////////////////////////////////////////////////////////////
    class Character;

    class PropGuavaJuiceBlood : public Prop {
    public:
        PropGuavaJuiceBlood();
        ~PropGuavaJuiceBlood();
        void Initialize();
        void effect(Character* character, bool flag) override;
    private:

    };
}
#endif
