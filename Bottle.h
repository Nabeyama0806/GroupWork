#pragma once
#include "ModelActor.h"

class Player;

class Bottle : public ModelActor
{
public:
	//ボトルの属性
	enum class  Type
	{
		Fire,		//炎
		Thunder,	//雷
		Water,		//水
		Wind,		//風

		Length
	};

	static constexpr Vector3 Scale = Vector3(10, 10, 10);		//大きさの調整
private:
	static constexpr float Gravity = 0.01f;	//重力
	static constexpr float AddForce = 1700;	//投げる力
	static constexpr float Mass = 2;		//質量

	Vector3 m_forward;

protected:
	static constexpr Vector3 ColliderSize = Vector3(4, 4, 4);

	Player* m_player;

	virtual void Update() override;		//更新
	virtual void ActiveEffect();				//効果の発動
	Vector3 Throw(Vector3& position) const;

public:
	//コンストラクタ
	Bottle(const char* bottleName, const Vector3& position, const Vector3& forward, Player* player);
};