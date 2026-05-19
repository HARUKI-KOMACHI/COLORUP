#define CONIOEX
#include "conioex.h"
#include "interact.h"
#include <iostream>

bool  PlayerInteractPaint(PLAYER* ptPlayer)
{
	PAINT* ptPaint = GetPaint();

	int nMojiBite = 2;
	for (int nCnt = 0; nCnt < PAINT_MAX; nCnt++, ptPaint++)
	{
		if (ptPlayer->fPosX == ptPaint->fPosX - (nMojiBite * 2) &&
			ptPlayer->fPosY == ptPaint->fPosY)
		{
			ptPlayer->nColor = ptPaint->nColor;
			return true;
		}
	}
	return false;
}

bool PlayerInteractField(PLAYER* ptPlayer)
{
	FIELD* ptField = GetField();

	int nMojiBite = 2;
	for (int nCnt = 0; nCnt < FIELD_MAX; nCnt++,ptField++)
	{
		if (ptPlayer->fPosX == ptField->fPosX + nMojiBite &&
			ptPlayer->fPosY == ptField->fPosY)
		{
			ptField->nColor = ptPlayer->nColor;
			ptField->bChange = true;
			return true;
		}
	}
	return false;
}

bool CustInteractGet(CUST* ptCust)
{
	FIELD* ptField = GetField();

	int nMojiBite = 2;
	for (int nCnt = 0; nCnt < FIELD_MAX; nCnt++, ptField++)
	{
		if (ptCust->fPosX == ptField->fPosX - (nMojiBite * 2) &&
			ptCust->fPosY == ptField->fPosY &&
			ptCust->nColor == ptField->nColor)
		{
			ptCust->bUse = false;
			ptField->nColor = DARKGRAY;
			ptField->bChange = true;
			return true;
		}
	}
	return false;
}

bool PlayerInteractMixSet(PLAYER* ptPlayer)
{
	MIX* ptMix = GetMix();

	int nMojiBite = 2;
	for (int nCnt = 0; nCnt < MIX_MAX; nCnt++, ptMix++)
	{
		if (ptPlayer->fPosX == ptMix->fPosX - (nMojiBite * 2) &&
			ptPlayer->fPosY == ptMix->fPosY)
		{
			if (ptPlayer->nColor == LIGHTRED ||
				ptPlayer->nColor == LIGHTBLUE ||
				ptPlayer->nColor == YELLOW ||
				ptPlayer->nColor == WHITE ||
				ptPlayer->nColor == GREEN)
			{
				if (!ptMix->bHave)
				{
					ptMix->nColor = ptPlayer->nColor;
					ptMix->bChange = true;
					ptMix->bHave = true;
					return true;
				}
				else 
				{
					if (ptMix->nColor == LIGHTRED)
					{
						switch (ptPlayer->nColor)
						{
						case LIGHTBLUE:
							ptMix->nColor = MAGENTA;
							return true;
						case WHITE:
							ptMix->nColor = LIGHTMAGENTA;
							return true;
						case LIGHTRED:
							ptMix->nColor = RED;
							return true;
						default:return false;
						}
					}

					if (ptMix->nColor == LIGHTBLUE)
					{
						switch (ptPlayer->nColor)
						{
						case LIGHTRED:
							ptMix->nColor = MAGENTA;
							return true;
						case WHITE:
							ptMix->nColor = LIGHTCYAN;
							return true;
						case GREEN:
							ptMix->nColor = CYAN;
							return true;
						case YELLOW:
							ptMix->nColor = GREEN;
							return true;
						case LIGHTBLUE:
							ptMix->nColor = BLUE;
							return true;
						default:return false;
						}
					}

					if (ptMix->nColor == YELLOW)
					{
						switch (ptPlayer->nColor)
						{
						case LIGHTBLUE:
							ptMix->nColor = GREEN;
							return true;
						case GREEN:
							ptMix->nColor = LIGHTGREEN;
							return true;
						case YELLOW:
							ptMix->nColor = BROWN;
							return true;
						default:return false;
						}
					}

					if (ptMix->nColor == WHITE)
					{
						switch (ptPlayer->nColor)
						{
						case LIGHTRED:
							ptMix->nColor = LIGHTMAGENTA;
							return true;
						case LIGHTBLUE:
							ptMix->nColor = LIGHTCYAN;
							return true;
						default:return false;
						}
					}

					if (ptMix->nColor == GREEN)
					{
						switch (ptPlayer->nColor)
						{
						case LIGHTBLUE:
							ptMix->nColor = CYAN;
							return true;
						case YELLOW:
							ptMix->nColor = LIGHTGREEN;
							return true;
						default:return false;
						}
					}
				}
			}
		}
	}
	return false;
}

bool PlayerInteractMixGet(PLAYER* ptPlayer)
{
	MIX* ptMix = GetMix();

	int nMojiBite = 2;
	for (int nCnt = 0; nCnt < MIX_MAX; nCnt++, ptMix++)
	{
		if (ptPlayer->fPosX == ptMix->fPosX - (nMojiBite * 2) &&
			ptPlayer->fPosY == ptMix->fPosY)
		{
			ptPlayer->nColor = ptMix->nColor;
			ptMix->nColor = DARKGRAY;
			ptMix->bChange = true;
			ptMix->bHave = false;
			return true;
		}
	}
	return false;
}