#include "Node.h"
#include "PlayData.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Input.h"
#include "Screen.h"
#include "TitleSelect.h"
#include "DxLib.h"

//初期化
void SceneTitle::Initialize()
{
	m_rootNode = new Node();
	m_transform.position = Screen::Center;

	//アニメーションの登録
	m_sprite = new Sprite();
	m_sprite->gridSize = Screen::Size;
	for (int i = 0; i < static_cast<int>(Anime::Length); ++i)
	{
		m_sprite->Register(AnimeName[i], AnimeDate[i]);
	}
	m_sprite->Load();
	
	//選択用のカーソル
	m_select = new TitleSelect();
	m_rootNode->AddChild(m_select);

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Resource/sound/bgm_title.mp3");
	SoundManager::Play(m_bgm, DX_PLAYTYPE_LOOP);

	//背景色の変更
	SetBackgroundColor(255, 255, 255); 
}

void SceneTitle::Finalize()
{
	//ノードの削除
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//更新
SceneBase* SceneTitle::Update()
{
	//ノードの更新
	m_rootNode->TreeUpdate();

	switch (m_phase)
	{
	case Phase::Run:
		
		//キーが押されたらゲームシーンへ移動
		if (Input::GetInstance()->IsDecision())
		{
			//効果音
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);
			
			//セーブデータの読み込み
			if (!m_select->GetIsContinued()) m_playData->Reset();
			m_playData->Load();
			m_phase = Phase::Start;
		}
		break;

	case Phase::Start:
		m_select->Destroy();

		//アニメーションの更新
		m_sprite->Update();
		m_sprite->Play(AnimeName[static_cast<int>(m_anime)]);
		
		//アニメーションが終わるとステージ選択へ遷移
		if (m_sprite->IsFinishAnime())
		{
			if (m_anime == Anime::Initial) m_anime = Anime::Final;
			else m_phase = Phase::StageSelect;
		}
		break;

	case Phase::StageSelect:
		if (Input::GetInstance()->IsKeyDown(KEY_INPUT_SPACE)
		||  Input::GetInstance()->IsPadDown(PAD_INPUT_1))
		{
			return new SceneGame(m_playData->GetData());
		}
	}

	return this;
}

//描画
void SceneTitle::Draw()
{
	//ノードの描画
	m_sprite->Draw(m_transform);
	m_rootNode->TreeDraw();
}