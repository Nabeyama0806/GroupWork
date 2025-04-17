#include "KeyGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Player.h"
#include "Time.h"

//�R���X�g���N�^
KeyGimmick::KeyGimmick(const Vector3& position, const Vector3& size, Player* player) :
	GimmickBase("KeyBlock", position),
	m_player(player),
	m_destroyWall(false),
	m_destroyTime(DestroyTime)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/(KeyBlock�͂܂��Ȃ�).mv1");
	//m_effect = new Effect("Resource/Effect/fire.efk", 10, 70);

	//�p�����
	m_transform.position = position;
	m_transform.scale = size;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale);
}

//���ʂ̔���
void KeyGimmick::Active()
{
	if (m_destroyWall)
	{
		m_destroyTime -= Time::GetInstance()->GetDeltaTime();
		//m_effect->Play();
		if (m_destroyTime <= 0) Destroy();
	}
}

//�Փ˃C�x���g
void KeyGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Player")
	{
		if (m_player->IsGetKey()) m_destroyWall = true;
	}
}