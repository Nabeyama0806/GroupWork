#pragma once
#include "Node.h"
#include "UiTransform.h"
#include "Sprite.h"
#include <string>

class Collider;
class Camera;

class UiActor : public Node
{
protected: 
	std::string m_name;		//�I�u�W�F�N�g��
	UiTransform m_uiTransform;	//�p�����
	Sprite* m_sprite;		//2D�摜
	Collider* m_collider;	//�Փ˔���̌`��

	virtual void Load() override;	//���\�[�X�̓ǂݍ���
	virtual void Release() override;	//���\�[�X�̊J��
	virtual void Draw() override;	//���\�[�X�̊J��

public:
	//�R���X�g���N�^
	UiActor(const char* name,
		const char* textureName = nullptr,
		const Vector2& position = Vector2()
	);

	//�q�m�[�h���܂ލX�V
	virtual void TreeUpdate() override;

	//�p���̎擾
	const UiTransform& GetUiTransform() const
	{
		return m_uiTransform;
	}

	//���W�̎擾
	const Vector2& GetPosition() const
	{
		return m_uiTransform.position;
	}

	//���O�̎擾
	const std::string& GetName()const
	{
		return m_name;
	}

	//�Փ˔���̌`��擾
	const Collider* GetCollider() const
	{
		return m_collider;
	}

	//�Փ˃C�x���g
	virtual void OnCollision(const UiActor* other) {}

};