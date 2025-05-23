#include "Node.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "SelectButton.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "PlayData.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"

//初期化
void SceneTitle::Initialize()
{
	//ノード
	m_rootNode = new Node();
	m_ModeSelectButtonNode = new Node();
	m_StageSelectButtonNode = new Node();

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
	Input::GetInstance()->SetMouseDispFlag(true);

	//ボタン
	m_ModeSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/continue.png", SelectButtonSize, LeftSelectButtonPos, std::bind(&SceneTitle::ContinueButton, this)));
	m_ModeSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/newgame.png", SelectButtonSize, RightSelectButtonPos, std::bind(&SceneTitle::NewGameButton, this)));

	m_StageSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/arrow_left.png", ArrowButtonSize, LeftArrowButtonPos, std::bind(&SceneTitle::LeftArrowButton, this)));
	m_StageSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/arrow_right.png", ArrowButtonSize, RightArrowButtonPos, std::bind(&SceneTitle::RightArrowButton, this)));
	m_StageSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/start.png", SelectButtonSize, LeftSelectButtonPos, std::bind(&SceneTitle::StartButton, this)));
	m_StageSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/back.png", SelectButtonSize, RightSelectButtonPos, std::bind(&SceneTitle::BackButton, this)));

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
	if (m_phase == Phase::ModeSelect) m_ModeSelectButtonNode->TreeUpdate();
	if (m_phase == Phase::StageSelect) m_StageSelectButtonNode->TreeUpdate();

	// パッドの右スティックでマウスカーソルを動かす
	int padPointX = 0;
	int padPointY = 0;
	DxLib::GetJoypadAnalogInput(&padPointX, &padPointY, DX_INPUT_PAD1);
	// 感度調整
	Vector2 movePadPoint = Vector2(padPointX, padPointY);
	Input::GetInstance()->SetPadStick(movePadPoint);

	switch (m_phase)
	{
	case Phase::ModeSelect:
		m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
		break;

	case Phase::OpenBook:
		//アニメーションが終わるとステージ選択へ遷移
		m_sprite->Update();
		m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
		if (m_sprite->IsFinishAnime())
		{
			m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
			m_phase = Phase::StageSelect;
		}
		break;

	case Phase::StageSelect:
		//アニメーションの更新
		m_sprite->Update();
		m_stageSprite->Update();

		if (m_titleAnime == TitleAnime::Close)
		{
			m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
			if (m_sprite->IsFinishAnime())
			{
				m_titleAnime = TitleAnime::Open;
				m_phase = Phase::ModeSelect;
				break;
			}
		}
		if (m_sprite->IsFinishAnime())
		{
			m_stageSprite->Play(SelectStage[m_stageNum]);
			m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
		}
		break;

	case Phase::GameStart:
		SoundManager::SoundStop(m_bgm);
		return new SceneGame(m_playData, m_stageNum, m_isReset);
		break;
	}

	return this;
}

//描画
void SceneTitle::Draw()
{
	//ノードの描画
	m_sprite->Draw(m_transform);

	// ステージ選択の描画
	if (m_phase == Phase::StageSelect)
	{
		if (m_sprite->IsFinishAnime()) m_stageSprite->Draw(m_transform);
	}

	m_rootNode->TreeDraw();
	if (m_phase == Phase::ModeSelect) m_ModeSelectButtonNode->TreeDraw();
	if (m_phase == Phase::StageSelect) m_StageSelectButtonNode->TreeDraw();
}

//ステージ選択の左右ボタン
void SceneTitle::LeftArrowButton()
{
	//アニメーションが終わるまでボタンを押せない
	if (!m_sprite->IsFinishAnime()) return;

	m_stageNum--;

	if (m_stageNum < 0) m_stageNum = 0;
	else
	{
		m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::Prev)]);
	}
}
void SceneTitle::RightArrowButton()
{
	//アニメーションが終わるまでボタンを押せない
	if (!m_sprite->IsFinishAnime()) return;

	//初期データなら何もしない
	if (m_isReset) return;
	
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

//モード選択のボタン
void SceneTitle::ContinueButton()
{
	//アニメーションが終わるまでボタンを押せない
	m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);

	//データの読み込み
	m_stageNum = m_playData->GetMapData();
	m_phase = Phase::OpenBook;
}
void SceneTitle::NewGameButton()
{
	//アニメーションが終わるまでボタンを押せない
	m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);

	//初期データの作成
	m_stageNum = 0;
	m_isReset = true;
	m_phase = Phase::OpenBook;
}

//ステージ選択のボタン
void SceneTitle::BackButton()
{
	//アニメーションが終わるまでボタンを押せない
	if (!m_sprite->IsFinishAnime()) return;

	//初期データの破棄
	m_isReset = false;

	//アニメーションの変更
	m_titleAnime = TitleAnime::Close;
}
void SceneTitle::StartButton()
{
	//アニメーションが終わるまでボタンを押せない
	if (!m_sprite->IsFinishAnime()) return;

	//プレイデータの記録
	m_playData->Save(m_stageNum, m_isReset ? 0 : m_playData->GetBottleData(), true);

	//ゲームシーンの起動
	m_phase = Phase::GameStart;
}