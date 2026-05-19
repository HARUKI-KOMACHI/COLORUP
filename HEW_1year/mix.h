#pragma once
#ifndef _MIX_H_
#define _MIX_H_

#define MIX_MAX	2

struct MIX
{
	float fPosX;
	float fPosY;
	int nColor;
	bool bUse;
	bool bChange;
	bool bHave;
};

void InitMix();
void UninitMix();
void UpdateMix();
void DrawMix();

void UpdateDrawMix();
void CreateMix(float fX, float fY);
MIX* GetMix();
#endif