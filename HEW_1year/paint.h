#pragma once
#ifndef _PAINT_H_
#define _PAINT_H_

//マクロ定義
#define PAINT_MAX	4

//カラーオブジェクト構造体
struct PAINT
{
	float fPosX;
	float fPosY;
	int nColor;

	bool bUse;
};

//プロトタイプ宣言
void InitPaint();
void UninitPaint();
void UpdatePaint();
void DrawPaint();

void CreatePaint(float fX, float fY, int nColor);

PAINT* GetPaint();
#endif