#ifndef __PROPGRASSFAST__
#define __PROPGRASSFAST__
namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��GrassFast
    /////////////////////////////////////////////////////////////////////////////
    class Character;

    class PropGrassFast : public Prop {
    public:
        PropGrassFast();
        ~PropGrassFast();
        void Initialize();
        void effect(Character* character) override;
    private:

    };
}
#endif
