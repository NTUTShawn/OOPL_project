#ifndef __MAPS1__
#define __MAPS1__
namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѧa�Ϻc��
	/////////////////////////////////////////////////////////////////////////////
	class MapS1 : public Map
	{
	public:
		MapS1();
		~MapS1();
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
		void monsterFloorChanging(int x) override;
		int screenX(int x) override;
		int screenY(int y) override;
		void messageOnShow() override;
	protected:
		CMovingBitmap map;
		int X, Y;
		int mapGrid[100][18];
		CMovingBitmap white, blue;
		int gridW, gridH;
		CMovingBitmap message01;
		CMovingBitmap message02;
		CMovingBitmap message03;
		CMovingBitmap message04;
	};
}
#endif