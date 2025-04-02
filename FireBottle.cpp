#include "FireBottle.h"
#include "Time.h"
#include "Model.h"

//�R���X�g���N�^
FireBottle::FireBottle(const Vector3& position) :
	Bottle(position)
{
	m_model = new Model("Resource/bottle_fire.mv1");
	m_transform.scale *= Scale;
	m_transform.position = position;
}

//�X�V
void FireBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();
}

//�`��
void FireBottle::Draw()
{
	//�{���̕`��
	ModelActor::Draw();
}

//���ʔ���
void FireBottle::ActiveEffect()
{
	//���g���폜
	Destroy();
}