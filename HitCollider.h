#pragma once
#include "ModelActor.h"
#include "BoxCollider.h"

class HitCollider : public ModelActor
{
public:
	//‹éŒ`‚Ì“–‚½‚è”»’è
	HitCollider(const char* name, const Vector3& position, const Vector3& size) :
		ModelActor(name, nullptr, position)
	{
		m_collider = new BoxCollider(size);
	}
};