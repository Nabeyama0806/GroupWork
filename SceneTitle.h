#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Sprite.h"
#include "PlayData.h"
#include "CreateMap.h"

class Node;

//タイトルシーン
class SceneTitle : public SceneBase
{
public:
	//フェーズ
	enum class Phase
	{
		ModeSelect,		//モードの選択
		OpenBook,		//本を開く
		StageSelect,	//ステージの選択
		GameStart,		//ゲーム開始

		Length,
	};

private:
	static constexpr Vector2 SelectButtonSize = Vector2(650, 150);	//矢印ボタンの大きさ
	static constexpr Vector2 ArrowButtonSize = Vector2(200, 300);	//選択ボタンの大きさ
	
	static constexpr Vector2 LeftArrowButtonPos = Vector2(50, 540);		//左矢印ボタンの座標
	static constexpr Vector2 RightArrowButtonPos = Vector2(1870, 540);	//右矢印ボタンの座標

	static constexpr Vector2 LeftSelectButtonPos = Vector2(350, 980);		//左選択ボタンの座標
	static constexpr Vector2 RightSelectButtonPos = Vector2(1570, 980);		//右選択ボタンの座標

	enum class TitleAnime
	{
		Open,
		Close,

		Length,
	};

	const char* TitleAnimeName[static_cast<int>(TitleAnime::Length)] =
	{
		"Open",
		"Close",
	};
	const SpriteAnimation TitleAnimeData[static_cast<int>(TitleAnime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/1920open_title.png", 12, 17, false),
		SpriteAnimation("Resource/LoadBook/1920close_title.png", 12, 17, false),
	};

	enum class SelectAnime
	{
		Prev,
		Next,
		FinishAnime,

		Length,
	};

	const char* SelectAnimeName[static_cast<int>(SelectAnime::Length)] =
	{
		"Prev",
		"Next",
		"End",
	};
	const SpriteAnimation SelectAnimeData[static_cast<int>(SelectAnime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/prev_page.png", 13, 17, false),
		SpriteAnimation("Resource/LoadBook/next_page.png", 13, 17, false),
		SpriteAnimation("Resource/LoadBook/end_page.png", 1, 16, false),
	};

	const char* SelectStage[static_cast<int>(CreateMap::MapType::Length)] =
	{
		"Map0",
		"Map1",
		"Map2",
		"Map3",
		"Map4",
		"Map5",
		"Map6",
		"Map7",
		"Map8",
		"Map9",
	};
	const SpriteAnimation SelectStageData[static_cast<int>(CreateMap::MapType::Length)] =
	{
		SpriteAnimation("Resource/Texture/Map0.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map2.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map3.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map4.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map5.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map6.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map7.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map8.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map9.png", 1, 1, false),
	};

	Node* m_rootNode;
	Node* m_ModeSelectButtonNode;
	Node* m_StageSelectButtonNode;
	PlayData* m_playData;
	Sprite* m_sprite;
	Sprite* m_stageSprite;
	Phase m_phase;
	TitleAnime m_titleAnime;
	Transform m_transform;
	bool m_isReset;
	int m_stageNum;
	int m_bgm;

	void LeftArrowButton();		//ステージ選択用の左矢印ボタン
	void RightArrowButton();	//ステージ選択用の右矢印ボタン

	void ContinueButton();		//つづきからのボタン
	void NewGameButton();		//はじめからのボタン

	void StartButton();			//ゲームスタートのボタン	
	void BackButton();			//戻る用のボタン

protected:
	virtual void Initialize() override;		//初期化
	virtual void Finalize() override;		//終了
	virtual SceneBase* Update() override;	//更新
	virtual void Draw() override;			//描画

public:
	//コンストラクタ
	SceneTitle() :
		m_phase(Phase::ModeSelect),
		m_titleAnime(TitleAnime::Open),
		m_isReset(false),
		m_rootNode(nullptr),
		m_ModeSelectButtonNode(nullptr),
		m_StageSelectButtonNode(nullptr),
		m_playData(nullptr),
		m_sprite(nullptr),
		m_stageSprite(nullptr),
		m_stageNum(0),
		m_bgm(0)
	{
		m_playData = new PlayData();
	}

	void SetPhase(Phase phase)
	{
		m_phase = phase;
	}
};