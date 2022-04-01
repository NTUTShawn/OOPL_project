#ifndef __PROPSTROAGE__
#define __PROPSTROAGE__

#include "Util.h"

namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D���x�s�Ŷ�
    /////////////////////////////////////////////////////////////////////////////
    class Prop;
    class PropMosquitoJump;
    class PropShrimpBlood;
    class PropGrassFast;
    class PropBananaAttack;
    class PropShrimpAttack;
    class PropGuavaJuiceBlood;

    class PropStorage
    {
    public:
        PropStorage();
        ~PropStorage();
        void Initialize();
        Prop* getProp(int propCase);
    private:
        PropCase propCase;
        PropMosquitoJump* MosquitoJumpP;
        PropShrimpBlood* ShrimpBloodP;
        PropGrassFast* GrassFastP;
        PropBananaAttack* BananaAttackP;
        PropShrimpAttack* ShrimpAttackP;
        PropGuavaJuiceBlood* GuavaJuiceBloodP;
    };
}
#endif