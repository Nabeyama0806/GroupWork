#include "Bottle.h"
#include "Player.h"
#include "Time.h"

void Bottle::Update()
{
	//–{—ˆ‚ÌXV
	ModelActor::Update();

	//“Š‚°‚é
	m_transform.position += Throw(m_forward);

	if (m_transform.position.y < FallEndPos)
	{
		Destroy();
	}
}

Vector3 Bottle::Throw(Vector3& position) const
{
	//³‹K‰»
	position.y -= Gravity;
	return position.Normalized() * AddForce * Time::GetInstance()->GetDeltaTime() / Mass;
}