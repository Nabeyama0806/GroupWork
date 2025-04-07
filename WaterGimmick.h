#pragma once
#include "ModelActor.h"
#include "Model.h"

class WaterGimmick : public ModelActor
{
private:
	static constexpr float DownWater = 10.0f;
	static constexpr float UpWater = 250.0f;
	static constexpr Vector3 ColliderSize = Vector3(4, 4, 4);
	static constexpr float VariableWater = 2.0f;	// �ϓ����鐅�̑��x

	bool waterHeight;	// ���������Ȃ��Ă��邩�ǂ���

protected:
	virtual void Update() override;
	virtual void Draw() override;

public:
	WaterGimmick(const Vector3& spawnPos, const Vector3& scale, const Vector3& offset = Vector3(0, 0, 0));

	virtual void OnCollision(const ModelActor* other) override;
};