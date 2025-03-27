#include "ModelActor.h"
#include "Model.h"
#include "Animation.h"

//�R���X�g���N�^
ModelActor::ModelActor(const char* name, const char* modelFileName, const Vector3& position) :
	ActorBase(name, modelFileName, position), 
	m_model(nullptr),
	m_collider(nullptr)
{
	//�t�@�C���p�X���w�肳��Ă���΃��[�h����
	if (modelFileName)
	{
		m_model = new Model(modelFileName);
	}
}

//���\�[�X�̓ǂݍ���
void ModelActor::Load()
{
	//���f��
	if (m_model)
	{
		m_model->Load();
	}

	//�Փ˔���̒ǉ�
}

//���\�[�X�̉��
void ModelActor::Release()
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
void ModelActor::Draw()
{
	//���f��
	if (m_model)
	{
		m_model->Draw(m_transform);
	}

}

//�q�m�[�h���܂ލX�V
void ModelActor::TreeUpdate()
{
	//�{����Update
	Node::TreeUpdate();
	
	//���f��
	if (m_model)
	{
		m_model->Update();
	}
}