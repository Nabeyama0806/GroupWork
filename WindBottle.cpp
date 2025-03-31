#include "WindBottle.h"
#include "Model.h"

//�R���X�g���N�^
WindBottle::WindBottle(Vector3& position, Vector3& addForce) :
	Bottle(position)
{
	m_model = new Model("Resource/honou�|�[�V����.mv1");

	m_addForce = addForce;
}

//�X�V
void WindBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	//������
	Throw(m_transform.position, m_addForce);
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