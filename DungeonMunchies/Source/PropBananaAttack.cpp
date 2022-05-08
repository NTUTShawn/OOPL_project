#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character.h"
#include "Prop.h"
#include "PropBananaAttack.h"
#include <vector>

namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
    // �o��class���D��BananaAttack
    /////////////////////////////////////////////////////////////////////////////

    PropBananaAttack::PropBananaAttack() : Prop()
    {
    }

    PropBananaAttack::~PropBananaAttack()
    {
    }

    void PropBananaAttack::Initialize()
    {
    }

    void PropBananaAttack::effect(Character* character)
    {
        character->EatBananaAttack(true);
    }
}