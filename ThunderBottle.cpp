#include "ThunderBottle.h"
#include "Model.h"

//�R���X�g���N�^
ThunderBottle::ThunderBottle(const Vector3& position) :
	Bottle(position)
{
	m_model = new Model("Resource/bottle_thunder.mv1");
	m_transform.scale *= Scale;
}

//�X�V
void ThunderBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();
}

//�`��
void ThunderBottle::Draw()
{
	//�{���̕`��
	ModelActor::Draw();
}

//���ʔ���
void ThunderBottle::ActiveEffect()
{
	//���g���폜
	Destroy();
}