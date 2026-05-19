#define CONIOEX
#include "conioex.h"
#include "game.h"
#include "paint.h"
#include <iostream>

//マクロ定義
#define PAINT_POSX (SCREEN_RIGHT-3)

//グローバル変数
PAINT g_tPaint[PAINT_MAX];

//初期配置　構造体
struct PaintData
{
	float fX, fY;
	int nColor;
};

//データテーブル
PaintData g_tPaintTable[] =
{
	{PAINT_POSX, 5, LIGHTRED},
	{PAINT_POSX, 8, LIGHTBLUE},
	{PAINT_POSX, 11, YELLOW},
	{PAINT_POSX, 14, WHITE},
};

//初期化処理
void InitPaint()
{
	memset(&g_tPaint[0], 0, sizeof(PAINT) * PAINT_MAX);

	for (int nCnt = 0; nCnt < PAINT_MAX; nCnt++)
	{
		CreatePaint(g_tPaintTable[nCnt].fX, g_tPaintTable[nCnt].fY, g_tPaintTable[nCnt].nColor);
	}
}

//終了処理
void UninitPaint()
{

}

//更新処理
void UpdatePaint()
{

}

//描画処理
void DrawPaint()
{
	for (int nCnt = 0; nCnt < PAINT_MAX; nCnt++)
	{
		if (g_tPaint[nCnt].bUse == true)
		{
			textcolor(g_tPaint[nCnt].nColor);
			gotoxy((int)g_tPaint[nCnt].fPosX, (int)g_tPaint[nCnt].fPosY);
			printf("◆");
			gotoxy((int)g_tPaint[nCnt].fPosX, (int)g_tPaint[nCnt].fPosY+1);
			printf("◆");
		}
	}
}

//生成処理
void CreatePaint(float fX,float fY,int nColor)
{
	for (int nCnt = 0; nCnt < PAINT_MAX; nCnt++)
	{
		if (g_tPaint[nCnt].bUse == false)
		{
			g_tPaint[nCnt].fPosX = fX;
			g_tPaint[nCnt].fPosY = fY;
			g_tPaint[nCnt].nColor = nColor;
			g_tPaint[nCnt].bUse = true;

			break;
		}
	}
}

PAINT* GetPaint()
{
	return &g_tPaint[0];
}