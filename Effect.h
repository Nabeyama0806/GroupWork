#pragma once
#include "Vector3.h"

class Effect
{
private:
	static constexpr float EffectMoveSpeed = 0.2f;				//�G�t�F�N�g���ړ����鑬�x

	int m_effectPlayInterval;		//�G�t�F�N�g���Đ��������
	int m_effectHandle;			//�G�t�F�N�g�̃��\�[�X�p
	int m_playingEffectHandle;	//�Đ����̃G�t�F�N�g�n���h��
	int m_playCount;

public:
	Effect(const char* filePath, const int effectSize, const int playInterval = 150);	// �R���X�g���N�^
	~Effect();						// �f�X�g���N�^

	void Update(Vector3& position);		// �X�V
	void Play(bool loop = true);
};