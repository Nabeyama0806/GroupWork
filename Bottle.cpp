#include "Bottle.h"
#include "Player.h"
#include "Time.h"

void Bottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	//������
	m_transform.position += Throw(m_forward);

	if (m_transform.position.y < -300)
	{
		Destroy();
	}
}

Vector3 Bottle::Throw(Vector3& position) const
{
	//���K��
	position.y -= Gravity;
	return position.Normalized() * AddForce * Time::GetInstance()->GetDeltaTime() / Mass;
}