#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "MapForBoss.h"
#include <vector>

namespace game_framework {
    /////////////////////////////////////////////////////////////////////////////
// �o��class���Ѧa�Ϻc��
/////////////////////////////////////////////////////////////////////////////

    MapForBoss::MapForBoss(): Map(0, 0) //�a�ϳ]�m�G0�����ਫ�B1���i�H���B2���ǰe��(transGate)
    {
        X = 0;
        Y = 0;
        gridW = 60;
        gridH = 60;
       //�����a�ϥ��W���y�ФΨC�i�p�ϼe��
        int mapGrid_init[4][6] = { //�����a�ϰ}�C���
            {0,0,0,0,0,0},
            {0,1,1,1,1,0},
            {0,1,1,1,1,0},
            {0,0,0,0,0,0},
        };
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                mapGrid[i][j] = mapGrid_init[i][j]; //�̧Ƕ�JmapGrid
            }
        }
    }

    MapForBoss::~MapForBoss()
    {
    }

    void MapForBoss::Initialize()
    {
        setXY(0, 0);
    }

    void MapForBoss::setPos(int x, int y, int n)
    {
        int gridX = x / 60;
        int gridY = y / 60;
        mapGrid[gridX][gridY] = n;
    }

    bool MapForBoss::isEmpty(int x, int y) const
    {
        int gridX = x / 60;
        int gridY = y / 60;
        if (mapGrid[gridX][gridY] != 0)
        {
            return true;
        }
        return false;
    }

    void MapForBoss::LoadBitmap() {
        white.LoadBitmap(IDB_WHITE);
        blue.LoadBitmap(IDB_BLUE);
        map.LoadBitmap(IDB_BOSSMAP);
    }

    void MapForBoss::onShow() {
        map.SetTopLeft(getSX(), getSY());
        map.ShowBitmap();
        for (int i = 0; i < 6; i++) { //���k��ܤ��i��
            for (int j = 0; j < 4; j++) { //���U��ܥ|�i��
                switch (mapGrid[j][i]) {
                case 0:
                    blue.SetTopLeft(X + (gridW * j), Y + (gridH * i)); //�]�w�C�i�Ϫ��y��
                    blue.ShowBitmap(); // ��ܳ]�w�����y��
                    break;
                case 1:
                    white.SetTopLeft(X + (gridW * j), Y + (gridH * i)); //�]�w�C�i�Ϫ��y��
                    white.ShowBitmap(); //��ܳ]�w�����y��
                    break;
                case 2:
                    //blue.SetTopLeft(X + (gridW * i), Y + (gridH * j)); //�]�w�C�i�Ϫ��y��
                    //blue.ShowBitmap(); // ��ܳ]�w�����y��
                    break;
                default:
                    ASSERT(0); //mapGrid�}�C���ӥX�{0,1,2���~����
                }
            }
        }
    }

    void MapForBoss::getCharacterX(int x)
    {
        characterX = x;
    }
    void MapForBoss::getCharacterY(int y)
    {
        characterY = y;
    }
    int MapForBoss::screenX(int x)
    {
        return x + getSX();
    }
    int MapForBoss::screenY(int y)
    {
        return y + getSY();
    }
}