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

	static constexpr int Scale = 40;		//大きさの調整
private:
	static constexpr float Gravity = 1.2f;	//重力

	Vector3 m_effectiveArea;	//効果の有効範囲
	Type m_type;				//自身の属性

protected:
	virtual void ActiveEffect() = 0;		//接触時の発動効果
	void Throw(Vector3& position, Vector3& addforce);
	Vector3 m_addForce;			//投げられる力

public:
	//コンストラクタ
	Bottle(const Vector3& position);
};