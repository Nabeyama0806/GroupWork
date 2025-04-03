#include "Bottle.h"
#include "Time.h"

Bottle::Bottle(const Vector3& position) :
	ModelActor("Bottle", nullptr, position),
	m_type(Bottle::Type::Fire)
{

}

Vector3 Bottle::Throw(Vector3& position) const
{
	//³‹K‰»
	position.y -= Gravity;
	return position.Normalized() * AddForce * Time::GetInstance()->GetDeltaTime() / Mass;
}