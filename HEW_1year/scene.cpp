#define CONIOEX
#include "conioex.h"
#include "scene.h"
#include "title.h"
#include "result.h"
#include "game.h"

//起動時に動作させたいシーンをセットしておく
SCENE g_Scene = SCENE_TITLE;//現在稼働中のシーン
SCENE g_SceneNext = SCENE_TITLE;//移行先のシーン
//シーンの初期化
void InitScene(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の初期化
		InitTitle();
		break;
	case SCENE_GAME:
		//本編の初期化
		InitGame();
		break;
	case SCENE_RESULT:
		//リザルトの初期化
		InitResult();
		break;
	}
}
//シーンの終了処理
void UninitScene(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の初期化
		UninitTitle();
		break;
	case SCENE_GAME:
		//本編の初期化
		UninitGame();
		break;
	case SCENE_RESULT:
		//リザルトの初期化
		UninitResult();
		break;
	}
}
void UpdateScene(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の初期化
		UpdateTitle();
		break;
	case SCENE_GAME:
		//本編の初期化
		UpdateGame();
		break;
	case SCENE_RESULT:
		//リザルトの初期化
		UpdateResult();
		break;
	}
}
//シーンの描画処理
void DrawScene(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の初期化
		DrawTitle();
		break;
	case SCENE_GAME:
		//本編の初期化
		DrawGame();
		break;
	case SCENE_RESULT:
		//リザルトの初期化
		DrawResult();
		break;
	}
}
void SetScene(SCENE next)
{
	g_SceneNext = next;
}
//シーン切り替え
void CheckScene(void)
{
	//移行先シーンがセットされているかを確認する
	if (g_Scene != g_SceneNext)
	{
		//現在稼働中のシーンを終了させる
		UninitScene();

		//現在動作中のシーンを移行先シーンで更新する
		g_Scene = g_SceneNext;
		//更新したシーンの初期化を行う
		InitScene();
		//画面のクリア
		clrscr();
	}
}