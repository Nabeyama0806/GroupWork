#include "SceneResult.h"
#include "Input.h"
#include "SceneTitle.h"
#include "SpriteActor.h"
#include "Time.h"

//初期化
void SceneResult::Initialize()
{
	m_rootNode = new Node();

	//アニメーションの登録
	m_sprite = new Sprite();
	m_sprite->gridSize = Screen::Size;
	for (int i = 0; i < static_cast<int>(ClearAnime::Length); ++i)
	{
		m_sprite->Register(ClearAnimeName[i], ClearAnimeDate[i]);
	}
	m_sprite->Load();

	SetBackgroundColor(255, 255, 255); //背景色の変更
}

//終了処理
void SceneResult::Finalize()
{
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//更新
SceneBase* SceneResult::Update()
{
	if (m_waitTransitionTime > 0)
	{
		m_waitTransitionTime -= Time::GetInstance()->GetDeltaTime();
	}

	m_sprite->Update();
	m_sprite->Play(ClearAnimeName[static_cast<int>(m_clearAnime)]);
	if (m_sprite->IsFinishAnime() && m_clearAnime == ClearAnime::First)
	{
		m_clearAnime = ClearAnime::Second;
	}

	//いずれかのキーが押されたらタイトル画面に遷移
	if (m_waitTransitionTime <= 0 && Input::GetInstance()->IsAnyKeyDown())
	{
		return new SceneTitle();
	}

	//ノードの更新
	m_rootNode->TreeUpdate();

	return this;
}

//描画
void SceneResult::Draw()
{
	//ノードの更新
	m_rootNode->TreeDraw();

	m_sprite->Draw(m_transform);
}