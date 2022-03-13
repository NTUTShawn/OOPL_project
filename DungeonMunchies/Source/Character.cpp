#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character.h"
#include "Map.h"

/////////////////////////////////////////////////////////////////////////////
// �o��class���C��������H������
/////////////////////////////////////////////////////////////////////////////
namespace game_framework {
    Character::Character() {
		Initialize();
		//characterX = characterY = 50;
    }

	int Character::GetLeftX()
	{
		return characterX;
	}

	int Character::GetTopY()
	{
		return characterY;
	}

	int Character::GetRightX()
	{
		return characterX + characterW; // + animation.Width();
	}

	int Character::GetButtonY()
	{
		return characterY + characterH; // + animation.Height();
	}

	void Character::Initialize()
	{
		characterH = 80;
		characterW = 80;
		const int X_POS = 80;													//����_�lX�b
		const int Y_POS = 100;													//����_�lY�b
		characterX = X_POS;
		characterY = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;

		isRising = false;
		floor = 320;
	}

	void Character::LoadBitmap()
	{
		//animation.AddBitmap(IDB_GRAY);
		animation.AddBitmap(IDB_MAINCHARACTERSTAND, RGB(255, 51, 255));
	}

	void Character::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Character::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Character::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Character::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void Character::OnMove(Map *m)
	{

		const int BORDER = 5;													//������ؼe��
		const int STEP_SIZE = 5;												//�}�Ⲿ�ʳt��
		animation.OnMove();
		if (isMovingLeft && m->isEmpty(GetLeftX() - STEP_SIZE, GetTopY()) && m->isEmpty(GetLeftX() - STEP_SIZE, GetButtonY() - BORDER))
		{
			if (m->getSX() > -230) 
			{
				characterX -= STEP_SIZE;
			}

			//m->addSX(STEP_SIZE);												//��������(��������)
		}
		if (isMovingRight && m->isEmpty(GetRightX() + STEP_SIZE - 5, GetTopY()) && m->isEmpty(GetRightX() - BORDER + STEP_SIZE, GetButtonY() - BORDER)) 
		{
			if (m->getSX() > -230) 
			{
				characterX += STEP_SIZE;
			}

			//m->addSX(-STEP_SIZE);                             	
		}
		if (isMovingUp && GetButtonY() >= floor && velocity == 0) {
			isRising = true;
			velocity = 10;
		}
		/*if (isMovingDown && !m->isEmpty(GetLeftX(), GetButtonY() + STEP_SIZE - 5) && !m->isEmpty(GetRightX() - 5, GetButtonY() + STEP_SIZE - 5)) {
			characterY += STEP_SIZE;
			m->addSY(-STEP_SIZE);
		}*/

		if (isRising)							// �W�ɪ��A	
		{						
			if (velocity > 0)
			{
				characterY -= velocity * 2;		// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity--;						// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else
			{
				isRising = false;				// ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;					// �U������t(velocity)��1
			}
		}
		else									// �U�����A
		{		
			if (characterY < floor)				// ��y�y���٨S�I��a�O
			{									
				characterY += velocity * 2;		// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				if (velocity < 5)
					velocity++;
			}
			else
			{
				characterY = floor;				// ��y�y�ЧC��a�O�A�󥿬��a�O�W
				velocity = 0;
			}
		}
		
	}

	void Character::SetXY(int x, int y)
	{
		characterX = x;
		characterY = y;
	}

	void Character::OnShow()
	{
		animation.SetTopLeft(characterX, characterY);
		animation.OnShow();
	}
}