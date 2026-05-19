#define CONIOEX
#include "conioex.h"
#include "scene.h"
#include "game.h"
#include "player.h"
#include "field.h"
#include "paint.h"
#include "customer.h"
#include "score.h"
#include "mix.h"
#include "information.h"
#include <iostream>

void InitGame()
{
	InitPlayer();
	InitPaint();
	InitField();
	InitCust();
	InitScore();
	InitMix();
	InitInfo();
}

void UninitGame()
{
	UninitPlayer();
	UninitPaint();
	UninitField();
	UninitCust();
	UninitScore();
	UninitMix();
	UninitInfo();
}

void UpdateGame()
{
	UpdatePlayer();
	UpdatePaint();
	UpdateField();
	UpdateCust();
	UpdateScore();
	UpdateMix();
	UpdateInfo();
}

void DrawGame()
{
	DrawPlayer();
	DrawPaint();
	DrawField();
	DrawCust();
	DrawScore();
	DrawMix();
	DrawInfo();
}