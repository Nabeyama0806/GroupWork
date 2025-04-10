#pragma once
#include "Vector3.h"

class Effect
{
private:
	static constexpr float EffectMoveSpeed = 0.2f;				//�G�t�F�N�g���ړ����鑬�x

	int effectPlayInterval;		//�G�t�F�N�g���Đ��������
	int effectHandle;			//�G�t�F�N�g�̃��\�[�X�p
	int playingEffectHandle;	//�Đ����̃G�t�F�N�g�n���h��
	int playCount;

public:
	Effect(const char* filePath, const int effectSize, const int playInterval = 150);	// �R���X�g���N�^
	~Effect();						// �f�X�g���N�^

	void Update(Vector3& position);		// �X�V
	void Play(bool loop = true);
};