#include "TileCube.h"
#include "Model.h"
#include "BoxCollider.h"

TileCube::TileCube(const Vector3& position, const Vector3& size) :
	ModelActor("Wall")
{
	m_model = new Model("Environment/Cube.mv1");

	//姿勢情報の調整
	m_transform.position = position;

	m_collider = new BoxCollider(size);
}

void TileCube::Update()
{
	//本来の更新
	ModelActor::Update();
}

void TileCube::Draw()
{
	// 本来の描画
	ModelActor::Draw();
}