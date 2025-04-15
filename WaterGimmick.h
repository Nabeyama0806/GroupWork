#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class WaterGimmick : public GimmickBase
{
private:
	static constexpr float VariableWater = 2.0f;	// 変動する水の速度
	static constexpr float StopTime = 5.0f;	// 水が上で止まる時間

	bool m_waterHeight;	// 水瓶に当たったかどうか
	bool m_canUp;		//上昇可能かどうか
	float m_stopTime;	// 水が上で止まっている時間
	Vector3 m_startPos;	// 水の初期位置

protected:
	//効果の発動
	virtual void Active() override;

public:
	//コンストラクタ
	WaterGimmick(const Vector3& spawnPos, const Vector3& scale, const Vector3& offset = Vector3(0, 0, 0));

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};