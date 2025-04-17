#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Player;
class Effect;

class KeyGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);		//自身のサイズ
	static constexpr float DestroyTime = 3;	// 燃え続ける時間

	Player* m_player;	//プレイヤー
	bool m_destroyWall;	// このオブジェクトが消えるかどうか
	float m_destroyTime;	// 燃える時間

protected:
	//効果の発動
	virtual void Active() override;

public:
	//コンストラクタ
	KeyGimmick(const Vector3& position, const Vector3& size, Player* player);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};