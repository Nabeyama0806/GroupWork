#pragma once
#include "GimmickBase.h"
#include "Model.h"
#include "Effect.h"

class WindGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(25, 25, 25);		//自身のサイズ
	static constexpr Vector3 SpawnOffset = Vector3(0, 50, 0);	//オフセット
	static constexpr float EffectDrawTime = 6.5f;				//エフェクトを表示する時間
		
	float m_elapsedTime;	//経過時間

	Vector3 SnapPosition(const Vector3& playerPos);

protected:
	virtual void Update() override;		//更新
	virtual void Active() override;		//効果の発動
	
public:
	//コンストラクタ
	WindGimmick(const Vector3& position, Player* m_player);
};