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

	Map::Map(int x, int y)
	{
		sx = x;
		sy = y;
	}
	void Map::addSX(int n)			//sx+=n ��ܦa�ϦV������n
	{
		sx += n;
	}
	void Map::addSY(int n)			//sx+=n ��ܦa�ϤW����n
	{
		sy += n;
	}
	void Map::setXY(int x, int y)
	{
		sx = x;
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
}