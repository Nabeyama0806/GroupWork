#pragma once
#include <EffekseerForDXLib.h> //�G�t�F�N�V�A�t�@�C��
#include "Vector3.h"

// �G�t�F�N�g�Ǘ��N���X
class EffectManager
{
private:
	static constexpr int EffectParticleLimit = 20000;	// ��ʂɕ\���ł���ő�p�[�e�B�N����

public:
	//�V���O���g��
	static EffectManager* GetInstance()
	{
		static EffectManager instance;
		return &instance;
	}

	void Initialize();					// ������
	int Load(const char* filePath);		// �ǂݍ���
	void Update(const Vector3& playPosition);	// �X�V
	void Draw();						// �`��
};