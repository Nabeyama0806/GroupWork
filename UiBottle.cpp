#include "UiBottle.h"
#include "FireBottle.h"
#include "ThunderBottle.h"
#include "WaterBottle.h"
#include "WindBottle.h"
#include "SoundManager.h"
#include "Sprite.h"
#include "Player.h"
#include "Input.h"

//�R���X�g���N�^
UiBottle::UiBottle() :
	SpriteActor("UiBottle"),
	m_type(Bottle::Type::Fire),
	m_select(0),
	m_crossDrawFlag(false),
	m_getBottleFlag(0),
	m_canWind(true)
{	
	//�摜�̓o�^	
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(Bottle::Type::Length); ++i)
	{
		m_sprite->Register(TextureName[i], SpriteAnimation(FilePath[i]));
	}
	m_sprite->Play(TextureName[m_select]);

	m_crossImg = new Sprite();
	m_crossImg->Register("Cross", SpriteAnimation("Resource/Texture/cross.png"));
	m_crossImg->Play("Cross");
	m_crossImg->Load();

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
	if (mouseHweel != 0)
	{
		if (mouseHweel < 0)
		{
			m_select == static_cast<int>(Bottle::Type::Length) - 1 ?
				m_select = static_cast<int>(Bottle::Type::Fire) :
				m_select++;
		}
		if (mouseHweel > 0)
		{
			m_select == static_cast<int>(Bottle::Type::Fire) ?
				m_select = static_cast<int>(Bottle::Type::Length) - 1 :
				m_select--;
		}
		SoundManager::Play("Resource/sound/se_bottle_select.mp3");
	}

	m_type = static_cast<Bottle::Type>(m_select);
	m_sprite->Play(TextureName[m_select]);

	// �~��`�悷�邩�ǂ���
	m_crossDrawFlag = m_getBottleFlag & (1 << m_select);
	m_crossImg->Update();
}

//�`��
void UiBottle::Draw()
{
	//�{���̕`��
	SpriteActor::Draw();

	//�\���̕`��
	if (!m_crossDrawFlag || m_select == static_cast<int>(Bottle::Type::Wind) && !m_canWind ||
		m_createBottle)
	{
		m_crossImg->Draw(m_transform);
	}
}