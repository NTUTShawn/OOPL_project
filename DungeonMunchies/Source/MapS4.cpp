#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "MapS4.h"
#include <vector>
namespace game_framework
{
    /////////////////////////////////////////////////////////////////////////////
    // 這個class提供地圖構成
    /////////////////////////////////////////////////////////////////////////////
    MapS4::MapS4() : Map(0, 0) //地圖設置：0為不能走、1為可以走、2為傳送門、3為橋、4為鍛造台、5為垃圾桶、6為受傷區域
    {
        X = 20;
        Y = 20;
        gridW = 20;
        gridH = 20;
        startX = 200;
        finalX = 3250;
        setFloor(540);
        setCeiling(0);
        setMonsterFloor(540);
        int mapGrid_init[400][70];
        for (int i = 1; i < 400; i++)
        {
            for (int j = 0; j < 70; j++)
            {
                mapGrid_init[i][j] = 1;
            }
        }
        //給予地圖左上角座標及每張小圖寬度
        for (int i = 0; i < 400; i++)
        {
            for (int j = 37; j < 70; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 0; i < 400; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 0; i < 14; i++)
        {
            for (int j = 5; j < 37; j++)
            {
                mapGrid_init[i][j] = 2;
            }
        }
        for (int i = 35; i < 400; i++)
        {
            for (int j = 5; j < 14; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 0; i < 38; i++)
        {
            for (int j = 27; j < 32; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 0; i < 72; i++)
        {
            for (int j = 32; j < 37; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 37; i < 54; i++)
        {
            mapGrid_init[i][30] = 6;
            mapGrid_init[i][31] = 6;
        }
        for (int i = 56; i < 65; i++)
        {
            for (int j = 26; j < 32; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 79; i < 88; i++)
        {
            for (int j = 14; j < 28; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 92; i < 97; i++)
        {
            mapGrid_init[i][33] = 3;
        }
        for (int i = 98; i < 113; i++)
        {
            for (int j = 31; j < 37; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 97; i < 113; i++)
        {
            mapGrid_init[i][29] = 6;
            mapGrid_init[i][30] = 6;
        }
        for (int i = 101; i < 107; i++)
        {
            mapGrid_init[i][27] = 3;
        }
        for (int i = 117; i < 400; i++)
        {
            for (int j = 14; j < 21; j++)
            {
                mapGrid_init[i][j] = 0;
            }
        }
        for (int i = 155; i < 176; i++)
        {
            for (int j = 21; j < 37; j++)
            {
                mapGrid_init[i][j] = 2;
            }
        }
        for (int i = 176; i < 400; i++)
        {
            for (int j = 0; j < 70; j++)
            {
                mapGrid_init[i][j] = 0;
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
    MapS4::~MapS4()
    {
    }
    void MapS4::LoadBitmap()
    {
        map.LoadBitmap(IDB_MAPS4);
        exitBitmap.LoadBitmap(IDB_EXIT, RGB(0, 0, 0));
        pressEBitmap.LoadBitmap(IDB_PRESSE, RGB(0, 0, 0));
        trashCanClosedBitmap.LoadBitmap(IDB_TRASHCANCLOSED, RGB(0, 0, 0));
        trashCanOpenBitmap.LoadBitmap(IDB_TRASHCANOPEN, RGB(0, 0, 0));
        craftingBitmap.LoadBitmap(IDB_CRAFTING, RGB(0, 0, 0));
        loadMagnifierBitmap();
    }
    void MapS4::Initialize()
    {
        setXY(0, -270);
        setInitialXY(0, -270);
        setScreenMoving(true);
        setMapName("MapS4");
        setCeiling(0);
        previousFloor = 0;
        targetSY = 0;
        trashCanOpen = false;
        screenUp = screenDown = false;
        messageCode = 0;
        canShowMessage = false;
        autoShowMessage = false;
        havePlayedAutoMessage = false;
        showMaginifierFlag = false;
        showMessageIconFlag = false;
        messageCounter = 1;
        messageSize = 6;
        messageEndFlag = false;
    }
    void MapS4::setPos(int x, int y, int n)
    {
        int gridX = x / 20;
        int gridY = y / 20;
        mapGrid[gridX][gridY] = n;
    }
    bool MapS4::isEmpty(int x, int y) const
    {
        return (blockProperty(x, y) != 0);
    }
    bool MapS4::isPortal(int x, int y) const
    {
        return (blockProperty(x, y) == 2);
    }
    bool MapS4::isBridge(int x, int y) const
    {
        return (blockProperty(x, y) == 3);
    }
    bool MapS4::isCraftTable(int x, int y) const
    {
        return (blockProperty(x, y) == 4);
    }
    bool MapS4::isTrashCan(int x, int y) const
    {
        return (blockProperty(x, y) == 5);
    }
    bool MapS4::isGetHurtPlace(int x, int y) const
    {
        return (blockProperty(x, y) == 6);
    }
    int MapS4::blockProperty(int x, int y) const
    {
        int gridX = x / 20;
        int gridY = y / 20;
        return mapGrid[gridX][gridY];
    }
    void MapS4::onShow()
    {
        map.SetTopLeft(getSX(), getSY());
        map.ShowBitmap();

        syMoving(targetSY);

        if (getPortalOpen())
        {
            if (characterX < 500)
                exitBitmap.SetTopLeft(80 + getSX(), 230);
            else
                exitBitmap.SetTopLeft(3240 + getSX(), 250);
            
            pressEBitmap.SetTopLeft(600, 610);
            exitBitmap.ShowBitmap();
            pressEBitmap.ShowBitmap();
        }
    }
    void MapS4::syMoving(int y)
    {
        if (screenUp)
        {
            if (getSY() - 15 > y)
            {
                addSY(-15);
            }
            else
            {
                addSY(y - getSY());
                screenUp = false;
            }
        }
        else if (screenDown)
        {
            if (getSY() + 15 < y)
            {
                addSY(15);
            }
            else
            {
                addSY(y - getSY());
                screenDown = false;
            }
        }
    }
    void MapS4::monsterFloorChanging(int x)
    {
        if (x < 750)
            setMonsterFloor(540);
        else if (x < 1120)
            setMonsterFloor(630);
        else if (x < 1315)
            setMonsterFloor(485);
        else if (x < 1447)
            setMonsterFloor(630);
        else if (x < 1925)
            setMonsterFloor(725);
        else if (x < 2265)
            setMonsterFloor(605);
        else
            setMonsterFloor(725);
    }
    void MapS4::characterFloorAndCeiling()
    {
        if (characterX < 750)
            setFloor(540);
        else if (characterX < 1090)
            setFloor(630);
        else if (characterX < 1315)
        {
            setFloor(485);
            if (getSY() != -270)
            {
                screenDown = true;
                targetSY = -270;
            }
        }
        else if (characterX < 1447)
            setFloor(630);
        else if (characterX < 1925)
        {
            if (getSY() != -440)
            {
                screenUp = true;
                targetSY = -440;
            }
            if (characterX > 1850 && characterY+120 < 674)
                setFloor(665);
            else
                setFloor(725);
        }
        else if (characterX < 2265)
        {
            if (characterX > 2035 && characterX < 2115 && characterY + 120 < 554)
                setFloor(545);
            else
                setFloor(605);
        }
        else
            setFloor(725);
        if (characterX < 650)
            setCeiling(100);
        else if (characterX < 1535)
            setCeiling(290);
        else if (characterX < 1780)
            setCeiling(570);
        else if (characterX < 2335)
            setCeiling(340);
        else
            setCeiling(405);
    }
    int MapS4::screenX(int x)
    {
        return x + getSX();
    }
    int MapS4::screenY(int y)
    {
        return y + getSY();
    }
    void MapS4::messageOnShow()
    {
        int mX = 136, mY = 201;
        if (messageCounter == 1)
        {
            message01.SetTopLeft(mX, mY);
            message01.ShowBitmap();
        }
        else if (messageCounter == 2)
        {
            message02.SetTopLeft(mX, mY);
            message02.ShowBitmap();
        }
        else if (messageCounter == 3)
        {
            message03.SetTopLeft(mX, mY);
            message03.ShowBitmap();
        }
        else if (messageCounter == 4)
        {
            message04.SetTopLeft(mX, mY);
            message04.ShowBitmap();
        }
        else if (messageCounter == 5)
        {
            message05.SetTopLeft(mX, mY);
            message05.ShowBitmap();
        }
        else if (messageCounter == 6)
        {
            message06.SetTopLeft(mX, mY);
            message06.ShowBitmap();
            messageEndFlag = true;
        }
    }
}