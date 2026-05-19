#define CONIOEX
#include "conioex.h"
#include "scene.h"
#include "title.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

const char* sCmoji[] =
{
	"  ■■■■",
	"■        ■",
	"■",
	"■",
	"■",
	"■        ■",
	"  ■■■■"
};

const char* sOmoji[] =
{
	"    ■■■",
	"  ■      ■",
	"■          ■",
	"■          ■",
	"■          ■",
	"  ■      ■",
	"    ■■■"
};

const char* sLmoji[] =
{
	"■",
	"■",
	"■",
	"■",
	"■",
	"■",
	"■■■■■"
};

const char* sRmoji[] =
{
	"■■■■",
	"■      ■",
	"■      ■",
	"■■■■",
	"■    ■",
	"■      ■",
	"■        ■"
};

const char* sUmoji[] =
{

	"■        ■",
	"■        ■",
	"■        ■",
	"■        ■",
	"■        ■",
	"■        ■",
	"  ■■■■"
};

const char* sPmoji[] =
{
	"■■■■",
	"■      ■",
	"■      ■",
	"■■■■",
	"■",
	"■",
	"■"
};

const char* sMark[] =
{
	"■",
	"■",
	"■",
	"■",
	"■",
	"",
	"■",
};

MOJI g_tMoji[MOJI_NUM];

void InitTitle()
{
	memset(&g_tMoji[0], 0, sizeof(MOJI) * MOJI_NUM);
	srand((unsigned int)time(NULL));

	for (int nCnt = 0; nCnt < MOJI_NUM; nCnt++)
	{
		int nNum;
		bool bLoop = true;
		do
		{
			nNum = rand() % 15 + 1;
			if (nNum != 7 && nNum != 8)
			{
				g_tMoji[nCnt].nColor = nNum;
				bLoop = false;
			}

		} while (bLoop);
	}
}

void UninitTitle()
{

}

void UpdateTitle()
{
	if (inport(PK_ENTER))
	{
		//シーンをゲーム本編へ移行させる
		SetScene(SCENE_GAME);
	}
}

void DrawTitle()
{
	int nStartX = 3;
	int nStartY = 2;
	textcolor(g_tMoji[0].nColor);
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		gotoxy(nStartX, nStartY + nCnt);
		std::cout << sCmoji[nCnt];
	}

	nStartX = 16;
	textcolor(g_tMoji[1].nColor);
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		gotoxy(nStartX, nStartY + nCnt);
		std::cout << sOmoji[nCnt];
	}

	nStartX = 31;
	textcolor(g_tMoji[2].nColor);
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		gotoxy(nStartX, nStartY + nCnt);
		std::cout << sLmoji[nCnt];
	}

	nStartX = 42;
	textcolor(g_tMoji[3].nColor);
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		gotoxy(nStartX, nStartY + nCnt);
		std::cout << sOmoji[nCnt];
	}

	nStartX = 57;
	textcolor(g_tMoji[4].nColor);
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		gotoxy(nStartX, nStartY + nCnt);
		std::cout << sRmoji[nCnt];
	}

	nStartY = 11;
	nStartX = 50;
	textcolor(g_tMoji[5].nColor);
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		gotoxy(nStartX, nStartY + nCnt);
		std::cout << sUmoji[nCnt];
	}

	nStartX = 64;
	textcolor(g_tMoji[6].nColor);
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		gotoxy(nStartX, nStartY + nCnt);
		std::cout << sPmoji[nCnt];
	}

	nStartX = 76;
	textcolor(g_tMoji[7].nColor);
	for (int nCnt = 0; nCnt < 7; nCnt++)
	{
		gotoxy(nStartX, nStartY + nCnt);
		std::cout << sMark[nCnt];
	}

	textcolor(WHITE);
	gotoxy(22, 21);
	std::cout << "＜＜　Press Enter Key to Start　＞＞";
}