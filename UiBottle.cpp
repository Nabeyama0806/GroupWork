#include "UiBottle.h"
#include "Sprite.h"
#include "Input.h"

//�R���X�g���N�^
UiBottle::UiBottle() :
	SpriteActor("UiBottle"),
	m_type(Bottle::Type::Fire),
	m_select(0)
{	
	//�摜�̓o�^	
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(Bottle::Type::Length); ++i)
	{
		m_sprite->Register(TextureName[i], SpriteAnimation(FilePath[i]));
	}

	//�T�C�Y����
	m_transform.scale = SizeOffset;
}

//�X�V
void UiBottle::Update()
{
	//�{���̍X�V
	SpriteActor::Update();

	//�����r���̐؂�ւ�
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_RIGHT))
	{
		//�C���f�b�N�X�𒴂���Ɛ擪�v�f�ɖ߂�
		m_select == static_cast<int>(Bottle::Type::Length) - 1 ?
			m_select = static_cast<int>(Bottle::Type::Fire) :
			m_select++;
	}
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_LEFT))
	{
		//�C���f�b�N�X�𒴂���Ɛ擪�v�f�ɖ߂�
		m_select == static_cast<int>(Bottle::Type::Fire) ?
			m_select++ :
			m_select = static_cast<int>(Bottle::Type::Length) - 1;
	}
}

//�`��
void UiBottle::Draw()
{
	//�{���̕`��
	SpriteActor::Draw();

	//�I�����Ă���摜�̕`��
	m_sprite->Play(TextureName[m_select]);
}