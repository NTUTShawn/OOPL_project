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
        gridW = 40;
        gridH = 40;
        setFloor(600);
        setMonsterFloor(560);
        int mapGrid_init[40][18];
        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 18; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
       //�����a�ϥ��W���y�ФΨC�i�p�ϼe��
        for (int i = 2; i < 30; i++)
        {
            for (int j = 5; j < 16; j++)
            {
                mapGrid_init[i][j] = 1;
            }
        }
        
        for (int i = 0; i < 40; i++) {
            for (int j = 0; j < 18; j++) {
                mapGrid[i][j] = mapGrid_init[i][j]; //�̧Ƕ�JmapGrid
            }
        }
    }

    MapForBoss::~MapForBoss()
    {
    }

    void MapForBoss::LoadBitmap() {
        //white.LoadBitmap(IDB_WHITE);
        //blue.LoadBitmap(IDB_BLUE);
        map.LoadBitmap(".\\res\\boss_map.bmp");
    }

    void MapForBoss::Initialize()
    {
        setXY(0, 0);
        setInitialXY(0, 0);
        setScreenMoving(false);
        setMapName("MapForBoss");
        setStartPosition(80);
    }

    void MapForBoss::setPos(int x, int y, int n)
    {
        int gridX = x / 40;
        int gridY = y / 40;
        mapGrid[gridX][gridY] = n;
    }

    bool MapForBoss::isEmpty(int x, int y) const
    {
        int gridX = x / 40;
        int gridY = y / 40;
        if (mapGrid[gridX][gridY] != 0)
        {
            return true;
        }
        return false;
    }

    bool MapForBoss::isPortal(int x, int y) const
    {
        int gridX = x / 40;
        int gridY = y / 40;
        if (mapGrid[gridX][gridY] == 2)
        {
            return true;
        }
        return false;
    }

    bool MapForBoss::isBridge(int x, int y) const
    {
        int gridX = x / 40;
        int gridY = y / 40;
        if (mapGrid[gridX][gridY] == 3)
        {
            return true;
        }
        return false;
    }

    bool MapForBoss::isCraftTable(int x, int y) const
    {
        return false;
    }

    bool MapForBoss::isTrashCan(int x, int y) const
    {
        return false;
    }

    bool MapForBoss::isGetHurtPlace(int x, int y) const
    {
        return false;
    }

    void MapForBoss::onShow() {
        map.SetTopLeft(getSX(), getSY()+20);
        map.ShowBitmap();
        for (int i = 0; i < 18; i++) { //���k��ܤ��i��
            for (int j = 0; j < 40; j++) { //���U��ܥ|�i��
                switch (mapGrid[j][i]) {
                case 0:
                    //blue.SetTopLeft(X + (gridW * j), Y + (gridH * i)); //�]�w�C�i�Ϫ��y��
                    //blue.ShowBitmap(); // ��ܳ]�w�����y��
                    break;
                case 1:
                    //white.SetTopLeft(X + (gridW * j), Y + (gridH * i)); //�]�w�C�i�Ϫ��y��
                    //white.ShowBitmap(); //��ܳ]�w�����y��
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

    void MapForBoss::monsterFloorChanging(int x)
    {
        setMonsterFloor(600);
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