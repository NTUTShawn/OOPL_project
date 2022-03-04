#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character.h"

/////////////////////////////////////////////////////////////////////////////
// �o��class���C��������H������
/////////////////////////////////////////////////////////////////////////////
namespace game_framework {
    Character::Character() {
        x = y = 50;
    }

    void Character::onMove() {
        if (y <= SIZE_Y) {
            x += 3;
            y += 3;
        }
        else {
            x = y = 50;
        }
    }

    void Character::LoadBitmap() {
        character.LoadBitmap(IDB_MONSTER);
    }

    void Character::onShow() {
        character.SetTopLeft(x, y);
        character.ShowBitmap();
    }
}