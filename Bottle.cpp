#include "Bottle.h"
#include "Player.h"
#include "Time.h"


void Bottle::Update()
{
	//本来の更新
	ModelActor::Update();

	//投げる
	m_transform.position += Throw(m_forward);

	if (m_transform.position.y < -300)
	{
		DestroyBottle();
	}
}

void Bottle::DestroyBottle()
{
	//自身を削除
	m_player->DestroyBottle();
	Destroy();
}

Vector3 Bottle::Throw(Vector3& position) const
{
	//正規化
	position.y -= Gravity;
	return position.Normalized() * AddForce * Time::GetInstance()->GetDeltaTime() / Mass;
}