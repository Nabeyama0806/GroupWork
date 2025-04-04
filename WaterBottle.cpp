#include "WaterBottle.h"
#include "Model.h"
#include "BoxCollider.h"

//�R���X�g���N�^
WaterBottle::WaterBottle(const Vector3& position, const Vector3& forward, const Quaternion& rotation) :
	Bottle(position),
	m_forward(forward)
{
	m_model = new Model("Resource/bottle_water.mv1");
	m_transform.scale *= Scale;
	m_transform.position = position;
	m_transform.rotation = rotation;

	m_collider = new BoxCollider(ColliderSize);
}

//�X�V
void WaterBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	m_transform.position += Bottle::Throw(m_forward);
}

//�`��
void WaterBottle::Draw()
{
	//�{���̕`��
	ModelActor::Draw();
}

//���ʔ���
void WaterBottle::ActiveEffect()
{
	//���g���폜
	Destroy();
}

//�Փ˃C�x���g
void WaterBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() != "Player" && other->GetName() != "Bottle")
	{
		ActiveEffect();
	}
}