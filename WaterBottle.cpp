#include "WaterBottle.h"
#include "Model.h"

//コンストラクタ
WaterBottle::WaterBottle(const Vector3& position) :
	Bottle(position)
{
	m_model = new Model("Resource/bottle_water.mv1");
	m_transform.scale *= Scale;
}

//更新
void WaterBottle::Update()
{
	//本来の更新
	ModelActor::Update();
}

//描画
void WaterBottle::Draw()
{
	//本来の描画
	ModelActor::Draw();
}

//効果発動
void WaterBottle::ActiveEffect()
{
	//自身を削除
	Destroy();
}