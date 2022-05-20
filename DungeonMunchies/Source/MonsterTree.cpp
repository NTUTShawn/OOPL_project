#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <cmath>
#include <ctgmath>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "Character.h"
#include "BloodBar.h"
#include "Monster.h"
#include "MonsterTree.h"
#include "Util.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	//�o��class�O�Ǫ�tree������											   //
	/////////////////////////////////////////////////////////////////////////////
	MonsterTree::MonsterTree()
	{
		_x = 400;
		_y = 400;
		hp = 10;
		attackDamage = 5;
		facingLR = 0;
		action = sleep_a;
		STEP_SIZE = 1;
		attackCD = false;
	}

	MonsterTree::MonsterTree(int x, int y, Character* c) : Monster(x, y, 50, 5, c)
	{
		hp = 50;
		attackDamage = 5;
		facingLR = 0;
		action = sleep_a;
		STEP_SIZE = 1;
		attackCD = false;
	}

	MonsterTree::~MonsterTree()
	{
	}

	void MonsterTree::LoadBitmap()
	{
		bloodBar.LoadBitmap();
		sleepLeft.LoadBitmap(".\\res\\monster_tree_sleep_left.bmp", RGB(0, 0, 0));
		sleepRight.LoadBitmap(".\\res\\monster_tree_sleep_right.bmp", RGB(0, 0, 0));

		walkLeft.AddBitmap(".\\res\\monster_tree_walk01_left.bmp", RGB(0, 0, 0));
		walkLeft.AddBitmap(".\\res\\monster_tree_walk02_left.bmp", RGB(0, 0, 0));
		walkLeft.AddBitmap(".\\res\\monster_tree_walk03_left.bmp", RGB(0, 0, 0));
		walkLeft.AddBitmap(".\\res\\monster_tree_walk04_left.bmp", RGB(0, 0, 0));
		walkRight.AddBitmap(".\\res\\monster_tree_walk01_right.bmp", RGB(0, 0, 0));
		walkRight.AddBitmap(".\\res\\monster_tree_walk02_right.bmp", RGB(0, 0, 0));
		walkRight.AddBitmap(".\\res\\monster_tree_walk03_right.bmp", RGB(0, 0, 0));
		walkRight.AddBitmap(".\\res\\monster_tree_walk04_right.bmp", RGB(0, 0, 0));

		attackLeft.AddBitmap(".\\res\\monster_tree_attack01_left.bmp", RGB(0, 0, 0));
		attackLeft.AddBitmap(".\\res\\monster_tree_attack02_left.bmp", RGB(0, 0, 0));
		attackLeft.AddBitmap(".\\res\\monster_tree_attack03_left.bmp", RGB(0, 0, 0));
		attackLeft.AddBitmap(".\\res\\monster_tree_attack04_left.bmp", RGB(0, 0, 0));
		attackLeft.AddBitmap(".\\res\\monster_tree_attack05_left.bmp", RGB(0, 0, 0));
		attackLeft.AddBitmap(".\\res\\monster_tree_attack06_left.bmp", RGB(0, 0, 0));
		attackLeft.AddBitmap(".\\res\\monster_tree_attack07_left.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_tree_attack01_right.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_tree_attack02_right.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_tree_attack03_right.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_tree_attack04_right.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_tree_attack05_right.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_tree_attack06_right.bmp", RGB(0, 0, 0));
		attackRight.AddBitmap(".\\res\\monster_tree_attack07_right.bmp", RGB(0, 0, 0));

		deadLeft.LoadBitmap(".\\res\\monster_tree_dead_left.bmp", RGB(0, 0, 0));
		deadRight.LoadBitmap(".\\res\\monster_tree_dead_right.bmp", RGB(0, 0, 0));
		sourceGuavaJuiceBlood.LoadBitmap(".\\res\\source_guava_juice_blood.bmp", RGB(0, 0, 0));
	}

	void MonsterTree::Initialize()
	{
		_x = init_x;
		_y = init_y;
		currentFloor = 0;
		RelativeMovement = 0;
		BORDER = 5;
		HORIZONTAL_GAP = 0;
		hp = 50;
		attackDamage = 5;
		facingLR = 0;
		action = sleep_a;
		bloodBar.setFullHP(hp);
		STEP_SIZE = 5;
		velocity = 0;
	}

	void MonsterTree::OnShow(Map* m)
	{
		if (isAlive())
		{
			if (facingLR == 0)
			{
				if (action == sleep_a)
				{
					sleepLeft.SetTopLeft(_x + RelativeMovement, _y);
					sleepLeft.ShowBitmap();
				}
				else if (action == walk_a)
				{
					walkLeft.SetTopLeft(_x + RelativeMovement, _y); //���Ϥ����Ǫ���ܾa�V��
					//walkLeft.SetDelayCount(3);
					walkLeft.OnShow();
				}
				else
				{
					attackLeft.SetTopLeft(_x + RelativeMovement, _y);
					attackLeft.SetDelayCount(4);
					attackLeft.OnShow();
					if (attackLeft.IsFinalBitmap())
					{
						action = actionController();
					}
				}
			}
			else
			{
				if (action == sleep_a)
				{
					sleepRight.SetTopLeft(_x + RelativeMovement, _y);
					sleepRight.ShowBitmap();
				}
				else if (action == walk_a)
				{
					walkRight.SetTopLeft(_x + RelativeMovement, _y);
					walkRight.OnShow();
				}
				else
				{
					attackRight.SetTopLeft(_x + RelativeMovement, _y);
					attackRight.SetDelayCount(4);
					attackRight.OnShow();
					if (attackRight.IsFinalBitmap())
					{
						action = actionController();
					}
				}
			}
			bloodBar.setXY(_x + RelativeMovement, _y - 16);
			bloodBar.showBloodBar(m, hp);
		}
		else
		{
			if (facingLR == 0)
			{
				deadLeft.SetTopLeft(_x + RelativeMovement, _y);
				deadLeft.ShowBitmap();
			}
			else
			{
				deadRight.SetTopLeft(_x + RelativeMovement, _y);
				deadRight.ShowBitmap();
			}
			if (!hasGottenSource)
			{
				sourceGuavaJuiceBlood.SetTopLeft((_x + GetRightX()) / 2 + RelativeMovement, m->getMonsterFloor() - 64);
				sourceGuavaJuiceBlood.ShowBitmap();
			}
		}
		showData();
	}

	void MonsterTree::OnMove(Map* m)
	{
		if (!character->GetMap() == NULL)
		{
			character->GetMap()->monsterFloorChanging(GetLeftX());
			if (character->GetMap()->getMonsterFloor() > currentFloor)
			{

				if (_y < character->GetMap()->getMonsterFloor() - 170)
				{
					_y += velocity * 2;
					if (velocity < 6)
						velocity++;
				}
				else
				{
					currentFloor = character->GetMap()->getMonsterFloor();
					_y = currentFloor - 170;			// ��y�y�ЧC��a�O�A�󥿬��a�O�W
					velocity = 0;
				}
			}
		}
		if (isAlive())
		{
			SetCharacterDirection();
			if (distanceToCharacter() < 280 && action == sleep_a)
			{
				action = walk_a;
			}
			if (distanceToCharacter() >= 280 && action == walk_a)
			{
				action = sleep_a;
			}
			if (action == walk_a)
			{
				facingLR = characterDirectionLR;
			}
			if (distanceToCharacter() < 130 && attackCD == false)
			{
				attack();
				intersect();
			}
			else if (distanceToCharacter() < 280 && action == walk_a)
			{
				if (characterDirectionLR == 0 && (GetLeftX() - STEP_SIZE + BORDER) >= character->GetRightX() && character->GetMap()->isEmpty(GetLeftX() - STEP_SIZE - BORDER, GetButtonY() - 34))
				{
					_x -= STEP_SIZE;
				}
				else if (characterDirectionLR == 1 && (GetRightX() + STEP_SIZE - BORDER - 5) <= character->GetLeftX() && character->GetMap()->isEmpty(GetRightX() + STEP_SIZE + BORDER, GetButtonY() - 34))
				{
					_x += STEP_SIZE;
				}
			}
			attackCDTime.CaculateTimeForFalse(&attackCD, 2);
			walkLeft.OnMove();
			walkRight.OnMove();

			attackLeft.OnMove();
			attackRight.OnMove();

			//intersect();
		}
		else
		{
			if (!hasGottenSource)
			{
				touchSource(m, guava_juice_blood_p);
			}
		}
	}

	void MonsterTree::SetFacingLR(bool flag)
	{
		facingLR = flag;
	}

	bool MonsterTree::GetFacingLR()
	{
		return facingLR;
	}

	int MonsterTree::GetLeftX() //�H�����鬰�D(�����d�򤣭n��b�̭�)
	{
		if (facingLR == 0) //left
		{
			return _x + 87;
		}
		else
		{
			return _x + 60;
		}
	}

	int MonsterTree::GetTopY() //�ݽվ�H������ܪ���(_y + (�Ϥ�����-���鰪��))
	{
		if (action == walk_a) //left
		{
			return _y + 72;
		}
		else
		{
			return _y;
		}
	}

	int MonsterTree::GetRightX() //�[�W���饻��������
	{
		if (facingLR == 0) //left
		{
			return _x + 175;
		}
		else
		{
			return _x + 145;
		}
	}

	int MonsterTree::GetButtonY()
	{
		return _y + walkLeft.Height();
	}

	Action MonsterTree::actionController()
	{
		if (distanceToCharacter() < 280)
		{
			return walk_a;
		}
		else
		{
			return sleep_a;
		}
	}

	void MonsterTree::attack()
	{
		if (attackCD == false) //�O�I�_���h�[��
		{
			action = attack_a;
			attackCDTime.Start();
			attackCD = true;
			if (!character->GetIsInvincible())
			{
				if (facingLR == 0)
				{
					if (isAttackSuccessfullyL(90))
					{
						character->SetIsAttackedFromRight(true);
						character->lossCurrentHp(attackDamage);
					}
				}
				else
				{
					if (isAttackSuccessfullyR(90))
					{
						character->SetIsAttackedFromLeft(true);
						character->lossCurrentHp(attackDamage);
					}
				}
			}
		}
	}

	void MonsterTree::showData()
	{
		int CharacterLeftX = character->GetLeftX();
		int CharacterRightX = character->GetRightX();
		int CharacterTopY = character->GetTopY();
		int CharacterButtonY = character->GetButtonY();
		CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, * fp;
		f.CreatePointFont(120, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(230, 220, 200));
		pDC->SetTextColor(RGB(0, 0, 0));
		char position[500];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(position, "TreeLeftX:%d TreeRightX:%d TreeTopY:%d TreeButtonY:%d TreeHp:%d"
			, GetLeftX(), GetRightX(), GetTopY(), GetButtonY(), GetCurrentHp());
		//sprintf(str, "CharacterLeftX : %d", CharacterLeftX);
		pDC->TextOut(200, 100, position);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}
}
