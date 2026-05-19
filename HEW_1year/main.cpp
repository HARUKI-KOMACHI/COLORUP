#include "conioex.h"
#include "scene.h"
#include <iostream>

#if defined(_WIN64) || defined(_M_X64)
#ifndef _DEBUG
#define show 0
#pragma comment(lib, "./Library/HEW_x64_Release.lib")
#else
#define show 1
#pragma comment(lib, "./Library/HEW_x64_Debug.lib")
#endif

#elif defined(_WIN32) || defined(_M_IX86)
#ifndef _DEBUG
#define show 0
#pragma comment(lib, "./Library/HEW_x86_Release.lib")
#else
#define show 1
#pragma comment(lib, "./Library/HEW_x86_Debug.lib")
#endif
#endif

//マクロ定義
#define DEBUG_TIMER (500)	// デバッグ表示の間隔 500ms
#define WINDOWPOS_X (275)	// ウィンドウの初期位置
#define WINDOWPOS_Y (100)	// ウィンドウの初期位置

//プロトタイプ宣言
bool HEWStartup();
bool HEWCleanup();

void Initialize();	//初期化
void Uninit();		//終了処理
void Update();		//更新
void Draw();		//描画

void WindowConsoleInitialize(void);		// ウィンドウ情報の初期化
#ifdef _DEBUG
void DispFPS(void);	// デバッグ時のみ有効な関数
#endif

//グローバル変数
int g_fpsCounter;	//FPSカウンタ

//メイン関数
int main()
{
	int execLastTime;	// ゲーム処理をした時間（タイマー値）
	int fpsLastTime;	// デバッグ表示をした時間（タイマー値）
	int currentTime;	// 現在の時間（タイマー値）
	int frameCount;		// ゲームの処理をした回数

	setcaption((char*)"ウィンドウタイトル");

	// タイマー分解能を高精度に設定
	// 1/1000秒ごとに1ずつ増えるタイマーを使える
	timeBeginPeriod(1);

	execLastTime =
		fpsLastTime = timeGetTime();	// 現在のタイマー値取得

	// 変数を0に初期化
	currentTime =
		frameCount = 0;

	// ウィンドウ情報の初期化
	WindowConsoleInitialize();

	// カーソル表示ＯＦＦ
	setcursortype(NOCURSOR);

	//初期化処理
	bool rtn = 0;
	int ch = 0;
	rtn = HEWStartup();
	if (rtn != 1) {
		perror("HEWStartup error");
		return 0;  // FALSE
	}

	Initialize();

	//ゲームループ
	do
	{
		currentTime = timeGetTime();	// 現在のタイマー値
		if ((currentTime - fpsLastTime) >= DEBUG_TIMER)	// タイマーの差が500ms以上かどうか
		{	// 処理回数と経過時間から1秒間に何回処理できるかを計算
			g_fpsCounter = frameCount * 1000 / (currentTime - fpsLastTime);
			fpsLastTime = currentTime;	// 現在のタイマー値を保存
			frameCount = 0;				// 処理回数リセット
		}

		// 前回ゲーム処理時のタイマー値と現在のタイマー値の差が
		// 1/60秒(17ms)以上になっていたら処理を実行
		if ((currentTime - execLastTime) >= (1000 / 60))
		{
			execLastTime = currentTime;// 現在のタイマー値保存

			//更新処理
			Update();

			//描画処理
			Draw();

			//シーン切り替え
			CheckScene();
			frameCount++;// ゲーム処理回数アップ

			//Sleep(50);//50ms待機

			// デバッグ時のみ表示
#ifdef _DEBUG
			DispFPS();
#endif
		}
	} while (!inport(PK_ESC)); // ESC押すまでループ

	//ゲーム終了処理
	Uninit();

	//後始末処理
	rtn = HEWCleanup();
	if (rtn != 1) {
		perror("HEWCleanup error");
		return 0; // FALSE
	}

	//ここから後始末処理
	//カーソル表示ON
	setcursortype(NORMALCURSOR);

	//タイマー分解能を戻す
	timeEndPeriod(1);

	return 0;
}

//ウィンドウ設定の初期化(HEW用設定)
void WindowConsoleInitialize(void)
{
	// Set console window position
	HWND consoleWindow = GetConsoleWindow();
	int x, y;
	x = WINDOWPOS_X;
	y = WINDOWPOS_Y;
	SetWindowPos(consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// Set console window size
	SMALL_RECT windowSize = { 0, 0, 80, 25 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

	// Set console buffer size
	// ウィンドウサイズは80, 25で固定すること
	COORD coord;
	coord.X = 80;
	coord.Y = 25;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	// Set console font style and size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	// ↓フォントサイズのみ変更可↓
	cfi.dwFontSize.X = 12;						// Width of each character in the font
	cfi.dwFontSize.Y = 24;						// Height
	// ↑フォントサイズのみ変更可↑
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"MS Gothic");       // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Initialize()
{
	InitScene();
}

void Uninit()
{
	UninitScene();
}

void Update()
{
	UpdateScene();
}

void Draw()
{
	DrawScene();
}

#ifdef _DEBUG
// デバッグ表示
void DispFPS(void)
{
	// 色設定
	textcolor(LIGHTCYAN);

	gotoxy(1, 1);	// 表示位置設定
	std::cout << "FPS:" << g_fpsCounter;	// FPS値表示

	// 色設定(もとに戻す)
	textcolor(WHITE);
}
#endif