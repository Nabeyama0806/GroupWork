#include "UiActor.h"

//�R���X�g���N�^
UiActor::UiActor(const char* name, const char* textureName, const Vector2& position) :
	m_name(name),
	m_sprite(nullptr),
	m_collider(nullptr)
{
	m_uiTransform.position = position;

	//�摜���ݒ肳��Ă���΃X�v���C�g���N��
	if (textureName)
	{
		m_sprite = new Sprite();
		m_sprite->Register(textureName);
	}
}
//���\�[�X�̓ǂݍ���
void UiActor::Load()
{
	if (m_sprite)
	{
		m_sprite->Load();
	}

}

//���\�[�X�̉��
void UiActor::Release()
{
	if (m_sprite)
	{
		delete m_sprite;
		m_sprite = nullptr;
	}
}

//�`��
void UiActor::Draw()
{
	if (m_sprite)
	{
		m_sprite->Draw(m_uiTransform);
	}
}

//�q�m�[�h���܂ލX�V
void UiActor::TreeUpdate()
{
	//Node�{����TreeUpdate
	Node::TreeUpdate();

	//�X�v���C�g�̍X�V
	if (m_sprite)
	{
		m_sprite->Update();
	}
}