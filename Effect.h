#pragma once
#include "Vector3.h"

class Effect
{
private:
	static constexpr int EffectPlayInterval = 150;				//エフェクトを再生する周期
	static constexpr float EffectSize = 30.0f;					//エフェクトのサイズ
	static constexpr float EffectMoveSpeed = 0.2f;				//エフェクトが移動する速度

	int effectHandle;			//エフェクトのリソース用
	int playingEffectHandle;	//再生中のエフェクトハンドル
	int playCount;				

public:
	Effect(const char* filePath);	// コンストラクタ
	~Effect();						// デストラクタ

	void Update(Vector3& position);		// 更新
};