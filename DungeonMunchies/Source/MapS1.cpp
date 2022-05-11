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
        X = 40;
        Y = 40;
        gridW = 40;
        gridH = 40;
        setFloor(640);
        int mapGrid_init[100][18];
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 18; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        //�����a�ϥ��W���y�ФΨC�i�p�ϼe��
        for (int i = 2; i < 45; i++)
        {
            for (int j = 1; j < 16; j++)
            {
                mapGrid_init[i][j] = 1;
            }
        }

        for (int i = 45; i < 60; i++)
        {
            for (int j = 1; j < 15; j++)
            {
                mapGrid_init[i][j] = 1;
            }
        }

        for (int i = 60; i < 71; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                mapGrid_init[i][j] = 1;
            }
        }

        for (int j = 1; j < 9; j++) {
            mapGrid_init[52][j] = 0;
        }

        for (int i = 60; i < 65; i++)
        {
            for (int j = 5; j < 11; j++)
            {
                mapGrid_init[i][j] = 2;
            }
        }

        for (int i = 0; i < 100; i++)
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

	void MapS1::LoadBitmap()
	{
		//white.LoadBitmap(IDB_WHITE);
		//blue.LoadBitmap(IDB_BLUE);
		map.LoadBitmap(".\\res\\map01.bmp");
        exitBitmap.LoadBitmap(IDB_EXIT, RGB(0, 0, 0));
        pressEBitmap.LoadBitmap(IDB_PRESSE, RGB(0, 0, 0));
	}

    void MapS1::Initialize()
    {
        setXY(-410, -320);
        setScreenMoving(true);
        setMapName("MapS1");
        setStartPosition(335);
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

    bool MapS1::isPortal(int x, int y) const
    {
        int gridX = x / 40;
        int gridY = y / 40;
        if (mapGrid[gridX][gridY] == 2)
        {
            return true;
        }
        return false;
    }

    void MapS1::onShow()
    {
        map.SetTopLeft(getSX(), getSY());
        map.ShowBitmap();

        if (getPortalOpen())
        {
            exitBitmap.SetTopLeft(2895+getSX(), 180);
            exitBitmap.ShowBitmap();
            pressEBitmap.SetTopLeft(600, 620);
            pressEBitmap.ShowBitmap();
        }

        if (getSX() > -1520)
        {
            setFloor(640);
        }
        else if (getSX() > -2060)
        {
            setFloor(560);
        }
        else
        {
            setFloor(420);
        }

        if (getSX() > -425)
        {
            setCeiling(0);
        }
        else if (getSX() > -1865) 
        {
            setCeiling(420);
        }
        else
        {
            setCeiling(0);
        }

        for (int i = 0; i < 18; i++)
        { //���k��ܤ��i��
            for (int j = 0; j < 100; j++)
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