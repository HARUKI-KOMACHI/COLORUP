#define CONIOEX
#include "conioex.h"
#include "result.h"
#include "scene.h"
#include "score.h"
#include <iostream>

const char* s0[] =
{
	"　■■■",
	"■　　　■",
	"■　　　■",
	"■　　　■",
	"■　　　■",
	"■　　　■",
	"　■■■"
};

const char* s1[] =
{
	"　■■",
	"　　■",
	"　　■",
	"　　■",
	"　　■",
	"　　■",
	"　　■"
};

const char* s2[] =
{
	"　■■■　",
	"■　　　■",
	"　　　　■",
	"　　　■",
	"　　■",
	"　■",
	"■■■■■"
};

const char* s3[] =
{
	"　■■■",
	"■　　　■",
	"　　　　■",
	"　　■■",
	"　　　　■",
	"■　　　■",
	"　■■■"
};

const char* s4[] =
{
	"　　　　■",
	"　　　■■",
	"　　■　■",
	"　■　　■",
	"■■■■■■",
	"　　　　■",
	"　　　　■"
};

const char* s5[] =
{
	"■■■■■",
	"■",
	"■■■■",
	"　　　　■",
	"　　　　■",
	"■　　　■",
	"　■■■"
};

const char* s6[] =
{
	"　■■■　",
	"■　　　■",
	"■",
	"■■■■",
	"■　　　■",
	"■　　　■",
	"　■■■"
};

const char* s7[] =
{
	"■■■■■",
	"　　　 ■",
	"　　　■",
	"　　 ■",
	"　　■",
	"　 ■",
	"　■"
};

const char* s8[] =
{
	"　■■■",
	"■　　　■",
	"■　　　■",
	"　■■■",
	"■　　　■",
	"■　　　■",
	"　■■■"
};
const char* s9[] =
{
	"　■■■",
	"■　　　■",
	"■　　　■",
	"　■■■■",
	"　　　　■",
	"　　　　■",
	"　■■■"
};

const char** BigNum[] = { s0,s1,s2,s3,s4,s5,s6,s7,s8,s9 };


int nHundred, nTen, nOne;
bool bEndFlg;
int bDrawFlg;

void InitResult()
{
	SCORE* ptScore = GetScore();
	nHundred = ptScore->nPoint / 100;
	nTen = (ptScore->nPoint / 10) % 10;
	nOne = ptScore->nPoint % 10;
	bEndFlg = false;
	bDrawFlg = false;
}

void UninitResult()
{

}

void UpdateResult()
{
	if (inport(PK_BS) && bEndFlg)
	{
		SetScene(SCENE_TITLE);
	}

	if (inport(PK_ENTER))
	{
		clrscr();

		bEndFlg = true;
	}
}

void DrawResult()
{
	if (!bEndFlg)
	{
		textcolor(WHITE);
		for (int nCnt = 0; nCnt < 9; nCnt++)
		{
			gotoxy(22 + nCnt * 4, 5);
			printf("　─");
			gotoxy(22 + nCnt * 4, 14);
			printf("　─");
		}
		for (int nCnt = 0; nCnt < 7; nCnt++)
		{
			gotoxy(22, 6 + nCnt);
			if (nCnt % 2 == 0)
			{
				printf("|");
			}
			else
			{
				printf("　");
			}

			gotoxy(59, 6 + nCnt);
			if (nCnt % 2 == 0)
			{
				printf("|");
			}
			else
			{
				printf("　");
			}
		}
		gotoxy(26, 7);
		std::cout << "店内が満席になってしまったため、";
		gotoxy(26, 8);
		std::cout << "お客様が帰ってしまいました...";
		gotoxy(26, 12);
		std::cout << "あなたの接客ポイントは・・・";
		gotoxy(27, 20);
		std::cout << "＜＜　Press Enter Key　＞＞";

	}	
	else
	{
		for (int nCnt = 0; nCnt < 7; nCnt++)
		{
			gotoxy(20, 6+nCnt);
			std::cout << BigNum[nHundred][nCnt];
		}
		for (int nCnt = 0; nCnt < 7; nCnt++)
		{
			gotoxy(35, 6+nCnt);
			std::cout << BigNum[nTen][nCnt];
		}
		for (int nCnt = 0; nCnt < 7; nCnt++)
		{
			gotoxy(50, 6+nCnt);
			std::cout << BigNum[nOne][nCnt];
		}
		gotoxy(25, 20);
		std::cout << "＜＜　Press BackSpace Key　＞＞";
	}
}