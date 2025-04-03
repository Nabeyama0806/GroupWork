#include "WindBottle.h"
#include "Model.h"

//コンストラクタ
WindBottle::WindBottle(const Vector3& position, const Vector3& forward, const Quaternion& rotation) :
	Bottle(position),
	m_forward(forward)
{
	m_model = new Model("Resource/bottle_wind.mv1");
	m_transform.scale *= Scale;
	m_transform.position = position;
	m_transform.rotation = rotation;
}

//更新
void WindBottle::Update()
{
	//本来の更新
	ModelActor::Update();

	m_transform.position += Bottle::Throw(m_forward);
}

//描画
void WindBottle::Draw()
{
	//本来の描画
	ModelActor::Draw();
}

//効果発動
void WindBottle::ActiveEffect()
{
	//自身を削除
	Destroy();
}