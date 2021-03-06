#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include <vector>

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// 這個class提供地圖構成
	/////////////////////////////////////////////////////////////////////////////

	Map::Map(int x, int y)
	{
		sx = x;
		sy = y;
		portalOpen = false;
	}
	string Map::getMapName()
	{
		return mapName;
	}
	int Map::getStartPosition()
	{
		return startX;
	}
	int Map::getFinalPosition()
	{
		return finalX;
	}
	void Map::setSX(int x)
	{
		sx = x;
	}
	void Map::setSY(int y)
	{
		sy = y;
	}
	int Map::getSX()
	{
		return sx;
	}
	int Map::getSY()
	{
		return sy;
	}
	bool Map::mapScreenMoving()
	{
		return screenMoving;
	}
	int Map::getFloor()
	{
		return floor;
	}
	int Map::getCeiling()
	{
		return ceiling;
	}
	bool Map::getCraftTableOpen()
	{
		return craftTableOpen;
	}
	void Map::setCraftTableOpen(bool flag)
	{
		craftTableOpen = flag;
	}
	bool Map::getPortalOpen()
	{
		return portalOpen;
	}
	void Map::setMapName(string name)
	{
		mapName = name;
	}
	int Map::getMonsterFloor()
	{
		return monsterFloor;
	}
	void Map::setMonsterFloor(int y)
	{
		monsterFloor = y;
	}
	void Map::addSX(int n)			//sx+=n 表示地圖向左移動n
	{
		sx += n;
	}
	void Map::addSY(int n)			//sx+=n 表示地圖上移動n
	{
		sy += n;
	}
	void Map::setCharacterX(int x)
	{
		characterX = x;
	}
	void Map::setCharacterY(int y)
	{
		characterY = y;
	}
	void Map::setXY(int x, int y)
	{
		sx = x;
		sy = y;
	}
	void Map::setInitialX(int x)
	{
		initialX = x;
	}
	int Map::getInitialX()
	{
		return initialX;
	}
	void Map::setInitialY(int y)
	{
		initialY = y;
	}
	int Map::getInitialY()
	{
		return initialY;
	}
	void Map::setInitialXY(int x, int y)
	{
		initialX = x;
		initialY = y;
	}
	int Map::getXMovement()
	{
		return sx - initialX;
	}
	int Map::getYMovement()
	{
		return sy - initialY;
	}
	void Map::loadMagnifierBitmap()
	{
		magnifier.LoadBitmap(IDB_MAGNIFIERR, RGB(0, 0, 0));
	}
	void Map::loadMagnifierLBitmap()
	{
		magnifierL.LoadBitmap(IDB_MAGNIFIERL, RGB(0, 0, 0));
	}
	void Map::showMaginifier(int x, int y)
	{
		magnifier.SetTopLeft(x + getSX(), y + getSY());
		magnifier.ShowBitmap();
	}
	void Map::showMaginifierL(int x, int y)
	{
		magnifierL.SetTopLeft(x + getSX(), y + getSY());
		magnifierL.ShowBitmap();
	}
	void Map::setShowMaginifierFlag(bool flag)
	{
		showMaginifierFlag = flag;
	}
	bool Map::getShowMaginifierFlag()
	{
		return showMaginifierFlag;
	}
	void Map::loadMessageIconBitmap()
	{
		messageIcon.LoadBitmap(IDB_MESSAGEICON, RGB(0, 0, 0));
	}
	void Map::showMessageIcon(int x, int y)
	{
		messageIcon.SetTopLeft(x + getSX(), y + getSY());
		messageIcon.ShowBitmap();
	}
	void Map::setShowMessageIconFlag(bool flag)
	{
		showMessageIconFlag = flag;
	}
	bool Map::getShowMessageIconFlag()
	{
		return showMessageIconFlag;
	}
	void Map::setCanShowMessage(bool flag, int code)
	{
		canShowMessage = flag;
		messageCode = code;
	}
	bool Map::getCanShowMessage()
	{
		return canShowMessage;
	}
	void Map::setAutoShowMessage(bool flag, int code)
	{
		autoShowMessage = flag;
		messageCode = code;
	}
	bool Map::getAutoShowMessage()
	{
		return autoShowMessage;
	}
	void Map::setHavePlayedAutoMessage(bool flag)
	{
		havePlayedAutoMessage = flag;
	}
	bool Map::getHavePlayedAutoMessage()
	{
		return havePlayedAutoMessage;
	}
	void Map::setFloor(int y)
	{
		floor = y;
	}
	void Map::setCeiling(int y)
	{
		ceiling = y;
	}
	void Map::setScreenMoving(bool flag)
	{
		screenMoving = flag;
	}
	void Map::setPortalOpen(bool flag)
	{
		portalOpen = flag;
	}
	bool Map::getTrashCanOpen()
	{
		return trashCanOpen;
	}
	void Map::setTrashCanOpen(bool flag)
	{
		trashCanOpen = flag;
	}
	void Map::setMessageCounter(int n)
	{
		messageCounter = n;
	}
	int Map::getMessageCounter()
	{
		return messageCounter;
	}
	void Map::setMessageCounterToNext()
	{
		if (messageCounter != messageSize)
		{
			messageCounter += 1;
		}
		else
		{
			messageCounter = 1;
		}
	}
	void Map::setMessageEndFlag(bool flag)
	{
		messageEndFlag = flag;
	}
	bool Map::getMessageEndFlag()
	{
		return messageEndFlag;
	}
	void Map::InitializeMessage()
	{
		messageCounter = 1;
		messageEndFlag = false;
	}
	void Map::messageOnShow()
	{
	}
}