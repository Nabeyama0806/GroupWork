#include "SceneGame.h"
#include "SceneResult.h"
#include "ModelLoader.h"
#include "Screen.h"
#include "Fade.h"
#include "Time.h"
#include "Input.h"
#include "Node.h"
#include "Sprite.h"
#include "ModelActor.h"
#include "SpriteActor.h"
#include "HitCollider.h"
#include "Camera.h"
#include "Player.h"
#include "UiBottle.h"
#include "DxLib.h"

//初期化
void SceneGame::Initialize()
{
	//画像の事前読み込み
	for (auto image : ImagePreload)
	{
		ModelLoader::GetInstance()->Load(image);
	}

	//ルート
	m_rootNode = new Node();

	//メインカメラ
	m_mainCamera = new Camera();
	m_rootNode->AddChild(m_mainCamera);

	//背景
	m_rootNode->AddChild(new ModelActor("Ground", "Environment/Environment.mv1"));

	//アクターレイヤー
	Node* actorLayer = new Node();
	m_rootNode->AddChild(actorLayer);

	//UIレイヤー
	Node* uiLayer = new Node();
	m_rootNode->AddChild(uiLayer);

	//プレイヤー
	m_player = new Player(m_mainCamera);
	actorLayer->AddChild(m_player);
	m_mainCamera->SetlookAt(m_player);

	// Ui(仮置き)
	m_tmpUi = new SpriteActor("ui", "Resource/ポーション候補3.png", Screen::BottomLeft);
	m_tmpUi->ChangeScale(0.1f);
	uiLayer->AddChild(m_tmpUi);

	//壁
	Vector3 wallPos	 = Vector3(0, 100, 2000);
	Vector3 wallSize = Vector3(4000, 500, 100);

	actorLayer->AddChild(new HitCollider(
		"Wall",
		Vector3(0, 100, 2000),
		Vector3(4000, 500, 100)
	));
	actorLayer->AddChild(new HitCollider(
		"Wall",
		Vector3(0, 100, -2000),
		Vector3(4000, 500, 100)
	));
	actorLayer->AddChild(new HitCollider(
		"Wall",
		Vector3(2000, 100, 0),
		Vector3(100, 500, 4000)
	));
	actorLayer->AddChild(new HitCollider(
		"Wall",
		Vector3(-2000, 100, 0),
		Vector3(100, 500, 4000)
	));

	// 床
	Vector3 floorPos = Vector3(0, -20, 0);
	Vector3 floorSize = Vector3(4000, 40, 4000);
	actorLayer->AddChild(new HitCollider(
		"Ground",
		floorPos,
		floorSize
	));

	/*
	//属性ビンの表示
	ModelActor* model = new ModelActor("kaminari", "Resource/bottle_thunder.mv1", wallPos);
	model->ChangeScale(70);
	actorLayer->AddChild(model);
	*/

	//UIの表示
 	uiLayer->AddChild(new UiBottle(m_player));

	//BGM

}

//終了
void SceneGame::Finalize()
{
	//事前読み込みした画像の破棄
	for (auto image : ImagePreload)
	{
		ModelLoader::GetInstance()->Delete(image);
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
	return this;
}

//描画
void SceneGame::Draw()
{
	//ノードの描画
	m_rootNode->TreeDraw();
}