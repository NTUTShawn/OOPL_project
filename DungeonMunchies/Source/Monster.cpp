#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Util.h"
#include "Monster.h"
#include "Character.h"
#include "SourceStorage.h"
#include "Map.h"

namespace game_framework
{
	Monster::Monster()
	{
		_x = 400;
		_y = 400;
		hp = 1200;
		attackDamage = 0;
		isAttacking = false;
		isIntersect = false;
	}

	Monster::Monster(int x, int y, int enemyHp, int ATK, Character* c)
	{
		_x = x;
		_y = y;
		init_x = x;
		init_y = y;
		hp = enemyHp;
		maxHp = enemyHp;
		attackDamage = ATK;
		isAttacking = false;
		isIntersect = false;
		character = c;
		characterDirectionLR = 0;
		characterDirectionTD = 0;
		bossDead = false;
		hasGottenSource = false;
		lossHp = 0;
		lossHpShowFlag = 0;
	}

	Monster::~Monster()
	{
	}

	void Monster::intersect()
	{
		if (isAlive())
		{
			if (character->GetRightX() >= GetLeftX() && character->GetRightX() <= GetRightX()
				&& character->GetButtonY() >= GetTopY() - 20 && character->GetButtonY() <= GetButtonY())
			{ //����k��I��Ǫ�
				isIntersect = true;
				if (!character->GetIsInvincible())
				{
					character->SetIsAttackedFromRight(true);
				}
			}
			if (character->GetLeftX() <= GetRightX() && character->GetLeftX() >= GetLeftX()
				&& character->GetButtonY() >= GetTopY() - 20 && character->GetButtonY() <= GetButtonY())
			{ //���⥪��I��Ǫ�
				isIntersect = true;
				if (!character->GetIsInvincible())
				{
					character->SetIsAttackedFromLeft(true);
				}
			}
			if ((character->GetRightX() >= GetLeftX() && character->GetRightX() <= GetRightX() ||
				character->GetLeftX() <= GetRightX() && character->GetLeftX() >= GetLeftX() ||
				character->GetLeftX() <= GetLeftX() && character->GetRightX() >= GetRightX() || //�����Ǫ��e
				character->GetRightX() <= GetRightX() && character->GetLeftX() >= GetLeftX()) //�Ǫ��񨤦�e
				&& character->GetButtonY() >= GetTopY() - 20 && character->GetButtonY() <= GetButtonY())
			{ //����U��I��Ǫ�
				isIntersect = true;
				if (!character->GetIsInvincible())
				{
					character->SetIsAttackedFromButton(true);
				}
			}
			if (isIntersect && !character->GetIsInvincible())
			{
				character->lossCurrentHp(attackDamage);
			}
		}
		isIntersect = false;
	}

	//bool Monster::intersect(int lX, int rX, int tY, int bY)
	//{
	//	if (isAlive())
	//	{
	//		if ((character->GetRightX() >= lX && character->GetRightX() <= rX ||
	//			character->GetLeftX() <= rX && character->GetLeftX() >= lX ||
	//			character->GetLeftX() <= lX && character->GetRightX() >= rX || //�����Ǫ��e
	//			character->GetRightX() <= rX && character->GetLeftX() >= lX) //�Ǫ��񨤦�e
	//			&& character->GetButtonY() >= tY - 20 && character->GetButtonY() <= bY)
	//		{ //����U��I��Ǫ�
	//			return true;
	//		}
	//	}
	//	return false;
	//}

	void Monster::SetIsIntersect(bool flag)
	{
		isIntersect = flag;
	}

	bool Monster::GetIsIntersect()
	{
		return isIntersect;
	}

	int Monster::distanceToCharacter() //�P���⪺�Z�� �Y�ӻ��h���ΰʧ@
	{
		int x_distance = (GetLeftX() + GetRightX()) / 2 - (character->GetLeftX() + character->GetRightX()) / 2;
		int y_distance = _y - character->GetTopY();
		return (int)(sqrt(pow(x_distance, 2) + pow(y_distance, 2)));
	}

	void Monster::SetCharacterDirection()
	{
		int cX, cY, mX, mY;
		cX = (character->GetLeftX() + character->GetRightX()) / 2;
		cY = (character->GetButtonY() + character->GetTopY()) / 2;
		mX = (_x + GetRightX()) / 2;
		mY = (_y + GetButtonY()) / 2;
		if (cX < mX)
		{
			characterDirectionLR = 0; //����b�Ǫ�����
		}
		else
		{
			characterDirectionLR = 1;
		}
		if (cY < mY)
		{
			characterDirectionTD = 0;
		}
		else
		{
			characterDirectionTD = 1;
		}
	}

	bool Monster::GetCharacterDirectionLR()
	{
		return characterDirectionLR;
	}

	bool Monster::GetCharacterDirectionTD()
	{
		return characterDirectionTD;
	}

	double Monster::hpProportion()
	{
		return (double)(hp) / maxHp;
	}

	void Monster::SetXY(int x, int y)
	{
		_x = x;
		_y = y;
	}

	void Monster::SetRelativeMovement(int x)
	{
		RelativeMovement += x;
	}

	int Monster::GetBorder()
	{
		return BORDER;
	}

	int Monster::GetHorizontalGap()
	{
		return HORIZONTAL_GAP;
	}

	void Monster::SetMovingDown(bool b)
	{
		isMovingDown = b;
	}

	bool Monster::GetIsMovingDown()
	{
		return isMovingDown;
	}

	void Monster::SetMovingUp(bool b)
	{
		isMovingUp = b;
	}

	bool Monster::GetIsMovingUp()
	{
		return isMovingUp;
	}

	void Monster::SetMovingLeft(bool b)
	{
		isMovingLeft = b;
	}

	bool Monster::GetIsMovingLeft()
	{
		return isMovingLeft;
	}

	void Monster::SetMovingRight(bool b)
	{
		isMovingRight = b;
	}

	bool Monster::GetIsMovingRight()
	{
		return isMovingRight;
	}

	void Monster::SetFacingLR(bool b)
	{
		facingLR = b;
	}

	bool Monster::GetFacingLR()
	{
		return facingLR;
	}
	bool Monster::isAlive()
	{
		if (hp <= 0)
		{
			return false;
		}
		return true;
	}

	bool Monster::isAttack()
	{
		return isAttacking;
	}

	void Monster::knockBack()
	{
		if (facingLR == 0)
		{
			_x += 1;
		}
		if (facingLR == 1)
		{
			_x -= 1;
		}
	}

	void Monster::SetIsOnTheFloor(bool b)
	{
		isOnTheFloor = b;
	}

	bool Monster::GetIsOnTheFloor()
	{
		return isOnTheFloor;
	}

	void Monster::SetMaxHp(int x)
	{
		maxHp = x;
	}

	int Monster::GetMaxHp()
	{
		return maxHp;
	}

	void Monster::SetCurrentHp(int x)
	{
		hp = x;
	}

	int Monster::GetCurrentHp()
	{
		return hp;
	}

	void Monster::lossCurrentHp(int x)
	{
		hp -= x;
		lossHp = x;
		lossHpShowFlag = true;
		lossHpTimer.Start();
	}

	void Monster::lossHpShow()
	{
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(120, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		/*pDC->SetBkColor(RGB(230, 220, 200));*/
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 0, 0));
		char position[500];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(position, "%d", lossHp);
		pDC->TextOut(GetRightX() + 10, GetTopY() + 10, position);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

	void Monster::SetIsAttacking(bool flag)
	{
		isAttacking = flag;
	}

	bool Monster::GetIsAttacking()
	{
		return isAttacking;
	}

	void Monster::SetIsAttacked(bool flag)
	{
		isAttacked = flag;
	}

	bool Monster::GetIsAttacked()
	{
		return isAttacked;
	}

	void Monster::SetAttackDamage(int x)
	{
		attackDamage = x;
	}

	int Monster::GetAttackDamage()
	{
		return attackDamage;
	}

	void Monster::attackStart()
	{
		action = attack_a;
		attackCDTime.Start();
		attackCD = true;
	}

	void Monster::attackJudge(int attackRange)
	{
		if (!character->GetIsInvincible())
		{
			if (facingLR == 0)
			{
				if (isAttackSuccessfullyL(attackRange))
				{
					character->SetIsAttackedFromRight(true);
					character->lossCurrentHp(attackDamage);
				}
			}
			else
			{
				if (isAttackSuccessfullyR(attackRange))
				{
					character->SetIsAttackedFromLeft(true);
					character->lossCurrentHp(attackDamage);
				}
			}
		}
	}

	void Monster::SetBossDead(bool flag)
	{
		bossDead = flag;
	}

	bool Monster::GetBossDead()
	{
		return bossDead;
	}

	bool Monster::isAttackSuccessfullyL(int range)
	{
		if (((character->GetRightX() >= GetLeftX() - range && character->GetRightX() <= GetLeftX()) ||
			(character->GetLeftX() >= GetLeftX() - range && character->GetLeftX() <= GetLeftX()) ||
			(character->GetLeftX() <= GetLeftX() - range && character->GetRightX() >= GetRightX()))
			&& ((character->GetButtonY() >= GetTopY() && character->GetButtonY() <= GetButtonY()) ||
				(character->GetTopY() >= GetTopY() && character->GetTopY() <= GetButtonY()) ||
				(character->GetTopY() <= GetTopY() && character->GetButtonY() >= GetButtonY())))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Monster::isAttackSuccessfullyR(int range)
	{
		if (((character->GetLeftX() <= GetRightX() + range && character->GetLeftX() >= GetRightX()) ||
			(character->GetRightX() <= GetRightX() + range && character->GetRightX() >= GetRightX()) ||
			(character->GetLeftX() <= GetRightX() && character->GetRightX() >= GetRightX() + range))
			&& ((character->GetButtonY() >= GetTopY() && character->GetButtonY() <= GetButtonY()) ||
				(character->GetTopY() >= GetTopY() && character->GetTopY() <= GetButtonY()) ||
				(character->GetButtonY() >= GetButtonY() && character->GetTopY() <= GetTopY())))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Monster::touchSource(Map* m, int sourceCase)
	{
		if (character->isIntersect((_x + GetRightX()) / 2 + RelativeMovement, (_x + GetRightX()) / 2 + RelativeMovement + 64, m->getMonsterFloor() - 64, m->getMonsterFloor()))
		{
			hasGottenSource = true;
			character->GetSourceStorage()->add(sourceCase);
		}
	}
}
