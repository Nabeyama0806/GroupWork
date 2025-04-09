#pragma once
#include "ModelActor.h"
#include "Model.h"

class WindGimmick : public ModelActor
{
private:
	static constexpr Vector3 SpawnOffset = Vector3(0, 150, 0);	//オフセット
	static constexpr Vector3 Scale = Vector3(50, 50, 50);	//自身のサイズ
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// コライダーのオフセット
	static constexpr Vector3 ColliderSize = Vector3(4, 4, 4);	// コライダーのサイズ

protected:
	virtual void Update() override;	//更新
	virtual void Draw() override;	// 描画

public:
	//コンストラクタ
	WindGimmick(Vector3 position);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};