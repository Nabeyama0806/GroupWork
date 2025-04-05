#pragma once
#include <EffekseerForDXLib.h> // ��قǎw�肵���G�t�F�N�V�A�t�@�C�����C���N���[�h
#include "Vector3.h"

// �G�t�F�N�g�Ǘ��N���X
class EffectManager
{
public:
	//�V���O���g��
	static EffectManager* GetInstance()
	{
		static EffectManager instance;
		return &instance;
	}

	void Initialize();					// ������
	void Load(const char* filePath);	// �ǂݍ���
	void Update(Vector3 playPosition);	// �X�V
	void Draw();						// �`��
private:
	EffectManager();					// �R���X�g���N�^
	~EffectManager();					// �f�X�g���N�^
	// �萔
	const int	EffectParticleLimit = 20000;				// ��ʂɕ\���ł���ő�p�[�e�B�N����
	const float EffectSize = 1.0f;					// �G�t�F�N�g�̃T�C�Y
	const int	EffectPlayInterval = 300;					// �G�t�F�N�g���Đ��������
	const float	EffectMoveSpeed = 0.2f;					// �G�t�F�N�g���ړ����鑬�x

	// �ϐ�
	int effectResourceHandle;	// �G�t�F�N�g�̃��\�[�X�p
	int playingEffectHandle;	// �Đ����̃G�t�F�N�g�n���h��

	// ����̓���łɂݕK�v�ȕϐ�
	int		playCount;			// �����G�ɍĐ����邽�߂̃J�E���g
};