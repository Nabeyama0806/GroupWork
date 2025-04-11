#pragma once
#include "GimmickBase.h"
#include "Model.h"
#include "Effect.h"

class WindGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);		//自身のサイズ
	static constexpr Vector3 SpawnOffset = Vector3(0, 100, 0);	//オフセット
	
protected:
	//効果の発動
	virtual void Active() override;
public:
	//コンストラクタ
	WindGimmick(const Vector3& position);
};