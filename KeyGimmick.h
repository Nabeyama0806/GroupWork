#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Player;
class Effect;

class KeyGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(25, 25, 25);		//自身のサイズ
	static constexpr float DestroyTime = 1;	//鍵を開けるのに必要な時間

	Player* m_player;		//プレイヤー
	bool m_destroyWall;		// このオブジェクトが消えるかどうか
	bool m_isFake;			// 偽物かどうか	
	float m_destroyTime;	// 経過時間

protected:
	//効果の発動
	virtual void Active() override;

public:
	//コンストラクタ
	KeyGimmick(const Vector3& position, Player* player, bool isFake);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};