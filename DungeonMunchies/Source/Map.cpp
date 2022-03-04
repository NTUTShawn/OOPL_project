#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"

/////////////////////////////////////////////////////////////////////////////
// �o��class���C��������H������
/////////////////////////////////////////////////////////////////////////////
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
// �o��class���Ѧa�Ϻc��
/////////////////////////////////////////////////////////////////////////////

	Map::Map()
		:X(20), Y(40), mapW(120), mapH(100) //�����a�ϥ��W���y�ФΨC�i�p�ϼe��
	{
		int map_init[4][5] = { //�����a�ϰ}�C���
			{0,0,1,0,0},
			{0,1,2,1,0},
			{1,2,1,2,1},
			{2,1,2,1,2},
		};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 5; j++)
				map[i][j] = map_init[i][j]; //�̧Ƕ�Jmap
		}
	}

	void Map::LoadBitmap() {
		map1.LoadBitmap(IDB_BOSSMAP);
		map2.LoadBitmap(IDB_MAP2);
	}

	void Map::onShow() {
		for (int i = 0; i < 5; i++) { //���k��ܤ��i��
			for (int j = 0; j < 4; j++) { //���U��ܥ|�i��
				switch (map[j][i]) {
				case 0:
					break;
				case 1:
					map1.SetTopLeft(X + (mapW * i), Y + (mapH * j)); //�]�w�C�i�Ϫ��y��
					map1.ShowBitmap(); //��ܳ]�w�����y��
					break;
				case 2:
					map2.SetTopLeft(X + (mapW * i), Y + (mapH * j)); //�]�w�C�i�Ϫ��y��
					map2.ShowBitmap(); // ��ܳ]�w�����y��
					break;
				default:
					ASSERT(0); //map�}�C���ӥX�{0,1,2���~����
				}
			}
		}
	}
}