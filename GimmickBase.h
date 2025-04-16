#pragma once
#include "ModelActor.h"
#include "Vector3.h"

class Player;
class Effect;

class GimmickBase : public ModelActor
{
protected:
	Effect* m_effect;
	Vector3 m_effectOffset;
	Vector3 m_scale;
	Player* m_player;

	virtual void Update() override;	//更新
	virtual void Draw() override;	//描画

public:
	//コンストラクタ
	GimmickBase(const char* name, const Vector3& position);

	//効果の発動
	virtual void Active() = 0;
};