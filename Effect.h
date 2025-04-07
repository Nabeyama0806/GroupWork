#pragma once
#include "Vector3.h"

class Effect
{
private:
	static constexpr int EffectPlayInterval = 150;				//�G�t�F�N�g���Đ��������
	static constexpr float EffectSize = 100.0f;					//�G�t�F�N�g�̃T�C�Y
	static constexpr float EffectMoveSpeed = 0.2f;				//�G�t�F�N�g���ړ����鑬�x

	int effectHandle;			//�G�t�F�N�g�̃��\�[�X�p
	int playingEffectHandle;	//�Đ����̃G�t�F�N�g�n���h��
	int playCount;				

public:
	Effect(const char* filePath);	// �R���X�g���N�^
	~Effect();						// �f�X�g���N�^

	void Load(const char* filePath);	// �ǂݍ���
	void Update(Vector3& position);		// �X�V
	void Draw();						// �`��

	//�A�j���[�V�����̍Đ�
	void Play(const char* effectName);
};