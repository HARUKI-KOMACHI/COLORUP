#pragma once
//マクロ定義
#define FIELD_MAX	40//障害物の最大値

struct FIELD
{
	float fPosX;	//X座標
	float fPosY;	//Y座標
	int nColor;

	bool bChange;
	bool bUse;
};

//プロトタイプ宣言
void InitField();
void UninitField();
void UpdateField();
void DrawField();
FIELD* GetField();

void UpdateDrawField();
void CreateField(float fX, float fY);
