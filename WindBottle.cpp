#include "WindBottle.h"
#include "Model.h"

//コンストラクタ
WindBottle::WindBottle(const Vector3& position) :
	Bottle(position)
{
	m_model = new Model("Resource/bottle_wind.mv1");
	m_transform.scale *= Scale;
}

//更新
void WindBottle::Update()
{
	//本来の更新
	ModelActor::Update();
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