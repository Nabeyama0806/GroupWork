#pragma once
#include "SpriteActor.h"
#include "SpriteAnimation.h"

class Instructions : public SpriteActor
{
public:
	enum class Device
	{
		Keyboard,
		Gamepad,

		Length,
	};

private:
	//�摜�z��
	const char* TextureName[static_cast<int>(Device::Length)] =
	{
		"Keyboard",
		"Gamepad",
	};
	const SpriteAnimation TextureData[static_cast<int>(Device::Length)] =
	{
		SpriteAnimation("Resource/Texture/tutorial1.jpg", 1, 1, true),
		SpriteAnimation("Resource/Texture/tutorial2.jpg", 1, 1, true),
	};

	bool m_isDraw; //�\�������ǂ���

protected:
	virtual void Update() override;		//�X�V
	virtual void Draw() override;		//�`��

public:
	//�R���X�g���N�^
	Instructions();

	bool GetIsDraw()
	{
		return m_isDraw;
	}
};
