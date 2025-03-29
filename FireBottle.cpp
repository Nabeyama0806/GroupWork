#include "FireBottle.h"
#include "Model.h"

//�R���X�g���N�^
FireBottle::FireBottle(Vector3& position, Vector3& addForce) :
	Bottle(position)
{
	m_model = new Model("Resource/honou�|�[�V����.mv1");

	m_addForce = addForce;
}

//�X�V
void FireBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();
	
	//������
	Throw(m_transform.position, m_addForce);
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