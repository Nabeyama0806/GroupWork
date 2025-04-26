#include "WindBottle.h"
#include "WindGimmick.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//�R���X�g���N�^
WindBottle::WindBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("WindBottle", position, forward, player),
	m_forward(forward),
	m_holdMove(0,0,0)
{
	//���f��
	m_model = new Model("Resource/Model/bottle_wind.mv1");

	//�v���C���[�̎擾
	m_player = player;

	//�p�����
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize.Scale(Scale));
}

void WindBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	//������
	m_holdMove = Throw(m_forward);
	m_transform.position += m_holdMove;

	if (m_transform.position.y < -300)
	{
		DestroyBottle();
	}
}

void WindBottle::DestroyBottle()
{
	Bottle::DestroyBottle();
	m_player->SetCanWindBottleThrow();
}

//�Փ˃C�x���g
void WindBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Wall")
	{
		m_player->AddChild(new WindGimmick(m_transform.position - m_holdMove, m_player));
	}

	std::string hit = other->GetName();
	if (hit != "Player" && hit != "Bottle" && hit != "WaterGimmickEnd" &&
		hit != "Transparent" && hit != "PlayerFoot")
	{
		// ���g�̍폜
		Bottle::DestroyBottle();
		if (other->GetName() != "Wall") m_player->SetCanWindBottleThrow();
	}
}