#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_

struct SCORE
{
	int nPoint;
};

void InitScore();
void UninitScore();
void UpdateScore();
void DrawScore();

void AddScore(int nPoint);
SCORE* GetScore();

#endif 