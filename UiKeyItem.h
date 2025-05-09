#pragma once
#include "SpriteActor.h"
#include "Vector3.h"

class Player;
class Camera;

class UiKeyItem : public SpriteActor
{
private:
	static constexpr Vector3 Offset = Vector3(-80, 80, 0);				//�\��������W
	static constexpr Vector3 Scale = Vector3(0.14f, 0.14f, 0.14f);		//�\������傫��

	//�\������摜�p�^�[��
	enum class TextureType
	{
		None,
		Get,

		Length,
	};

	//�摜�̃t�@�C���p�X
	const char* FilePath[static_cast<int>(TextureType::Length)] =
	{
		"Resource/Texture/uikey_none.png",
		"Resource/Texture/uikey_get.png",
	};

	//�摜�̖��O
	const char* TextureName[static_cast<int>(TextureType::Length)] =
	{
		"None",
		"Get",
	};

	Player* m_player;
	Camera* m_camera;	//�J����
	TextureType m_textureType;

protected:
	virtual void Update() override;		//�X�V
	virtual void Draw() override;		//�`��

public:
	UiKeyItem(Player* player, Camera* camera);	//�R���X�g���N�^
};