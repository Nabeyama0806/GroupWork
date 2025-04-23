#pragma once
#include "ModelActor.h"

class Player;

class GetBottle : public ModelActor
{
public:
	enum class Type
	{
		Fire,
		Thunder,
		Water,
		Wind,
	};

private:
	static constexpr Vector3 Scale = Vector3(10, 10, 10);		//自身のサイズ
	static constexpr Vector3 SpawnOffset = Vector3(0, -25, 0);	//スポーンオフセット

	Player* m_player;	//プレイヤー
	GetBottle::Type m_type;

public:
	//コンストラクタ
	GetBottle(const Vector3& spawnPos, Player* player, const char* fileName, GetBottle::Type);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};