#pragma once
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

//マクロ定義
#define CUST_MAX	9
#define CUST_START_POSX	1
#define CUST_START_POSY	10
#define CUST_SIZE	2
#define CUST_MOVE_SPEED_X	2
#define CUST_MOVE_SPEED_Y	1
#define CUST_FIRST_CURVE_POSX	5
#define COLOR_MAX	13

//客構造体
struct CUST
{
	float fPosX;
	float fPosY;
	float fPosOldX;
	float fPosOldY;
	int nColor;
	float fCurvePosY;

	bool bUse;
	bool bGet;
	bool bMove;

	int nFrameCounter;
};

//プロトタイプ宣言
void InitCust();
void UninitCust();
void UpdateCust();
void DrawCust();
CUST* GetCust();
void ColorCust(int CustNum);
void FirstDrawCust(int CustNum);
void ResetCust(int CustNum);
int CheckColorCust(int CustNum);
bool SceneCust();
#endif