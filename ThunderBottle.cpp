#include "ThunderBottle.h"
#include "Model.h"

//�R���X�g���N�^
ThunderBottle::ThunderBottle(Vector3& position, Vector3& addForce) :
	Bottle(position)
{
	m_model = new Model("Resource/honou�|�[�V����.mv1");

	m_addForce = addForce;
}

//�X�V
void ThunderBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	//������
	Throw(m_transform.position, m_addForce);
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