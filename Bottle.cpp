#include "Bottle.h"
#include "Time.h"

Bottle::Bottle(const Vector3& position, Type type) :
	ModelActor("Bottle", nullptr, position),
	m_type(type)
{

}

Vector3 Bottle::Throw(Vector3& position) const
{
	//³‹K‰»
	position.y -= Gravity;
	return position.Normalized() * AddForce * Time::GetInstance()->GetDeltaTime() / Mass;
}