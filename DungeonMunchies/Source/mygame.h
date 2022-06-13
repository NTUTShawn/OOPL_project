/*
 * mygame.h: ���ɮ��x�C��������class��interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "Character.h"
#include "Map.h"
#include "MapForBoss.h"
#include "MapS1.h"
#include "MapS2.h"
#include "MapS3.h"
#include "MapS4.h"
#include "MapS5.h"
#include "MapS6.h"
#include "Util.h"
#include "PropsBook.h"
#include "CharacterStatus.h"
#include "Monster.h"
#include "MonsterCactus.h"
#include "MonsterCactusMutation.h"
#include "MonsterBanana.h"
#include "MonsterShrimp.h"
#include "MonsterTree.h"
#include "MonsterMosquito.h"
#include "MonsterBoss.h"

namespace game_framework
{
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState
	{
	public:
		CGameStateInit(CGame* g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
	protected:
		void isChoiceChange();
		void OnMove();
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void instructionsPageShow();
	private:
		bool isMouseOnArrowR(CPoint point);
		bool isMouseOnArrowL(CPoint point);
		BeginningStage stage;
		InstructionsPage instructionsPage;
		int record; //1�N��instructionsPage�Ĥ@���A2�N��ĤG��
		CMovingBitmap startMenu;
		CMovingBitmap startMenuChoice;
		CMovingBitmap staff;
		CMovingBitmap instructionsPage01;
		CMovingBitmap instructionsPage02;
		CMovingBitmap instructionsPage03;
		CMovingBitmap instructionsPageC;
		CMovingBitmap whiteX;
		CMovingBitmap arrowL;
		CMovingBitmap arrowR;
		int choice;
		int lastChoice;
		int yChoice;
		bool onChoice;
		bool isMouseOnX;
		bool isArrowLShow;
		bool isArrowRShow;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState
	{
	public:
		CGameStateRun(CGame* g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void LightBulbOnShow();
		void ShowData();
		void monsterInitialize();
	private:
		void gameCompleteNoteShow();
		void bgmPlayer();
		void stopAllBgm();
		Map* GetCurrentMap();
		//CMovingBitmap	monster;
		Character		character;
		MapForBoss		bossMap;
		MapS1 mapS1;
		MapS2 mapS2;
		MapS3 mapS3;
		MapS4 mapS4;
		MapS5 mapS5;
		MapS6 mapS6;
		PropsBook		propsBook;
		CharacterStatus characterStatus;
		Stage currentStage;
		Stage lastStage;
		bool characterStatusCall;
		bool haveCalledCharacterStatus;
		bool gamePause;
		vector<Monster*> monsterS1;
		vector<Monster*> monsterS2;
		vector<Monster*> monsterS3;
		vector<Monster*> monsterS4;
		vector<Monster*> monsterS5;
		vector<Monster*> monsterS6;
		vector<Monster*> monsterS7;

		bool messageShowFlag;


		CPoint mousePosition;
		CMovingBitmap lightBulb;
		CMovingBitmap gameComplete;
		bool gameCompleteFlag;
		bool isStageChanged; //for bmgPlayer
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState
	{
	public:
		CGameStateOver(CGame* g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�
		bool isBgmPlayed;
		CMovingBitmap gameOver;
	};
}