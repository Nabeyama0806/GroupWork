#include "Goal.h"
#include "Model.h"
#include "CreateMap.h"
#include "BoxCollider.h"

Goal::Goal(const Vector3& position, CreateMap* map) : 
	ModelActor("Goal"), 
	m_map(map)
{
	m_model = new Model("Resource/Model/goal.mv1");

	//épê®èÓïÒÇÃí≤êÆ
	m_transform.position = position;

	m_collider = new BoxCollider(Vector3(100, 100, 100));
}