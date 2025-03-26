#include "Actor.h"
#include "Model.h"
#include "Animation.h"

//�R���X�g���N�^
Actor::Actor(const char* name, const char* modelFileName, const Vector3& position) :
	m_name(name),
	m_model(nullptr)
{
	//�t�@�C���p�X���w�肳��Ă���΃��[�h����
	if (modelFileName)
	{
		m_model = new Model(modelFileName);
	}
}

//���\�[�X�̓ǂݍ���
void Actor::Load()
{
	//���f��
	if (m_model)
	{
		m_model->Load();
	}

	//�Փ˔���̒ǉ�
}

//���\�[�X�̉��
void Actor::Release()
{
	//���f��
	if (m_model)
	{
		delete m_model;
		m_model = nullptr;
	}
	
	//�Փ˔���V�X�e�����珜�O����
}

//�`��
void Actor::Draw()
{
	//���f��
	if (m_model)
	{
		m_model->Draw(m_transform);
	}

}

//�q�m�[�h���܂ލX�V
void Actor::TreeUpdate()
{
	//�{����Update
	Node::TreeUpdate();
	
	//���f��
	if (m_model)
	{
		m_model->Update();
	}
	
}