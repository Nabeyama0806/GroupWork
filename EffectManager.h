#pragma once
#include <EffekseerForDXLib.h> //エフェクシアファイル
#include "Vector3.h"

// エフェクト管理クラス
class EffectManager
{
private:
	static constexpr int EffectParticleLimit = 20000;	// 画面に表示できる最大パーティクル数

public:
	//シングルトン
	static EffectManager* GetInstance()
	{
		static EffectManager instance;
		return &instance;
	}

	void Initialize();					// 初期化
	int Load(const char* filePath);		// 読み込み
	void Update(const Vector3& playPosition);	// 更新
	void Draw();						// 描画
};