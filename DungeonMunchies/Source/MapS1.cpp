#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "MapS1.h"
#include <vector>

namespace game_framework
{
    /////////////////////////////////////////////////////////////////////////////
// �o��class���Ѧa�Ϻc��
/////////////////////////////////////////////////////////////////////////////

    MapS1::MapS1() : Map(0, 0) //�a�ϳ]�m�G0�����ਫ�B1���i�H���B2���ǰe��(transGate)
    {
        X = 0;
        Y = 0;
        gridW = 40;
        gridH = 40;
        setFloor(560);
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
            for (int j = 5; j < 15; j++)
            {
                mapGrid_init[i][j] = 1;
            }
        }

        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 18; j++)
            {
                mapGrid[i][j] = mapGrid_init[i][j]; //�̧Ƕ�JmapGrid
            }
        }
    }

    MapS1::~MapS1()
    {
    }

    void MapS1::Initialize()
    {
        setXY(0, 0);
    }

    void MapS1::setPos(int x, int y, int n)
    {
        int gridX = x / 40;
        int gridY = y / 40;
        mapGrid[gridX][gridY] = n;
    }

    bool MapS1::isEmpty(int x, int y) const
    {
        int gridX = x / 40;
        int gridY = y / 40;
        if (mapGrid[gridX][gridY] != 0)
        {
            return true;
        }
        return false;
    }

    void MapS1::LoadBitmap()
    {
        //white.LoadBitmap(IDB_WHITE);
        //blue.LoadBitmap(IDB_BLUE);
        map.LoadBitmap(".\\res\\map01.bmp");
    }

    void MapS1::onShow()
    {
        map.SetTopLeft(getSX(), getSY() + 20);
        map.ShowBitmap();
        for (int i = 0; i < 18; i++)
        { //���k��ܤ��i��
            for (int j = 0; j < 40; j++)
            { //���U��ܥ|�i��
                switch (mapGrid[j][i])
                {
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

    void MapS1::setCharacterX(int x)
    {
        characterX = x;
    }
    void MapS1::setCharacterY(int y)
    {
        characterY = y;
    }
    int MapS1::screenX(int x)
    {
        return x + getSX();
    }
    int MapS1::screenY(int y)
    {
        return y + getSY();
    }
}