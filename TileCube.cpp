#include "TileCube.h"
#include "Model.h"
#include "BoxCollider.h"

TileCube::TileCube(const Vector3& position, const Vector3& size) :
	ModelActor("Wall")
{
	m_model = new Model("Environment/Cube.mv1");

	//�p�����̒���
	m_transform.position = position;

	m_collider = new BoxCollider(size);
}

void TileCube::Update()
{
	//�{���̍X�V
	ModelActor::Update();
}

void TileCube::Draw()
{
	// �{���̕`��
	ModelActor::Draw();
}