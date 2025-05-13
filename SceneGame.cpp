#include "SceneGame.h"
#include "SceneResult.h"
#include "SoundManager.h"
#include "Screen.h"
#include "PlayData.h"
#include "Fade.h"
#include "Time.h"
#include "Input.h"
#include "Node.h"
#include "Sprite.h"
#include "Camera.h"
#include "Player.h"
#include "UiBottle.h"
#include "CreateMap.h"
#include "UiKeyItem.h"
#include "Instructions.h"
#include "DxLib.h"

//初期化
void SceneGame::Initialize()
{
	//ルート
	m_rootNode = new Node();

	//メインカメラ
	m_mainCamera = new Camera();
	m_rootNode->AddChild(m_mainCamera);

	//アクターレイヤー
	Node* actorLayer = new Node();
	m_rootNode->AddChild(actorLayer);

	//UIレイヤー
	Node* uiLayer = new Node();
	m_rootNode->AddChild(uiLayer);

	//操作説明の表示
	m_instructions = new Instructions();
	uiLayer->AddChild(m_instructions);
	m_mainCamera->SetInstructions(m_instructions);

	//ボトルUIの表示
	m_uiBottle = new UiBottle(m_mainCamera, m_instructions);
	uiLayer->AddChild(m_uiBottle);

	//プレイヤー
	m_player = new Player(m_mainCamera, m_uiBottle, m_instructions);
	actorLayer->AddChild(m_player);
	m_mainCamera->SetLookAt(m_player, m_isLookPlayer);

	//照準の表示
	uiLayer->AddChild(new SpriteActor("reticle", "Resource/Texture/reticle.png", Screen::Center));

	//鍵のUIの表示
	uiLayer->AddChild(new UiKeyItem(m_player, m_mainCamera, m_instructions));

	//マップ
	m_map = new CreateMap(m_player, m_playData);
	actorLayer->AddChild(m_map);

	//スカイボックス
	ModelActor* skybox = new ModelActor("Skybox", "Resource/Model/Skybox.mv1");
	skybox->ChangeScale(10000);
	actorLayer->AddChild(skybox);

	// 太陽
	CreatePointLightHandle(
		SunPosition,
		SunRange,
		SunAtten.x,
		SunAtten.y,
		SunAtten.z);

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Resource/Sound/bgm_game.mp3");
	SoundManager::Play(m_bgm, DX_PLAYTYPE_LOOP);

	//セーブデータのマップを読み込み
	m_map->SetMap(m_stageNum);

	SetGlobalAmbientLight(GetColorF(1, 1, 1, 0));
	SetLightDirection(SunPosition);
}

//終了
void SceneGame::Finalize()
{
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
	SoundManager::SoundStop(m_bgm);
}

//更新
SceneBase* SceneGame::Update()
{
	//ノードの更新
	m_rootNode->TreeUpdate();

	//プレイヤーがゴールすれば次のステージに遷移
	switch (m_phase)
	{
	case Phase::Run: //フェードアウト開始
		if (m_player->GetIsGoal())
		{
			//効果音
			SoundManager::Play("Resource/sound/se_goal.mp3");
			
			if (m_map->GetMapIndex() == static_cast<int>(CreateMap::MapType::Length) - 1)
			{
				return new SceneResult(0);
				break;
			}
			m_phase = Phase::FadeOut;
			Fade::GetInstance()->StartFadeOut(0.8f, Fade::Color::White);
		}
		break;

	case Phase::FadeOut:
		if (!Fade::GetInstance()->IsFade())
		{
			m_player->SetIsGoal();
			m_map->LoadMap();
			m_phase = Phase::Transition;
		}
		break;

	case Phase::Transition:
		Fade::GetInstance()->StartFadeIn(1.2f, Fade::Color::White);
		m_phase = Phase::Run;
		break;
	}

	//0キーが押されたら視点を切り替える
	if (Input::GetInstance()->IsCameraChange())
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