#include "WaterBottle.h"
#include "Model.h"

//�R���X�g���N�^
WaterBottle::WaterBottle(Vector3& position, Vector3& addForce) :
	Bottle(position)
{
	m_model = new Model("Resource/honou�|�[�V����.mv1");

	m_addForce = addForce;
}

//�X�V
void WaterBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	//������
	Throw(m_transform.position, m_addForce);
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