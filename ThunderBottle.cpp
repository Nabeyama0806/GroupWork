#include "ThunderBottle.h"
#include "Model.h"

//コンストラクタ
ThunderBottle::ThunderBottle(const Vector3& position) :
	Bottle(position)
{
	m_model = new Model("Resource/bottle_thunder.mv1");
	m_transform.scale *= Scale;
}

//更新
void ThunderBottle::Update()
{
	//本来の更新
	ModelActor::Update();
}

//描画
void ThunderBottle::Draw()
{
	//本来の描画
	ModelActor::Draw();
}

//効果発動
void ThunderBottle::ActiveEffect()
{
	//自身を削除
	Destroy();
}