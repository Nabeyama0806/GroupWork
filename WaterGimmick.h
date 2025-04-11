#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class WaterGimmick : public GimmickBase
{
private:
	static constexpr float DownWaterHeight = 10.0f;
	static constexpr float UpWaterHeight = 250.0f;

	static constexpr float VariableWater = 2.0f;	// 変動する水の速度

	bool m_isWaterHeight;	// 水が高くなっているかどうか
	bool m_isPlay;

protected:
	//効果の発動
	virtual void Active() override;

public:
	//コンストラクタ
	WaterGimmick(const Vector3& spawnPos, const Vector3& scale, const Vector3& offset = Vector3(0, 0, 0));

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};