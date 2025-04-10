#pragma once
#include "Vector3.h"

class Effect
{
private:
	static constexpr float EffectMoveSpeed = 0.2f;				//エフェクトが移動する速度

	int effectPlayInterval;		//エフェクトを再生する周期
	int effectHandle;			//エフェクトのリソース用
	int playingEffectHandle;	//再生中のエフェクトハンドル
	int playCount;

public:
	Effect(const char* filePath, const int effectSize, const int playInterval = 150);	// コンストラクタ
	~Effect();						// デストラクタ

	void Update(Vector3& position);		// 更新
	void Play(bool loop = true);
};