#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "MapS2.h"
#include <vector>

namespace game_framework
{
    /////////////////////////////////////////////////////////////////////////////
// 這個class提供地圖構成
/////////////////////////////////////////////////////////////////////////////

    MapS2::MapS2() : Map(0, 0) //地圖設置：0為不能走、1為可以走、2為傳送門(transGate)
    {
        X = 20;
        Y = 20;
        gridW = 20;
        gridH = 20;
        setFloor(540);
        setCeiling(0);
        setMonsterFloor(540);
        int mapGrid_init[400][70];
        for (int i = 0; i < 400; i++)
        {
            for (int j = 0; j < 70; j++)
            {
                mapGrid_init[i][j] = 1;
            }
        }
        //給予地圖左上角座標及每張小圖寬度
        for (int i = 0; i < 11; i++)
        {
            for (int j = 27; j < 70; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }

        for (int i = 13; i < 26; i++)
        {
            mapGrid_init[i][33] = 4;
        }

        for (int i = 42; i < 77; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }

        for (int i = 27; i < 77; i++)
        {
            for (int j = 22; j < 70; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }

        for (int i = 94; i < 114; i++)
        {
            for (int j = 12; j < 37; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }

        for (int i = 77; i < 93; i++)
        {  
            mapGrid_init[i][29] = 3;
            mapGrid_init[i][36] = 3;
        }

        for (int i = 186; i < 190; i++)
        {
            for (int j = 0; j < 70; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }

        for (int i = 166; i < 186; i++)
        {
            for (int j = 0; j < 70; j++)
            {
                mapGrid_init[i][j] = 2;
            }
        }

        for (int i = 0; i < 400; i++)
        {
            for (int j = 0; j < 70; j++)
            {
                mapGrid[i][j] = mapGrid_init[i][j]; //依序填入mapGrid
            }
        }
    }

    MapS2::~MapS2()
    {
    }

    void MapS2::LoadBitmap()
    {
        //white.LoadBitmap(IDB_WHITE);
        //blue.LoadBitmap(IDB_BLUE);
        map.LoadBitmap(".\\res\\map02.bmp");
        exitBitmap.LoadBitmap(IDB_EXIT, RGB(0, 0, 0));
        pressEBitmap.LoadBitmap(IDB_PRESSE, RGB(0, 0, 0));
    }

    void MapS2::Initialize()
    {
        setXY(-100, -260);
        setScreenMoving(true);
        setMapName("MapS2");
        setCeiling(0);
        setStartPosition(100);
        setCharacterYRelativeMovement(0);
        previousFloor = 0;
        targetSY = 0;
        screenUp = screenDown = false;
    }

    void MapS2::setPos(int x, int y, int n)
    {
        int gridX = x / 20;
        int gridY = y / 20;
        mapGrid[gridX][gridY] = n;
    }

    bool MapS2::isEmpty(int x, int y) const
    {
        int gridX = x / 20;
        int gridY = y / 20;
        if (mapGrid[gridX][gridY] != 0)
        {
            return true;
        }
        return false;
    }

    bool MapS2::isPortal(int x, int y) const
    {
        int gridX = x / 20;
        int gridY = y / 20;
        if (mapGrid[gridX][gridY] == 2)
        {
            return true;
        }
        return false;
    }

    bool MapS2::isBridge(int x, int y) const
    {
        int gridX = x / 20;
        int gridY = y / 20;
        if (mapGrid[gridX][gridY] == 3)
        {
            return true;
        }
        return false;
    }

    void MapS2::onShow()
    {
        map.SetTopLeft(getSX(), getSY());
        map.ShowBitmap();
        syMoving(targetSY);

        if (getPortalOpen())
        {
            exitBitmap.SetTopLeft(3470 + getSX(), 300);
            exitBitmap.ShowBitmap();
            pressEBitmap.SetTopLeft(600, 650);
            pressEBitmap.ShowBitmap();
        }
    }

    void MapS2::syMoving(int y)
    {
        if (screenUp)
        {
            if (getSY()-20 > y)
            {
                addCharacterYRelativeMovement(20);
                addSY(-20);
            }
            else
            {
                screenUp = false;
                addCharacterYRelativeMovement(y - getSY());
                addSY(getSY()-y);
            }
        }

        if (screenUp)
        {
            if (getSY()-20 > y)
            {
                addCharacterYRelativeMovement(20);
                addSY(-20);
            }
            else
            {
                screenUp = false;
                addCharacterYRelativeMovement(getSY() - y);
                addSY(y - getSY());
            }
        }
        else if (screenDown)
        {
            if (getSY() + 20 < y)
            {
                addCharacterYRelativeMovement(-20);
                addSY(20);
            }
            else
            {
                screenDown = false;
                addCharacterYRelativeMovement(getSY() - y);
                addSY(y - getSY());
            }
        }
    }

    void MapS2::setCharacterX(int x)
    {
        characterX = x;
    }
    void MapS2::setCharacterY(int y)
    {
        characterY = y;
    }
    void MapS2::monsterFloorChanging(int x)
    {
        if (x < 1750)
        {
            setMonsterFloor(640);
        }
        else if (x < 2500)
        {
            setMonsterFloor(560);
        }
        else
        {
            setMonsterFloor(460);
        }
    }

    void MapS2::characterFloorChanging()
    {
        if (characterX < 218)
        {
            setFloor(540);
        }
        else if (characterX < 410)
        {
            setFloor(680);
        }
        else if (characterX < 500)
        {
            if (characterY > 382)
                setFloor(680);
            else
                setFloor(500);
        }
        else if (characterX < 1538)
        {
            setFloor(440);
            if (getSX() < -205)
                setCeiling(265);
            else 
                setCeiling(0);
        }
        else
        {
            if (characterY > 612 || characterX>2280)
            {
                setFloor(880);
                if (characterX > 1850 && characterX < 2280)
                    setCeiling(740);
                else
                    setCeiling(470);
                if (getSY() != -550)
                {
                    screenUp = true;
                    targetSY = -550;
                }
                previousFloor = 880;

            }
            else if (characterY > 462)
            {
                setFloor(730);
                setCeiling(265);
                if (characterY > 490 && previousFloor == 580 && getSY() != -550)
                {
                    screenUp = true;
                    targetSY = -550;
                } 
            }     
            else
            {
                setFloor(580);
                if (getSY() != -260)
                {
                    screenDown = true;
                    targetSY = -260;
                }
                previousFloor = 580;
            }
        }
    }

    int MapS2::screenX(int x)
    {
        return x + getSX();
    }
    int MapS2::screenY(int y)
    {
        return y + getSY();
    }
}