#pragma once
#include "SpriteActor.h"
#include "Bottle.h"

class Player;
class Camera;
class Instructions;

class UiBottle : public SpriteActor
{
private:
	static constexpr Vector3 SizeOffset = Vector3(0.07f, 0.07f, 0.07f);
	static constexpr Vector3 ScreenOffset = Vector3(-140, -140, 0);
	static constexpr Vector3 SubBottleOffset = Vector3(110, 0, 0);	//���ƑO�̑����̈ʒu�I�t�Z�b�g

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

	Sprite* m_crossImg;	// �g�p�s���̉摜
	Sprite* m_nextImg;	//���̑����̉摜
	Sprite* m_prevImg;	//�O�̑����̉摜
	Instructions* m_instructions;
	Transform m_nextTransform;	//���̑����̈ʒu
	Transform m_prevTransform;	//�O�̑����̈ʒu

	Camera* m_camera;
	Bottle::Type m_type;	//���g�̑���
	int m_select;			//�I�����Ă��鑮��
	int m_getBottleFlag;	//�{�g���������Ă��邩�ǂ���
	bool m_crossDrawFlag;	//�\���̕`��t���O
	bool m_canWind;			// ���r�𓊂���邩�ǂ���

	int SelectBottle(int select)
	{
		int bottleNum = select;
		if (bottleNum > static_cast<int>(Bottle::Type::Length) - 1) bottleNum = static_cast<int>(Bottle::Type::Fire);
		else if (bottleNum < static_cast<int>(Bottle::Type::Fire)) bottleNum = static_cast<int>(Bottle::Type::Length) - 1;
		return bottleNum;
	};

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	UiBottle(Camera* camera, Instructions* instructions);

	//�I������Ă���{�g���̎擾
	Bottle::Type GetType()
	{
		return m_type;
	}

	void SetGetBottleFlag(int getBottleFlag, bool canWind)
	{
		m_getBottleFlag = getBottleFlag;
		m_canWind = canWind;
	}
};
