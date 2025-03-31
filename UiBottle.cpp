#include "UiBottle.h"
#include "FireBottle.h"
#include "ThunderBottle.h"
#include "WaterBottle.h"
#include "WindBottle.h"
#include "Sprite.h"
#include "Player.h"
#include "Input.h"

//�R���X�g���N�^
UiBottle::UiBottle(Player* player) :
	SpriteActor("UiBottle"),
	m_type(Bottle::Type::Fire),
	m_select(0),
	m_player(player)
{	
	//�摜�̓o�^	
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(Bottle::Type::Length); ++i)
	{
		m_sprite->Register(TextureName[i], SpriteAnimation(FilePath[i]));
	}
	m_sprite->Play(TextureName[m_select]);

	//�T�C�Y����
	m_transform.scale = SizeOffset;

	//�\��������W�̒���
	m_transform.position = Screen::BottomRight + ScreenOffset;
}

//�X�V
void UiBottle::Update()
{
	//�{���̍X�V
	SpriteActor::Update();

	//�����r���̐؂�ւ�
	if (Input::GetInstance()->GetMouseHweelRot())
	{
		//�C���f�b�N�X�𒴂���Ɛ擪�v�f�ɖ߂�
		m_select == static_cast<int>(Bottle::Type::Length) - 1 ?
			m_select = static_cast<int>(Bottle::Type::Fire) :
			m_select++;

		m_sprite->Play(TextureName[m_select]);
	}

	//���N���b�N�Ń{�g���𐶐�
	if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT))
	{
		AddChild(new ThunderBottle(m_player->GetPosition()));
	}
}

//�`��
void UiBottle::Draw()
{
	//�{���̕`��
	SpriteActor::Draw();
}