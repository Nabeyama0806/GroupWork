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
	int mouseHweel = Input::GetInstance()->GetMouseHweelRot();
	if (mouseHweel < 0)
	{
		m_select == static_cast<int>(Bottle::Type::Length) - 1 ?
			m_select = static_cast<int>(Bottle::Type::Fire) :
			m_select++;
	}
	if(mouseHweel > 0)
	{
		m_select == static_cast<int>(Bottle::Type::Fire) ?
			m_select = static_cast<int>(Bottle::Type::Length) - 1 :
			m_select--;
	}

	m_type = static_cast<Bottle::Type>(m_select);
	m_sprite->Play(TextureName[m_select]);

	//���N���b�N�Ń{�g���𐶐�
	if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT))
	{
		switch (m_type)
		{
		case Bottle::Type::Fire:
			AddChild(new FireBottle(m_player->GetPosition()));
			break;

		case Bottle::Type::Thunder:
			AddChild(new ThunderBottle(m_player->GetPosition()));
			break;

		case Bottle::Type::Water:
			AddChild(new WaterBottle(m_player->GetPosition()));
			break;

		case Bottle::Type::Wind:
			AddChild(new WindBottle(m_player->GetPosition()));
			break;

		default:
			break;
		}
	}
}

//�`��
void UiBottle::Draw()
{
	//�{���̕`��
	SpriteActor::Draw();
}