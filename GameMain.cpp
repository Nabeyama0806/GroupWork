#include "GameMain.h"
#include "GameConfig.h"
#include "Screen.h"
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteLoader.h"
#include "ModelActorCollision.h"
#include "Fade.h"
#include "Input.h"
#include "Time.h"
#include "EffectManager.h"
#include "DxLib.h"
#include <EffekseerForDXLib.h>
//デストラクタ
GameMain::~GameMain()
{
	//自作スクリーンの破棄
	DeleteGraph(m_screen);

	//シーンの破棄
	delete m_sceneManager;
	m_sceneManager = nullptr;

	// Effekseer 終了
	Effkseer_End();

	// DxLib 終了
	DxLib_End();
}

//メインループ
void GameMain::Run()
{
	SetMainWindowText(GameConfig::Title); //ウィンドウタイトル
	SetAlwaysRunFlag(GameConfig::AlwayRunFlag); //非アクティブ時に動作する
	ChangeWindowMode(GameConfig::WindowMode); //ウィンドウモードで起動
	SetGraphMode(Screen::Width, Screen::Heigth, GameConfig::ColorBit); //ウィンドウサイズ
	SetUseDirect3DVersion(DX_DIRECT3D_11);
	if (DxLib_Init()) throw - 1; //DXライブラリの初期化
	EffectManager::GetInstance()->Initialize();

	//シーン起動
	m_sceneManager = new SceneManager(new SceneTitle());

	//スクリーンの作成
	m_screen = MakeScreen(Screen::Width, Screen::Heigth);

	//ゲームループ
	while (ProcessMessage() == 0)
	{
		//入力システムの更新
		Input::GetInstance()->Update();

		//時間の更新
		Time::GetInstance()->Update();

		//ESCキーが押されたら終了
		if (Input::GetInstance()->IsKeyDown(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//シーンの更新
		m_sceneManager->Updeta();

		//衝突判定の更新
		ModelActorCollision::GetInstance()->Update();

		//自作スクリーンに描画
		SetDrawScreen(m_screen);

		//画面に描かれているものを全て消す
		ClearDrawScreen();

		//シーンの描画
		m_sceneManager->Draw();

		EffectManager::GetInstance()->Draw();
		EffectManager::GetInstance()->Update();

#ifdef _DEBUG
		//衝突形状の描画
		ModelActorCollision::GetInstance()->Draw();
#endif
		//フェード
		Fade::GetInstance()->Update(m_screen);

		//自作スクリーンを裏画面に描画
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		DrawGraph(0, 0, m_screen, false);		

		//裏画面と表画面をひっくり返す
		ScreenFlip();
	}
}