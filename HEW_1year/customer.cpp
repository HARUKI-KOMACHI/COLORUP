#define CONIOEX
#include "conioex.h"
#include "customer.h"
#include "game.h"
#include "interact.h"
#include "score.h"
#include "scene.h"
#include <iostream>
#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>

//マクロ定義
#define CUST_STOP_POSX	(SCREEN_RIGHT / 2 - 5)

//グローバル関数
CUST g_tCust[CUST_MAX];

//グローバル変数
std::chrono::steady_clock::time_point LastSpawnTime;
double dSpawnInterval;
int nSpawnCount;

std::vector<std::string>sColorNum = { "12","9","14","15","5","13","11","3","2","10","4","1","6" };

//初期化処理
void InitCust()
{
	memset(&g_tCust[0], 0, sizeof(CUST) * CUST_MAX);
	LastSpawnTime = std::chrono::steady_clock::now();
	dSpawnInterval = 4.5;
	nSpawnCount = 0;
	srand((unsigned int)time(NULL));
}

//終了処理
void UninitCust()
{

}

//更新処理
void UpdateCust()
{
	//一定時間後に出現
	auto NowTime = std::chrono::steady_clock::now();//現在時間
	//最後にスポーンした時間から経過時間を計算
	double dElapsed = std::chrono::duration<double>(NowTime - LastSpawnTime).count();

	if (dElapsed >= dSpawnInterval)//経過時間>=インターバル
	{
		bool bLoop = false;
		for (int nCnt = 0; nCnt < CUST_MAX; nCnt++)
		{
			if (!g_tCust[nCnt].bUse)
			{
				bLoop = true;
				break;
			}
		}
		do
		{
			int nCustNum = rand() % CUST_MAX;
			if (g_tCust[nCustNum].bUse == false)
			{
				g_tCust[nCustNum].bUse = true;
				g_tCust[nCustNum].bMove = true;
				ColorCust(nCustNum);
				FirstDrawCust(nCustNum);
				LastSpawnTime = NowTime;
				nSpawnCount++;
				bLoop = false;
			}

		} while (bLoop);
	}

	if (nSpawnCount == 5)
	{
		dSpawnInterval -= 0.1;
		nSpawnCount = 0;
	}

#ifdef _DEBUG
	textcolor(WHITE);
	gotoxy(1, 25);
	std::cout << "スポーンインターバル：" << dSpawnInterval;
#endif

	//移動制御
	int nMoveDelay = 10;
	for (int nCnt = 0; nCnt<CUST_MAX; nCnt++)
	{
		if (g_tCust[nCnt].bUse)
		{
			if (g_tCust[nCnt].bMove)
			{
				if (g_tCust[nCnt].nFrameCounter == nMoveDelay)//1/6s一回
				{
					g_tCust[nCnt].fPosOldX = (int)g_tCust[nCnt].fPosX;
					g_tCust[nCnt].fPosOldY = (int)g_tCust[nCnt].fPosY;

					if (g_tCust[nCnt].fPosX < CUST_FIRST_CURVE_POSX)
					{
						g_tCust[nCnt].fPosX += CUST_MOVE_SPEED_X;
					}
					else
					{
						if (g_tCust[nCnt].fPosY != g_tCust[nCnt].fCurvePosY)
						{
							if (g_tCust[nCnt].fCurvePosY < CUST_START_POSY)
							{
								g_tCust[nCnt].fPosY -= CUST_MOVE_SPEED_Y;
							}
							else
							{
								g_tCust[nCnt].fPosY += CUST_MOVE_SPEED_Y;
							}
						}
						else
						{
							if (g_tCust[nCnt].fPosX != CUST_STOP_POSX)
							{
								g_tCust[nCnt].fPosX += CUST_MOVE_SPEED_X;
							}
						}
					}

					g_tCust[nCnt].nFrameCounter = 0;
				}
				else
				{
					g_tCust[nCnt].nFrameCounter++;
				}
			}

			if (CustInteractGet(&g_tCust[nCnt]))
			{
				int nNum = CheckColorCust(nCnt);
				AddScore(nNum);
				ResetCust(nCnt);
			}

		}
	}

	if (SceneCust())
	{
		SetScene(SCENE_RESULT);
	}
}

//描画処理
void DrawCust()
{
	for (int nCnt = 0; nCnt < CUST_MAX; nCnt++)
	{
		if (g_tCust[nCnt].bUse)
		{
			int nMojiBite = 2;
			if (g_tCust[nCnt].bMove)
			{
				if (g_tCust[nCnt].fPosX != g_tCust[nCnt].fPosOldX ||
					g_tCust[nCnt].fPosY != g_tCust[nCnt].fPosOldY)
				{
					for (int nCnt$ = 0; nCnt$ < nMojiBite; nCnt$++)
					{
						gotoxy((int)g_tCust[nCnt].fPosOldX, (int)g_tCust[nCnt].fPosOldY + nCnt$);
						printf("    ");
					}
				}
			}

			for (int nCnt$ = 0; nCnt$ < nMojiBite; nCnt$++)
			{
				textcolor(g_tCust[nCnt].nColor);
				gotoxy((int)g_tCust[nCnt].fPosX, (int)g_tCust[nCnt].fPosY + nCnt$);
				printf("●●");
			}

			if (g_tCust[nCnt].fPosX == CUST_STOP_POSX)
			{
				g_tCust[nCnt].bMove = false;
			}
		}
	}
}

//CUST* GetCust()
//{
//	return &g_tCust[0];
//}

void ColorCust(int CustNum)
{
	int nSpawnColor = COLOR_MAX;
	if (dSpawnInterval >= 4.3)
	{
		nSpawnColor = 4;
	}
	int nNum = rand() % nSpawnColor;
	int nColor = std::stoi(sColorNum[nNum]);
	g_tCust[CustNum].nColor = nColor;

}

void FirstDrawCust(int CustNum)
{
	g_tCust[CustNum].fPosX = g_tCust[CustNum].fPosOldX = CUST_START_POSX;
	g_tCust[CustNum].fPosY = g_tCust[CustNum].fPosOldY = CUST_START_POSY;
	g_tCust[CustNum].fCurvePosY = CustNum * CUST_SIZE + 2;
}

void ResetCust(int CustNum)
{
	int nMojiBite = 2;
	for (int nCnt = 0; nCnt < nMojiBite; nCnt++)
	{
		gotoxy(g_tCust[CustNum].fPosX - nMojiBite, g_tCust[CustNum].fPosY + nCnt);
		printf("      ");
	}
	memset(&g_tCust[CustNum], 0, sizeof(CUST));
}

int CheckColorCust(int CustNum)
{
	for (int nCnt = 0; nCnt < COLOR_MAX; nCnt++)
	{
		if (g_tCust[CustNum].nColor == std::stoi(sColorNum[nCnt]))
		{
			if (std::stoi(sColorNum[nCnt])==3||
				std::stoi(sColorNum[nCnt])==10)
			{
				return 3;
			}
			else if (std::stoi(sColorNum[nCnt]) == 9 ||
				std::stoi(sColorNum[nCnt]) == 12 ||
				std::stoi(sColorNum[nCnt]) == 14 ||
				std::stoi(sColorNum[nCnt]) == 15)
			{
				return 1;
			}
			else
			{
				return 2;
			}
			break;
		}
	}
}
bool SceneCust()
{
	for (const auto Cust : g_tCust)
	{
		if (!Cust.bUse)return false;
	}

	int nResult = false;
	for (const auto Cust : g_tCust)
	{
		nResult |= Cust.bMove;
	}

	return !nResult;
}