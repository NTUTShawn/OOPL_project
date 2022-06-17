#ifndef __MAPS_H__
#define __MAPS_H__
#include "Util.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѧa�Ϻc��
	/////////////////////////////////////////////////////////////////////////////
	class Map
	{
	public:
		Map(int x, int y);
		string getMapName();
		void setMapName(string name);
		int getStartPosition();
		int getFinalPosition();
		void setSX(int x);
		void setSY(int y);
		int getSX();
		int getSY();
		bool mapScreenMoving();
		virtual void addSX(int n);
		virtual void addSY(int n);
		virtual int screenX(int x) { return 0; };
		virtual int screenY(int y) { return 0; };
		void setCharacterX(int x);
		void setCharacterY(int y);
		void setScreenMoving(bool flag);
		virtual void setPos(int x, int y, int n) = 0;
		void setXY(int x, int y);
		void setInitialX(int x);
		int getInitialX();
		void setInitialY(int y);
		int getInitialY();
		void setInitialXY(int x, int y);
		int getXMovement();
		int getYMovement();
		//�a�Ϥ���]�w
		virtual bool isEmpty(int x, int y) const = 0;
		virtual bool isPortal(int x, int y) const = 0;
		virtual bool isBridge(int x, int y) const = 0;
		virtual bool isCraftTable(int x, int y) const = 0;
		virtual bool isTrashCan(int x, int y) const = 0;
		virtual bool isGetHurtPlace(int x, int y) const = 0;
		//����ΩǪ��a�O�B�Ѫ�O
		virtual void monsterFloorChanging(int x) {};
		int getMonsterFloor();								//�Ǫ��a�O
		void setMonsterFloor(int y);
		virtual void characterFloorAndCeiling() {};
		int getFloor();										//����a�O
		void setFloor(int y);
		int getCeiling();									//����Ѫ�O
		void setCeiling(int y);
		//��y�x�B�ǰe���B�U����
		bool getCraftTableOpen();
		void setCraftTableOpen(bool flag);
		bool getPortalOpen();
		void setPortalOpen(bool flag);
		bool getTrashCanOpen();
		void setTrashCanOpen(bool flag);
		/*�T�������禡*/
		//��j��
		void loadMagnifierBitmap();
		void loadMagnifierLBitmap();
		void showMaginifier(int x, int y);
		void showMaginifierL(int x, int y);
		void setShowMaginifierFlag(bool flag);
		bool getShowMaginifierFlag();
		//�T���ϥ�
		void loadMessageIconBitmap();
		void showMessageIcon(int x, int y);
		void setShowMessageIconFlag(bool flag);
		bool getShowMessageIconFlag();
		//�T��
		void setCanShowMessage(bool flag, int code);
		bool getCanShowMessage();
		void setAutoShowMessage(bool flag, int code);
		bool getAutoShowMessage();
		void setHavePlayedAutoMessage(bool flag);
		bool getHavePlayedAutoMessage();
		void setMessageCounter(int n);
		int getMessageCounter();
		void setMessageCounterToNext();
		void setMessageEndFlag(bool flag);
		bool getMessageEndFlag();
		void InitializeMessage();
		virtual void messageOnShow();
	protected:
		CMovingBitmap exitBitmap;
		CMovingBitmap pressEBitmap;
		CMovingBitmap trashCanOpenBitmap, trashCanClosedBitmap;
		CMovingBitmap craftingBitmap;
		int sx, sy; //screen ���y��
		int characterX, characterY;
		int initialX, initialY; //��lX�BY
		int startX; //�}�l��m
		int finalX; //������m
		string mapName;
		int floor;
		int monsterFloor;
		int ceiling;
		bool screenMoving;
		bool portalOpen;
		bool craftTableOpen;
		bool trashCanOpen;

		CMovingBitmap magnifier;
		CMovingBitmap magnifierL;
		bool showMaginifierFlag;
		CMovingBitmap messageIcon;
		bool showMessageIconFlag;

		int messageCode;
		bool canShowMessage;
		bool autoShowMessage;
		bool havePlayedAutoMessage;
		int messageCounter;
		int messageSize;
		bool messageEndFlag;
	};
}
#endif