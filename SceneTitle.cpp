#include "Node.h"
#include "PlayData.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Input.h"
#include "Time.h"
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
	for (int i = 0; i < static_cast<int>(TitleAnime::Length); ++i)
	{
		m_sprite->Register(TitleAnimeName[i], TitleAnimeData[i]);
	}
	for (int i = 0; i < static_cast<int>(SelectAnime::Length); ++i)
	{
		m_sprite->Register(SelectAnimeName[i], SelectAnimeData[i]);
	}
	m_sprite->Load();
	
	m_stageSprite = new Sprite();
	for (int i = 0; i < static_cast<int>(CreateMap::MapType::Length); ++i)
	{
		m_stageSprite->Register(SelectStage[i], SelectStageData[i]);
	}
	m_stageSprite->Load();

	//選択用のカーソル
	m_select = new TitleSelect();
	m_rootNode->AddChild(m_select);
	Input::GetInstance()->SetMouseDispFlag(true);

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
		m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);

		//キーが押されたらステージ選択へ移動
		if (Input::GetInstance()->IsDecision() && m_select->GetIsKey() ||
			Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT) && !m_select->GetIsKey())
		{
			if (!m_select->GetOnCursor()) break;

			//効果音
			SoundManager::Play("Resource/sound/se_start.mp3");

			if (!m_select->GetIsContinued())
			{
				m_stageNum = 0;
				m_isReset = true;
			}
			else  m_stageNum = m_playData->GetMapData();
			m_phase = Phase::Start;
		}
		break;

	case Phase::Start:
		//アニメーションが終わるとステージ選択へ遷移
		m_select->SetPhase(TitleSelect::SelectType::StageSelect);
		m_sprite->Update();
		m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
		if (m_sprite->IsFinishAnime())
		{
			m_phase = Phase::StageSelect;
			m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
		}
		break;

	case Phase::StageSelect:
		//アニメーションの更新
		m_sprite->Update();
		if (m_titleAnime == TitleAnime::Close)
		{
			m_select->SetPhase(TitleSelect::SelectType::GameSelect);
			m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
			if (m_sprite->IsFinishAnime())
			{
				m_titleAnime = TitleAnime::Open;
				m_phase = Phase::Run;
				break;
			}
		}

		m_stageSprite->Update();
		if (m_sprite->IsFinishAnime())
		{
			m_stageSprite->Play(SelectStage[m_stageNum]);
			m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
		}

		if (!m_sprite->IsFinishAnime()) return this;

		//ひとつ先のステージ
		if (m_select->RightButton())
		{
			m_stageNum--;

			SoundManager::Play("Resource/sound/se_start.mp3");

			if (m_stageNum < 0) m_stageNum = 0;
			else
			{
				m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::Prev)]);
			}
		}

		//ひとつ前のステージ
		if (m_select->LeftButton())
		{
			if (!m_isReset)
			{
				m_stageNum++;
				if (m_stageNum > m_playData->GetMapData())
				{
					m_stageNum = m_playData->GetMapData();
				}
				else
				{
					m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::Next)]);
				}
			}

			SoundManager::Play("Resource/sound/se_start.mp3");
		}

		//開始ボタン
		if (m_select->SelectButtonLeft())
		{
			//効果音
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);

			//プレイデータの記録
			m_playData->Save(m_stageNum, m_playData->GetBottleData());

			return new SceneGame(m_playData, m_stageNum, m_isReset);
		}

		//戻るボタン
		if (m_select->SelectButtonRight())
		{
			m_isReset = false;
			SoundManager::Play("Resource/sound/se_start.mp3");
			m_titleAnime = TitleAnime::Close;
		}
	}

	return this;
}

//描画
void SceneTitle::Draw()
{
	m_sprite->Draw(m_transform);
	// ステージ選択の描画
	if (m_phase == Phase::StageSelect)
	{  
		if (m_sprite->IsFinishAnime()) m_stageSprite->Draw(m_transform);

		/*
		m_elapsedTime -= Time::GetInstance()->GetDeltaTime();
		if (m_elapsedTime > 0) return;
		*/
	}

	//ノードの描画
	m_rootNode->TreeDraw();
}