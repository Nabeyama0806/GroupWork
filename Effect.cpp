#include "Effect.h"
#include "EffectManager.h"
#include "DxLib.h"

//�R���X�g���N�^
Effect::Effect(const char* fileName) :
    effectHandle(-1),
    playingEffectHandle(-1),
    playCount(0)
{
    //�G�t�F�N�g�̓o�^
    effectHandle = EffectManager::GetInstance()->Load(fileName, EffectSize);
}

//�f�X�g���N�^
Effect::~Effect()
{
    //�G�t�F�N�g�̊J��
    DeleteEffekseerEffect(effectHandle);
}

//�X�V
void Effect::Update(Vector3& position)
{
    //����I�ɃG�t�F�N�g���Đ�����
    if (!(playCount % EffectPlayInterval))
    {
        //�G�t�F�N�g���Đ�����B
        playingEffectHandle = PlayEffekseer3DEffect(effectHandle);
    }

    //�Đ��J�E���g��i�߂�
    playCount++;

    //�Đ����̃G�t�F�N�g���ړ�����B
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, position.x, position.y, position.z);
}