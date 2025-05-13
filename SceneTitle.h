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
private:
	//フェーズ
	enum class Phase
	{
		Run,			//実行中
		Start,			//本を開く
		StageSelect,	//ステージの選択

		Length,
	};

	enum class OpenAnime
	{
		First,		
		Second,		

		Length,
	};
	
	enum class SelectAnime
	{
		Prev,
		Next,
		FinishAnime,

		Length,
	};

	const char* OpenAnimeName [static_cast<int>(OpenAnime::Length)] =
	{
		"Initial",
		"Final",
	};
	const SpriteAnimation OpenAnimeDate[static_cast<int>(OpenAnime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/open1.png", 10, 20, false),
		SpriteAnimation("Resource/LoadBook/open2.png", 10, 17, false),
	};

	const char* SelectAnimeName[static_cast<int>(SelectAnime::Length)] =
	{
		"Prev",
		"Next",
		"End",
	};
	const SpriteAnimation SelectAnimeData[static_cast<int>(SelectAnime::Length)] =
	{
		SpriteAnimation("Resource/Book/page_prev.png", 13, 17, false),
		SpriteAnimation("Resource/Book/page_next.png", 13, 17, false),
		SpriteAnimation("Resource/Book/0051.png", 1, 1, false),
	};

	const char* SelectStage[static_cast<int>(CreateMap::MapType::Length)] =
	{
		"Map0"
		"Map1"
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
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/stsge1.png", 1, 1, false),
	};



	Node* m_rootNode;
	PlayData* m_playData;
	Sprite* m_sprite;
	Sprite* m_stageSprite;
	TitleSelect* m_select;
	Phase m_phase;
	OpenAnime m_openAnime;
	Transform m_transform;
	int m_stageNum;
	int m_bgm;

public:
	//コンストラクタ
	SceneTitle() :
		m_phase(Phase::Run),
		m_openAnime(OpenAnime::First),
		m_rootNode(nullptr),
		m_playData(nullptr),
		m_sprite(nullptr),
		m_select(nullptr),
		m_stageNum(0),
		m_bgm(0)
	{
		m_playData = new PlayData();
	}

	virtual void Initialize() override;				//初期化
	virtual void Finalize() override;				//終了
	virtual SceneBase* Update() override;			//更新
	virtual void Draw() override;					//描画
};