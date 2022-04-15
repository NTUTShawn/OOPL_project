#ifndef __MONSTER__
#define __MONSTER__

#include "BloodBar.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// �o��class�O�ĤH������    											   //
	/////////////////////////////////////////////////////////////////////////////
	class Character;
	class Map;
	class BloodBar;
	class Monster
	{
	public:
		Monster();
		Monster::Monster(int x, int y, int enemyHp, int attackDamage, Character* c);
		virtual ~Monster();
		virtual void LoadBitmap() = 0;				//�[���ĤHBitmap
		virtual void Initialize() = 0;				//��l��
		virtual void OnShow(Map* m) = 0;			//��ܼĤH��e���W
		virtual void OnMove(Map* m) = 0;			//�ĤH����
		virtual int  GetLeftX() = 0;				// ���W�� x �y��
		virtual int  GetTopY() = 0;					// ���W�� y �y��
		virtual int  GetRightX() = 0;				// �k�U�� x �y��
		virtual int  GetButtonY() = 0;				// �k�U�� y �y��
		//�^���O�_�M���ĤH�Ҧb�P�@��m�A�e���OcannotPass
		virtual bool isIntersect() = 0;
		int distanceToHero();
		double hpProportion();
		/////////////////////////////////////////////////////////////////////////////
		// �]�wMonster���y�Ъ��禡��												   //
		/////////////////////////////////////////////////////////////////////////////
		void SetMovingDown(bool b);					//�U
		void SetMovingUp(bool b);					//�W
		void SetMovingLeft(bool b);					//��
		void SetMovingRight(bool b);				//�k
		void SetXY(int x, int y);					//x, y�y��
		bool isAlive();
		bool isAttack();
		void knockBack();
	protected:
		Character* character;
		int _x, _y;
		int init_x, init_y;
		int hp;
		int fullHp;
		BloodBar bloodBar;
		int attackDamage;
		bool isMovingRight;
		bool isMovingLeft;
		bool isMovingUp;
		bool isMovingDown;
		bool isAttacking;
		int _direction;
	};
}
#endif
