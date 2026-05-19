#define CONIOEX
#include "conioex.h"
#include "mix.h"
#include "game.h"
#include <iostream>

#define MIX_POSX (SCREEN_RIGHT-3)

MIX g_tMix[MIX_MAX];

//ç\ë¢ëÃçƒï`âÊ
bool g_bUpdateMixFlg;

struct MixData
{
	float fX, fY;
};

MixData g_tMixTable[] =
{
	{MIX_POSX,2},
	{MIX_POSX,17},
};

void InitMix()
{
	memset(&g_tMix[0], 0, sizeof(MIX) * MIX_MAX);

	for (int nCnt = 0; nCnt < MIX_MAX; nCnt++)
	{
		CreateMix(g_tMixTable[nCnt].fX,g_tMixTable[nCnt].fY);
	}

	g_bUpdateMixFlg = true;
}

void UninitMix()
{

}

void UpdateMix()
{

}

void DrawMix()
{
	if (g_bUpdateMixFlg)
	{
		UpdateDrawMix();
		g_bUpdateMixFlg = false;
	}
	else
	{
		for (int nCnt = 0; nCnt < MIX_MAX; nCnt++)
		{
			if (g_tMix[nCnt].bChange)
			{
				int nHeight$ = 2;
				textcolor(g_tMix[nCnt].nColor);
				for (int nHeight = 0; nHeight < nHeight$; nHeight++)
				{
					gotoxy(g_tMix[nCnt].fPosX, g_tMix[nCnt].fPosY + nHeight);
					printf("Åô");
				}
			}
		}
	}
}

void UpdateDrawMix()
{
	for (int nCnt = 0; nCnt < MIX_MAX; nCnt++)
	{
		if (g_tMix[nCnt].bUse)
		{
			int nHeight$ = 2;
			textcolor(g_tMix[nCnt].nColor);
			for (int nHeight = 0; nHeight < nHeight$; nHeight++)
			{
				gotoxy(g_tMix[nCnt].fPosX, g_tMix[nCnt].fPosY + nHeight);
				printf("Åô");
			}
		}
	}
}

void CreateMix(float fX, float fY)
{
	for (int nCnt = 0; nCnt < MIX_MAX; nCnt++)
	{
		if (g_tMix[nCnt].bUse == false)
		{
			g_tMix[nCnt].fPosX = fX;
			g_tMix[nCnt].fPosY = fY;
			g_tMix[nCnt].nColor = DARKGRAY;
			g_tMix[nCnt].bUse = true;

			break;
		}
	}
}

MIX* GetMix()
{
	return &g_tMix[0];
}