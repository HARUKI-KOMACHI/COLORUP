#define CONIOEX
#include "conioex.h"
#include "information.h"
#include "game.h"
#include <iostream>

void InitInfo()
{
	
}

void UninitInfo()
{

}

void UpdateInfo()
{

}

void DrawInfo()
{	
	int nX = SCREEN_RIGHT + 2;
	textcolor(WHITE);
	gotoxy(nX, SCREEN_TOP);
	std::cout << "[ F‡¬ˆê—— ]";
	textcolor(LIGHTRED);
	gotoxy(nX, SCREEN_TOP + 1);
	printf("œ");
	gotoxy(nX, SCREEN_TOP + 3);
	printf("œ");
	gotoxy(nX, SCREEN_TOP + 13);
	printf("œ");
	gotoxy(nX + 6, SCREEN_TOP + 13);
	printf("œ");

	textcolor(LIGHTBLUE);
	gotoxy(nX + 6, SCREEN_TOP + 1);
	printf("œ");
	gotoxy(nX, SCREEN_TOP + 5);
	printf("œ");
	gotoxy(nX, SCREEN_TOP + 7);
	printf("œ");
	gotoxy(nX, SCREEN_TOP + 9);
	printf("œ");
	gotoxy(nX, SCREEN_TOP + 15);
	printf("œ");
	gotoxy(nX + 6, SCREEN_TOP + 15);
	printf("œ");
	
	textcolor(YELLOW);
	gotoxy(nX + 6, SCREEN_TOP + 9);
	printf("œ");
	gotoxy(nX + 6, SCREEN_TOP + 11);
	printf("œ");
	gotoxy(nX, SCREEN_TOP + 17);
	printf("œ"); 
	gotoxy(nX + 6, SCREEN_TOP + 17);
	printf("œ");

	textcolor(WHITE);
	gotoxy(nX + 6, SCREEN_TOP + 3);
	printf("œ");
	gotoxy(nX + 6, SCREEN_TOP + 5);
	printf("œ");

	textcolor(GREEN);
	gotoxy(nX + 6, SCREEN_TOP + 7);
	printf("œ"); 
	gotoxy(nX + 12, SCREEN_TOP + 9);
	printf("œ");
	gotoxy(nX, SCREEN_TOP + 11);
	printf("œ");

	textcolor(MAGENTA);
	gotoxy(nX + 12, SCREEN_TOP + 1);
	printf("œ");

	textcolor(LIGHTMAGENTA);
	gotoxy(nX + 12, SCREEN_TOP + 3);
	printf("œ");

	textcolor(LIGHTCYAN);
	gotoxy(nX + 12, SCREEN_TOP + 5);
	printf("œ");

	textcolor(CYAN);
	gotoxy(nX + 12, SCREEN_TOP + 7);
	printf("œ");

	textcolor(LIGHTGREEN);
	gotoxy(nX + 12, SCREEN_TOP + 11);
	printf("œ");

	textcolor(RED);
	gotoxy(nX + 12, SCREEN_TOP + 13);
	printf("œ");

	textcolor(BLUE);
	gotoxy(nX + 12, SCREEN_TOP + 15);
	printf("œ");

	textcolor(BROWN);
	gotoxy(nX + 12, SCREEN_TOP + 17);
	printf("œ");

	textcolor(WHITE);
	for (int nCnt = SCREEN_TOP; nCnt < 10; nCnt++)
	{
		gotoxy(nX + 3, nCnt*2);
		printf("{");
		gotoxy(nX + 9, nCnt*2);
		printf("");
	}
}