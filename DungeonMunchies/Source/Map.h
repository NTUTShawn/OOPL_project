namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѧa�Ϻc��
	/////////////////////////////////////////////////////////////////////////////
	class Map {
	public:
		Map();
		void LoadBitmap();
		void onShow();
	protected:
		CMovingBitmap map1, map2;
		int map[4][15];
		const int X, Y;
		const int mapW, mapH;
	};
}