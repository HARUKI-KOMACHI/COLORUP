#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

//マクロ定義
#define PLAYER_MOVE_SPEED_X 2
#define PLAYER_MOVE_SPEED_Y 1
#define PLAYER_MOVE_DELAY	5

struct PLAYER
{

	float fPosX;//現在X
	float fPosY;//現在Y
	float fPosOldX;//過去X
	float fPosOldY;//過去Y
	float fSpeedX;//移動量X
	float fSpeedY;//移動量Y
	float fDirect;//向き

	bool bHave;//物を持っているか
	int nColor;//色

	float fFrameCounter;
};

//プロトタイプ宣言
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

#endif