#define CONIOEX
#include "conioex.h"
#include "game.h"
#include "field.h"
#include <iostream>

//障害物の構造体配列
FIELD g_tField[FIELD_MAX];

//構造体再描画
bool g_bUpdateFieldFlg;

//初期化処理
void InitField()
{
	memset(&g_tField[0], 0, sizeof(FIELD) * FIELD_MAX);
	/*for (int nCnt = 0; nCnt < FIELD_MAX; nCnt++)
	{
		g_tField[nCnt].fPosX = 0.0;
		g_tField[nCnt].fPosY = 0.0;
		g_tField[nCnt].nColor = DARKGRAY;
		g_tField[nCnt].bChange = false;
		g_tField[nCnt].bUse = false;
	}*/

	for (int nCnt = SCREEN_TOP; nCnt < SCREEN_BOTTOM - 1; nCnt+=2)
	{
		CreateField(SCREEN_RIGHT / 2 - 1, nCnt + 1);
	}

	g_bUpdateFieldFlg = true;
}

//終了処理
void UninitField()
{

}

//更新処理
void UpdateField()
{
	
}

//描画処理
void DrawField()
{
	//描画高速表示対応
	if (g_bUpdateFieldFlg)
	{
		//Field全描画
		UpdateDrawField();
		g_bUpdateFieldFlg = false;
	}
	else
	{
		for (int nCnt = 0; nCnt < FIELD_MAX; nCnt++) 
		{
			if (g_tField[nCnt].bChange)
			{
				int nHeight$ = 2;
				textcolor(g_tField[nCnt].nColor);
				for (int nHeight = 0; nHeight < nHeight$; nHeight++)
				{
					if (nCnt % 2 == 0)
					{
						gotoxy(g_tField[nCnt].fPosX, g_tField[nCnt].fPosY + nHeight);
						printf("〇");
					}
					else
					{
						gotoxy(g_tField[nCnt].fPosX, g_tField[nCnt].fPosY + nHeight);
						printf("□");
					}
				}
				g_tField[nCnt].bChange = false;
			}
		}
	}
}

void UpdateDrawField()
{
	//色設定
	textcolor(LIGHTGRAY);

	//外枠の表示
	gotoxy(SCREEN_LEFT, SCREEN_TOP);
	for (int nCnt = SCREEN_LEFT - 2; nCnt < SCREEN_RIGHT / 2; nCnt++)
	{
		printf("■");
	}
	for (int nCnt = SCREEN_TOP + 1; nCnt < SCREEN_BOTTOM; nCnt++)
	{
		gotoxy(SCREEN_LEFT, nCnt);
		printf("■");
		gotoxy(SCREEN_RIGHT - 1, nCnt);
		printf("■");
		if (nCnt == 10||nCnt==11)
		{
			gotoxy(SCREEN_LEFT, nCnt);
			printf("  ");
		}
	}
	gotoxy(SCREEN_LEFT, SCREEN_BOTTOM);
	for (int nCnt = SCREEN_LEFT - 2; nCnt < SCREEN_RIGHT / 2; nCnt++)
	{
		printf("■");
	}
	for (int nCnt = 0; nCnt < FIELD_MAX; nCnt++)
	{
		if (g_tField[nCnt].bUse)
		{
			int nHeight$ = 2;
			textcolor(g_tField[nCnt].nColor);
			for (int nHeight = 0; nHeight < nHeight$; nHeight++)
			{
				if (nCnt % 2 == 0)
				{
					gotoxy(g_tField[nCnt].fPosX, g_tField[nCnt].fPosY + nHeight);
					printf("〇");
				}
				else
				{
					gotoxy(g_tField[nCnt].fPosX, g_tField[nCnt].fPosY + nHeight);
					printf("□");
				}
			}
		}
	}
}

void CreateField(float fX, float fY)
{
	for (int nCnt = 0; nCnt < FIELD_MAX; nCnt++)
	{
		if (g_tField[nCnt].bUse == false)
		{
			g_tField[nCnt].fPosX = fX;
			g_tField[nCnt].fPosY = fY;
			g_tField[nCnt].nColor = DARKGRAY;
			g_tField[nCnt].bUse = true;

			break;
		}
	}
}


FIELD* GetField()
{
	return &g_tField[0];
}