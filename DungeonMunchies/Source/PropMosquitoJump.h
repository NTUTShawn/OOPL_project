namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���Ѧa�Ϻc��
    /////////////////////////////////////////////////////////////////////////////
    class Character;

    class PropMosquitoJump : public Prop {
    public:
        PropMosquitoJump();
        ~PropMosquitoJump();
        void Initialize();
        void effect(Character* character) override;
    private:
    
    };
}