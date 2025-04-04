#pragma once
#include "Bottle.h"

class Player;

class FireBottle : public Bottle
{
private :
	Vector3 m_forward;
	Player* m_player;

protected:
	virtual void Update() override;			//更新
	virtual void Draw() override;			//描画
	virtual void ActiveEffect() override;	//効果発動

public:
	//コンストラクタ
	FireBottle(const Vector3& position, const Vector3& forward, Player* player);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};