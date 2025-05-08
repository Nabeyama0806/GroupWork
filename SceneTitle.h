#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Sprite.h"

//タイトルシーン
class SceneTitle : public SceneBase
{
private:
	//フェーズ
	enum class Phase
	{
		Run,		//実行中
		OpenBook,	//本を開く

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
		SpriteAnimation("Resource/Book/open1.png", 10, 15, false),
		SpriteAnimation("Resource/Book/open2.png", 10, 13, false),
	};

	Phase m_phase;
	Anime m_anime;
	Sprite* m_sprite;
	Transform m_transform;
	int m_bgm;

public:
	//コンストラクタ
	SceneTitle() :
		m_phase(Phase::Run),
		m_anime(Anime::Initial),
		m_sprite(nullptr),
		m_bgm(0){}

	virtual void Initialize() override;				//初期化
	virtual void Finalize() override {};			//終了
	virtual SceneBase* Update() override;			//更新
	virtual void Draw() override;					//描画
};