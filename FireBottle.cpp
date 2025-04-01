#include "FireBottle.h"
#include "Model.h"

//コンストラクタ
FireBottle::FireBottle(const Vector3& position) :
	Bottle(position)
{
	m_model = new Model("Resource/bottle_fire.mv1");
	m_transform.scale *= Scale;
}

//更新
void FireBottle::Update()
{
	//本来の更新
	ModelActor::Update();
}

//描画
void FireBottle::Draw()
{
	//本来の描画
	ModelActor::Draw();
}

//効果発動
void FireBottle::ActiveEffect()
{
	//自身を削除
	Destroy();
}