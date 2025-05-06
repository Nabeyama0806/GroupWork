#include "SceneTitle.h"
#include "SceneGame.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"

//初期化
void SceneTitle::Initialize()
{
	m_transform.position = Screen::Center;

	//アニメーションの登録
	m_sprite = new Sprite();
	m_sprite->gridSize = Screen::Size;
	for (int i = 0; i < static_cast<int>(Anime::Length); ++i)
	{
		m_sprite->Register(AnimeName[i], AnimeDate[i]);
	}
	m_sprite->Load();

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Resource/sound/bgm_title.mp3");
	SoundManager::Play(m_bgm, DX_PLAYTYPE_LOOP);

	//背景色の変更
	SetBackgroundColor(255, 255, 255); 
}

//更新
SceneBase* SceneTitle::Update()
{
	switch (m_phase)
	{
	case Phase::Run:
		//いずれかのキーが押されたらゲームシーンへ移動
		if (Input::GetInstance()->IsAnyKeyDown())
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
			else return new SceneGame();
		}
		break;
	}

	return this;
}

//描画
void SceneTitle::Draw()
{
	m_sprite->Draw(m_transform);
}