#ifndef __PROPMOSQUITOJUMP__
#define __PROPMOSQUITOJUMP__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��MosquitoJump
    /////////////////////////////////////////////////////////////////////////////
    class Character;

    class PropMosquitoJump : public Prop {
    public:
        PropMosquitoJump();
        ~PropMosquitoJump();
        void Initialize();
        void effect(Character* character, bool flag) override;
    private:
    };
}
#endif