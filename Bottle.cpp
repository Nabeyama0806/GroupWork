#include "Bottle.h"
#include "Time.h"

Bottle::Bottle(const char* bottleName, const Vector3& position) :
	ModelActor(bottleName, nullptr, position)
{

}

Vector3 Bottle::Throw(Vector3& position) const
{
	//³‹K‰»
	position.y -= Gravity;
	return position.Normalized() * AddForce * Time::GetInstance()->GetDeltaTime() / Mass;
}