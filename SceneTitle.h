#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Sprite.h"
#include "PlayData.h"

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

	enum class Anime
	{
		Initial,	//開始
		Final,		//終わり

		Length,
	};

	//アニメ名
	const char* AnimeName[static_cast<int>(Anime::Length)] =
	{
		"Initial",
		"Final",
	};
		
	//アニメのファイルパス
	const SpriteAnimation AnimeDate[static_cast<int>(Anime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/open1.png", 10, 20, false),
		SpriteAnimation("Resource/LoadBook/open2.png", 10, 17, false),
	};

	Node* m_rootNode;
	PlayData* m_playData;
	Sprite* m_sprite;
	TitleSelect* m_select;
	Phase m_phase;
	Anime m_anime;
	Transform m_transform;
	int m_bgm;

public:
	//コンストラクタ
	SceneTitle() :
		m_phase(Phase::Run),
		m_anime(Anime::Initial),
		m_rootNode(nullptr),
		m_playData(nullptr),
		m_sprite(nullptr),
		m_select(nullptr),
		m_bgm(0)
	{
		m_playData = new PlayData();
	}

	virtual void Initialize() override;				//初期化
	virtual void Finalize() override;				//終了
	virtual SceneBase* Update() override;			//更新
	virtual void Draw() override;					//描画
};