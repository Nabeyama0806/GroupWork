#pragma once
#include "GimmickBase.h"
#include "Model.h"

class WaterGimmickEnd : public ModelActor
{
public:
	//コンストラクタ
	WaterGimmickEnd(const Vector3& spawnPos, const Vector3& scale, const Vector3& offset = Vector3(0, 0, 0));
};