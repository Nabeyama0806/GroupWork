#pragma once
#include "ModelActor.h"
#include "Model.h"
#include "CreateMap.h"
#include "BoxCollider.h"

class Goal : public ModelActor
{
private:
	CreateMap* m_map;	//マップポインタ

public:
	//コンストラクタ
	Goal(const Vector3& position, CreateMap* map) :
		ModelActor("Goal"),
		m_map(map)
	{
		m_model = new Model("Resource/Model/goal.mv1");

		//姿勢情報の調整
		m_transform.position = position;

		m_collider = new BoxCollider(Vector3(100, 100, 100));
	}
};