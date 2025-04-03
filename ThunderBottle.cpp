#include "ThunderBottle.h"
#include "Model.h"

//�R���X�g���N�^
ThunderBottle::ThunderBottle(const Vector3& position, const Vector3& forward, const Quaternion& rotation) :
	Bottle(position),
	m_forward(forward)
{
	m_model = new Model("Resource/bottle_thunder.mv1");
	m_transform.scale *= Scale;
	m_transform.position = position;
	m_transform.rotation = rotation;
}

//�X�V
void ThunderBottle::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	m_transform.position += Bottle::Throw(m_forward);
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