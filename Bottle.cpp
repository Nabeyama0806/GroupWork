#include "Bottle.h"
#include "Time.h"

Bottle::Bottle(const Vector3& position) :
	ModelActor("Bottle", nullptr, position),
	m_type(Bottle::Type::Fire)
{

}

Vector3 Bottle::Throw(Vector3& position, float addForce) const
{
	//³‹K‰»
	return position.Normalized() * addForce * Time::GetInstance()->GetDeltaTime() / Mass;
}