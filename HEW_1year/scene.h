#pragma once

//列挙体でシーン定義
enum SCENE
{
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT,

	SCENE_NUM,
};

//プロトタイプ宣言
void InitScene();
void UninitScene();
void UpdateScene();
void DrawScene();

void SetScene(SCENE next);
void CheckScene();