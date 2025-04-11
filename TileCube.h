#pragma once
#include "ModelActor.h"

class TileCube : public ModelActor
{
protected:
	virtual void Update() override;
	virtual void Draw() override;

public:
	TileCube(const Vector3& position, const Vector3& size);
};