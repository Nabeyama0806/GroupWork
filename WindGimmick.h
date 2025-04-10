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
	virtual void Update() override;	//更新
	virtual void Draw() override;	// 描画
	virtual void ActiveEffect() override;
public:
	//コンストラクタ
	WindGimmick(const Vector3& position);
};