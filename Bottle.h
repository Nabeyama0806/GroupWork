#pragma once
#include "ModelActor.h"

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

	static constexpr int Scale = 20;		//大きさの調整
private:
	static constexpr float Gravity = 0.01f;	//重力
	static constexpr float AddForce = 2000;	//投げる力
	static constexpr float Mass = 2;		//質量

protected:
	static constexpr Vector3 ColliderSize = Vector3(80, 80, 80);

	virtual void ActiveEffect() = 0;		//接触時の発動効果
	Vector3 Throw(Vector3& position) const;

public:
	//コンストラクタ
	Bottle(const char* bottleName, const Vector3& position);
};