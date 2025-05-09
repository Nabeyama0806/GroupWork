#include "Node.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Input.h"
#include "Screen.h"
#include "TitleSelect.h"
#include "DxLib.h"
#include <fstream>

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

	//選択用のボタン
	m_rootNode->AddChild(new SpriteActor("Select", "Resource/Texture/select.png", Screen::Center));

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
		//エンターキーが押されたらゲームシーンへ移動
		if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT))
		{
			//効果音
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);
			m_phase = Phase::OpenBook;
		}
		break;

	case Phase::OpenBook:
		//アニメーションの更新
		m_sprite->Update();
		m_sprite->Play(AnimeName[static_cast<int>(m_anime)]);
		
		//アニメーションが終わるとシーン遷移
		if (m_sprite->IsFinishAnime())
		{
			if (m_anime == Anime::Initial) m_anime = Anime::Final;
			//else return new SceneGame(m_select->GetIsContinued());
		}
		break;
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

//データの読み込み
int SceneTitle::DataLoad()
{
	std::fstream file;
	std::string data;

	//セーブ用ファイルを開く
	file.open("SaveData.txt");

	//オープンできなかったらここで終了
	if (!file.is_open()) return -1;

	//データの読み込み
	getline(file, data);

	//ファイルを閉じる
	file.close();

	return std::stoi(data);
}

//データの書き込み
void SceneTitle::DataSeve(int data)
{
	std::fstream file;

	//セーブ用ファイルを開く
	file.open("SaveData.txt");

	//オープンできなかったらここで終了
	if (!file.is_open()) return;

	//データの書き込み
	file << std::to_string(data);

	//ファイルを閉じる
	file.close();
}