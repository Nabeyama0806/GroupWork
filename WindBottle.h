#pragma once
#include "Bottle.h"

class WindBottle : public Bottle
{
private:
	Vector3 m_forward;

protected:
	virtual void Update() override;			//更新
	virtual void Draw() override;			//描画
	virtual void ActiveEffect() override;	//効果発動

public:
	//コンストラクタ
	WindBottle(const Vector3& position, const Vector3& forward, const Quaternion& rotation);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
}; 
