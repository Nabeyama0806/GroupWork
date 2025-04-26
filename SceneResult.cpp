#include "SceneResult.h"
#include "Input.h"
#include "Screen.h"
#include "SceneTitle.h"
#include "SpriteActor.h"
#include "Time.h"

//初期化
void SceneResult::Initialize()
{
	m_rootNode = new Node();

	//背景
	m_rootNode->AddChild(new SpriteActor("BackGround", "Resource/Texture/title.png", Screen::Center));

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
}