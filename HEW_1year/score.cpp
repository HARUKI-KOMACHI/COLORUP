#define CONIOEX
#include "conioex.h"
#include "score.h"
#include <iostream>

SCORE g_tScore;

void InitScore()
{
	memset(&g_tScore, 0, sizeof(SCORE));
}

void UninitScore()
{

}

void UpdateScore()
{

}

void DrawScore()
{
	gotoxy(3, 23);
	textcolor(WHITE);
	std::cout << "接客ポイント：" << g_tScore.nPoint;
}

void AddScore(int nPoint)
{
	g_tScore.nPoint += nPoint;
}

SCORE* GetScore()
{
	return &g_tScore;
}