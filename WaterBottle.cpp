#include "WaterBottle.h"
#include "Model.h"
#include "BoxCollider.h"
#include "Player.h"

//�R���X�g���N�^
WaterBottle::WaterBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle(position, Bottle::Type::Water),
	m_forward(forward),
	m_player(player)
{
	m_model = new Model("Resource/bottle_water.mv1");
	m_transform.scale *= Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

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
	m_player->DestroyBottle();
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