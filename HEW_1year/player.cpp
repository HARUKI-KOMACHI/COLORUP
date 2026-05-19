#define CONIOEX
#include "conioex.h"
#include "player.h"
#include "game.h"
#include "paint.h"
#include "interact.h"
#include <iostream>

//グローバル変数
PLAYER g_tPlayer;
float fMoveDelay;//入力遅延
bool bInport;

//初期化処理
void InitPlayer()
{
	memset(&g_tPlayer, 0, sizeof(PLAYER));
	g_tPlayer.fPosX = g_tPlayer.fPosOldX = 31;//X座標　※絶対奇数スタート！
	g_tPlayer.fPosY = g_tPlayer.fPosOldY = 10;//Y座標
	g_tPlayer.nColor = DARKGRAY;
	fMoveDelay = PLAYER_MOVE_DELAY;
	bInport = false;
}

//終了処理
void UninitPlayer() 
{

}

//更新処理
void UpdatePlayer()
{
	//現在の座標位置の保存をする
	g_tPlayer.fPosOldX = (int)g_tPlayer.fPosX;
	g_tPlayer.fPosOldY = (int)g_tPlayer.fPosY;

	//移動量のリセット
	g_tPlayer.fSpeedX = 0;
	g_tPlayer.fSpeedY = 0;

	//WASDの入力で移動する
	if (g_tPlayer.fFrameCounter >= fMoveDelay)//秒ごとに移動
	{
		if (inport(PK_W))
		{
			g_tPlayer.fSpeedY = -PLAYER_MOVE_SPEED_Y;
		}
		if (inport(PK_S))
		{
			g_tPlayer.fSpeedY = PLAYER_MOVE_SPEED_Y;
		}
		if (inport(PK_A))
		{
			g_tPlayer.fSpeedX = -PLAYER_MOVE_SPEED_X;
		}
		if (inport(PK_D))
		{
			g_tPlayer.fSpeedX = PLAYER_MOVE_SPEED_X;
		}
	}
	g_tPlayer.fFrameCounter++;

	if (g_tPlayer.fSpeedX != 0||g_tPlayer.fSpeedY != 0)
	{
		g_tPlayer.fFrameCounter = 0;
	}

	if (inport(PK_SP))
	{
		if (!bInport)
		{
			if (g_tPlayer.bHave)
			{
				if (PlayerInteractField(&g_tPlayer))
				{
					g_tPlayer.nColor = DARKGRAY;
					g_tPlayer.bHave = false;
				}

				if (PlayerInteractMixSet(&g_tPlayer))
				{
					g_tPlayer.nColor = DARKGRAY;
					g_tPlayer.bHave = false;
				}
			}
			else
			{
				if (PlayerInteractPaint(&g_tPlayer))
				{
					g_tPlayer.bHave = true;
				}

				if (PlayerInteractMixGet(&g_tPlayer))
				{
					g_tPlayer.bHave = true;
				}
			}
		}
		bInport = true;
	}
	else
	{
		bInport = false;
	}

	//座標更新
	g_tPlayer.fPosX += g_tPlayer.fSpeedX;
	g_tPlayer.fPosY += g_tPlayer.fSpeedY;

	//座標制御
	if (g_tPlayer.fPosX > SCREEN_RIGHT-7)
	{
		g_tPlayer.fPosX = SCREEN_RIGHT - 7;
	}
	if (g_tPlayer.fPosX < SCREEN_RIGHT / 2 + 1)
	{
		g_tPlayer.fPosX = SCREEN_RIGHT / 2 + 1;
	}
	if (g_tPlayer.fPosY > SCREEN_BOTTOM-2)
	{
		g_tPlayer.fPosY = SCREEN_BOTTOM - 2;
	}
	if (g_tPlayer.fPosY < SCREEN_TOP+1)
	{
		g_tPlayer.fPosY = SCREEN_TOP + 1;
	}
}

void DrawPlayer()
{
	int nMojiBite = 2;
	//座標が変化していた場合、過去の座標を消去する
	if ((g_tPlayer.fPosX != g_tPlayer.fPosOldX) ||
		(g_tPlayer.fPosY != g_tPlayer.fPosOldY))
	{
		for (int nCnt = 0; nCnt < nMojiBite; nCnt++)
		{
			gotoxy((int)g_tPlayer.fPosOldX, (int)g_tPlayer.fPosOldY + nCnt);
			printf("    ");
		}
	}
	//キャラクター
	textcolor(g_tPlayer.nColor);
	for (int nCnt = 0; nCnt < nMojiBite; nCnt++)
	{
		gotoxy((int)g_tPlayer.fPosX, (int)g_tPlayer.fPosY + nCnt);
		printf("●●");
	}
}
