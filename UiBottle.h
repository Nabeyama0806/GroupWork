#pragma once
#include "SpriteActor.h"
#include "Bottle.h"

class Player;

class UiBottle : public SpriteActor
{
private:
	static constexpr Vector3 SizeOffset = Vector3(0.07f, 0.07f, 0.07f);
	static constexpr Vector3 ScreenOffset = Vector3(-140, -140, 0);

	//�摜�̃t�@�C���p�X
	const char* FilePath[static_cast<int>(Bottle::Type::Length)] =
	{
		"Resource/Texture/bottle_fire2.png",
		"Resource/Texture/bottle_thunder2.png",
		"Resource/Texture/bottle_water2.png",
		"Resource/Texture/bottle_wind2.png"
	};

	//�摜�̖��O
	const char* TextureName[static_cast<int>(Bottle::Type::Length)] =
	{
		"Fire",
		"Thunder",
		"Water",
		"WInd"
	};

	Sprite* m_crossImg;	//�X�v���C�g

	Bottle::Type m_type;	//���g�̑���
	int m_select;			//�I�����Ă��鑮��
	int m_getBottleFlag;	//�{�g���������Ă��邩�ǂ���
	bool m_crossDrawFlag;	//�\���̕`��t���O

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	UiBottle();

	//�I������Ă���{�g���̎擾
	Bottle::Type GetType()
	{
		return m_type;
	}

	void SetGetBottleFlag(int getBottleFlag)
	{
		m_getBottleFlag = getBottleFlag;
	}
};
