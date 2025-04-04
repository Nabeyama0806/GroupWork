#include "WindBottle.h"
#include "Model.h"
#include "BoxCollider.h"
#include "Player.h"

//�R���X�g���N�^
WindBottle::WindBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle(position, Bottle::Type::Wind),
	m_forward(forward),
	m_player(player)
{
	m_model = new Model("Resource/bottle_wind.mv1");
	m_transform.scale *= Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	m_collider = new BoxCollider(ColliderSize);
}

//�X�V
void WindBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	m_transform.position += Bottle::Throw(m_forward);
}

//�`��
void WindBottle::Draw()
{
	//�{���̕`��
	ModelActor::Draw();
}

//���ʔ���
void WindBottle::ActiveEffect()
{
	m_player->DestroyBottle();
	//���g���폜
	Destroy();
}

//�Փ˃C�x���g
void WindBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() != "Player" && other->GetName() != "Bottle")
	{
		ActiveEffect();
	}
}