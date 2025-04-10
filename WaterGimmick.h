#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class WaterGimmick : public GimmickBase
{
private:
	static constexpr float DownWater = 10.0f;
	static constexpr float UpWater = 250.0f;
	static constexpr float VariableWater = 2.0f;	// •Ï“®‚·‚é…‚Ì‘¬“x

	bool waterHeight;	// …‚ª‚‚­‚È‚Á‚Ä‚¢‚é‚©‚Ç‚¤‚©
	bool isPlay;

protected:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void ActiveEffect() override;

public:
	WaterGimmick(const Vector3& spawnPos, const Vector3& scale, const Vector3& offset = Vector3(0, 0, 0));

	virtual void OnCollision(const ModelActor* other) override;
};