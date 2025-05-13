#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;
class Camera;

class TransparentGimmick : public GimmickBase
{
private:
	static constexpr float AppearTime = 5.0f;	// 水が上で止まる時間

	Camera* m_camera;
	bool m_appear;		// 見えるかどうか
	float m_appearTime;	// 見えている間の時間

protected:
	//効果の発動
	virtual void Active() override;
	virtual void Draw() override;

public:
	//コンストラクタ
	TransparentGimmick(const Vector3& spawnPos, Camera* camera);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;

	bool GetAppear() const
	{
		return m_appear;
	}
};