#pragma once
#include "ModelActor.h"
#include "Model.h"

class FireGimmick : public ModelActor
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);	//自身のサイズ
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// コライダーのオフセット
	static constexpr Vector3 ColliderSize = Vector3(4, 4, 4);	// コライダーのサイズ
	static constexpr float FireTime = 3;	// 燃え続ける時間

	bool m_destroyWall;	// このオブジェクトが消えるかどうか
	float m_fireTime;	// 燃える時間

protected:
	virtual void Update() override;	//更新
	virtual void Draw() override;	// 描画

public:
	//コンストラクタ
	FireGimmick(Vector3 position);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};