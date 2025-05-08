#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class TransparentGimmick : public GimmickBase
{
private:
	static constexpr float AppearTime = 5.0f;	// 水が上で止まる時間

	bool m_appear;		// 見えるかどうか
	float m_appearTime;	// 見えている間の時間

	void DrawFrameLine();

protected:
	//効果の発動
	virtual void Active() override;
	virtual void Draw() override;

public:
	//コンストラクタ
	TransparentGimmick(const Vector3& spawnPos);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;

	bool GetAppear()
	{
		return m_appear;
	}
};