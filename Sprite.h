#pragma once
#include "Vector2.h"
#include "Transform.h"
#include "SpriteAnimation.h"
#include <map>	//連想配列

class Sprite
{
private:
	std::map<const char*, SpriteAnimation> m_spriteAnimationList;//<アニメーション名：アニメーションデータ>の連想配列
	const SpriteAnimation* m_runningAnime;	//再生中アニメーションリストへのポインタ
	float m_elapsedTime;					//経過時間(秒）

public:
	Vector2 gridSize;	//アニメーションのの幅、高さ
	bool flipX;			//左右反転
	bool flipY;			//上下反転

	//コンストラクタ
	Sprite() :
		m_runningAnime(nullptr),
		m_elapsedTime(0),
		flipX(false),
		flipY(false) {
	}

	//デストラクタ
	virtual ~Sprite();

	//画像の読み込み
	void Load();

	//画像の開放
	void Release();

	//更新
	void Update();

	//描画
	void Draw(const Transform& transform);

	//アニメーションの登録
	void Register(const char* textureName);
	void Register(const char* animeName, const SpriteAnimation& spriteAnimation);

	//アニメーションの再生
	void Play(const char* animeName);

	//アニメーション1コマの描画時間を取得
	float GetFrameTime()
	{
		return m_runningAnime ? 1.0f / m_runningAnime->sampleRate : 0.0f;
	}

	//アニメーションの総時間を取得
	float GetTotalFrameTime()
	{
		return m_runningAnime ? GetFrameTime() * m_runningAnime->gridAmount : 0.0f;
	}

	//アニメーションが終了したかどうか
	bool IsFinishAnime()
	{
		return m_runningAnime ? m_elapsedTime >= GetTotalFrameTime() : true;
	}
};
