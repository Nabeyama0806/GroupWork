#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Sprite.h"
#include "PlayData.h"
#include "CreateMap.h"

class Node;
class TitleSelect;

//タイトルシーン
class SceneTitle : public SceneBase
{
public:
	//フェーズ
	enum class Phase
	{
		Run,			//実行中
		Start,			//本を開く
		StageSelect,	//ステージの選択

		Length,
	};

private:
	static constexpr Vector2 StageTextureOffset = Vector2(-50, 0);	//ステージのテクスチャのオフセット
	
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
	PlayData* m_playData;
	Sprite* m_sprite;
	Sprite* m_stageSprite;
	TitleSelect* m_select;
	Phase m_phase;
	TitleAnime m_titleAnime;
	Transform m_transform;
	bool m_isReset;
	float m_elapsedTime;
	int m_stageNum;
	int m_bgm;

protected:
	virtual void Initialize() override;				//初期化
	virtual void Finalize() override;				//終了
	virtual SceneBase* Update() override;			//更新
	virtual void Draw() override;					//描画

public:
	//コンストラクタ
	SceneTitle() :
		m_phase(Phase::Run),
		m_titleAnime(TitleAnime::Open),
		m_isReset(false),
		m_rootNode(nullptr),
		m_playData(nullptr),
		m_sprite(nullptr),
		m_stageSprite(nullptr),
		m_select(nullptr),
		m_elapsedTime(0),
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