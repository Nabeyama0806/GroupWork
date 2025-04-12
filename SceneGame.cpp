#include "SceneGame.h"
#include "SceneResult.h"
#include "SoundManager.h"
#include "Screen.h"
#include "Fade.h"
#include "Time.h"
#include "Input.h"
#include "Node.h"
#include "Sprite.h"
#include "ModelActor.h"
#include "SpriteActor.h"
#include "Camera.h"
#include "Player.h"
#include "UiBottle.h"
#include "CreateMap.h"
#include "DxLib.h"

//初期化
void SceneGame::Initialize()
{
	//ルート
	m_rootNode = new Node();

	//メインカメラ
	m_mainCamera = new Camera();
	m_rootNode->AddChild(m_mainCamera);

	//背景
	//m_stage = new ModelActor("Ground", "Environment/BaseStage3.0.mv1");
	//m_rootNode->AddChild(m_stage);

	//アクターレイヤー
	Node* actorLayer = new Node();
	m_rootNode->AddChild(actorLayer);

	//UIレイヤー
	Node* uiLayer = new Node();
	m_rootNode->AddChild(uiLayer);

	//ボトルUIの表示
	m_uiBottle = new UiBottle();
	uiLayer->AddChild(m_uiBottle);

	//照準の表示
	uiLayer->AddChild(new SpriteActor("reticle", "Resource/reticle.png", Screen::Center));

	//プレイヤー
	m_player = new Player(m_mainCamera, m_uiBottle);
	actorLayer->AddChild(m_player);
	m_mainCamera->SetLookAt(m_player, m_isLookPlayer);

	// マップ
	actorLayer->AddChild(new CreateMap());

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Sound/bgm_game.mp3");
	SoundManager::GetInstance()->SoundPlay(m_bgm, DX_PLAYTYPE_LOOP);

	//背景色の変更
	SetBackgroundColor(230, 230, 230);
}

//終了
void SceneGame::Finalize()
{
	//画像の事前読み込み
	for (auto sprite : SpritePreload)
	{
		SpriteLoader::GetInstance()->Delete(sprite);
	}

	//モデルの事前読み込み
	for (auto model : ModelPreload)
	{
		ModelLoader::GetInstance()->Delete(model);
	}

	//ノードの削除
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;

	//BGM
	DeleteSoundMem(m_bgm);
}

//更新
SceneBase* SceneGame::Update()
{
	//ノードの更新
	m_rootNode->TreeUpdate();

	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_1))
	{
		m_isLookPlayer = !m_isLookPlayer;
		m_mainCamera->SetLookAt(m_isLookPlayer ? m_player : m_stage, m_isLookPlayer);
	}

	return this;
}

//描画
void SceneGame::Draw()
{
	//ノードの描画
	m_rootNode->TreeDraw();
}