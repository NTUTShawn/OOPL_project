#ifndef __MAPS2__
#define __MAPS2__

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѧa�Ϻc��
	/////////////////////////////////////////////////////////////////////////////
	class MapS2 : public Map
	{
	public:
		MapS2();
		~MapS2();
		void LoadBitmap();
		void Initialize();
		void setPos(int x, int y, int n);			//�N�a�Ϯy�Ъ��}�C�]���ǤJ���Ʀr
		bool isEmpty(int x, int y) const;
		bool isPortal(int x, int y) const;
		bool isBridge(int x, int y) const;
		bool isCraftTable(int x, int y) const;
		bool isTrashCan(int x, int y) const;
		bool isGetHurtPlace(int x, int y) const;
		void onShow();
		void syMoving(int y);
		void monsterFloorChanging(int x) override;
		void characterFloorChanging() override;
		int screenX(int x) override;
		int screenY(int y) override;
	protected:
		CMovingBitmap map;
		int X, Y;
		int mapGrid[400][70];
		CMovingBitmap white, blue;
		int gridW, gridH;
		
		int previousFloor;
		int targetSY;
		bool screenUp;
		bool screenDown;
	};
}
#endif
