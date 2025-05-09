#include "UiKeyItem.h"
#include "Sprite.h"
#include "Player.h"
#include "Camera.h"

//�R���X�g���N�^
UiKeyItem::UiKeyItem(Player* player, Camera* camera) : 
	SpriteActor("UiKey"),
	m_player(player),
	m_camera(camera),
	m_textureType(TextureType::None)
{
	//�p�����
	m_transform.position = Screen::TopRight + Offset;
	m_transform.scale = Scale;

	//�摜�̓o�^
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(TextureType::Length); ++i)
	{
		m_sprite->Register(TextureName[i], SpriteAnimation(FilePath[i]));
	}
	m_sprite->Play(TextureName[static_cast<int>(m_textureType)]);
}

//�X�V
void UiKeyItem::Update()
{
	//�{���̍X�V
	SpriteActor::Update();

	//���̎擾�󋵂ŕ\������摜��؂�ւ���
	m_textureType = m_player->GetIsKey() ? TextureType::Get : TextureType::None;
	m_sprite->Play(TextureName[static_cast<int>(m_textureType)]);
}

//�`��
void UiKeyItem::Draw()
{
	//�J�������v���C���[�𒍎����Ă��Ȃ���Ε`�悵�Ȃ�
	if (!m_camera->GetIsPlayer()) return;
	//�X�e�[�W�Ɍ������݂��ĂȂ���Ε`�悵�Ȃ�
	if (!m_player->GetIsExistenceKey()) return;

	//�{���̕`��
	SpriteActor::Draw();
}