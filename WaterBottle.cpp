#include "WaterBottle.h"
#include "Model.h"

//�R���X�g���N�^
WaterBottle::WaterBottle(const Vector3& position) :
	Bottle(position)
{
	m_model = new Model("Resource/bottle_water.mv1");
	m_transform.scale *= Scale;
}

//�X�V
void WaterBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();
}

//�`��
void WaterBottle::Draw()
{
	//�{���̕`��
	ModelActor::Draw();
}

//���ʔ���
void WaterBottle::ActiveEffect()
{
	//���g���폜
	Destroy();
}