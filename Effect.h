#pragma once
#include "Vector3.h"

class Effect
{
private:
	static constexpr float EffectMoveSpeed = 0.2f;				//エフェクトが移動する速度

	int m_effectPlayInterval;		//エフェクトを再生する周期
	int m_effectHandle;			//エフェクトのリソース用
	int m_playingEffectHandle;	//再生中のエフェクトハンドル
	int m_playCount;

public:
	Effect(const char* filePath, const int effectSize, const int playInterval = 150);	// コンストラクタ
	~Effect();						// デストラクタ

	void Update(Vector3& position);		// 更新
	void Play(bool loop = true);
};