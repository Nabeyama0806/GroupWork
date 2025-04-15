#include "Bottle.h"
#include "Player.h"
#include "Time.h"

Bottle::Bottle(const char* bottleName, const Vector3& position, const Vector3& forward, Player* player) :
	ModelActor(bottleName, nullptr, position),
	m_player(player),
	m_forward(forward)
{

}

void Bottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	//������
	m_transform.position += Throw(m_forward);

	if (m_transform.position.y < -500)
	{
		ActiveEffect();
	}
}

void Bottle::ActiveEffect()
{
	//���g���폜
	m_player->DestroyBottle();
	Destroy();
}

Vector3 Bottle::Throw(Vector3& position) const
{
	//���K��
	position.y -= Gravity;
	return position.Normalized() * AddForce * Time::GetInstance()->GetDeltaTime() / Mass;
}