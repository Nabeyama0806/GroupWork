#include "WindBottle.h"
#include "Model.h"

//�R���X�g���N�^
WindBottle::WindBottle(const Vector3& position) :
	Bottle(position)
{
	m_model = new Model("Resource/bottle_wind.mv1");
	m_transform.scale *= Scale;
}

//�X�V
void WindBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();
}

//�`��
void WindBottle::Draw()
{
	//�{���̕`��
	ModelActor::Draw();
}

//���ʔ���
void WindBottle::ActiveEffect()
{
	//���g���폜
	Destroy();
}