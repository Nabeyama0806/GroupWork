#include "Effect.h"
#include "EffectManager.h"
#include "DxLib.h"

//�R���X�g���N�^
Effect::Effect(const char* fileName, const int effectSize, const int playInterval) :
    effectHandle(-1),
    playingEffectHandle(-1),
    effectPlayInterval(playInterval),
    playCount(0)
{
    //�G�t�F�N�g�̓o�^
    effectHandle = EffectManager::GetInstance()->Load(fileName, effectSize);
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
    //�Đ����̃G�t�F�N�g���ړ�����B
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, position.x, position.y, position.z);
}

//�G�t�F�N�g���Đ�����
void Effect::Play(bool loop)
{
    //����I�ɃG�t�F�N�g���Đ�����
    if (!(playCount % effectPlayInterval))
    {
        playingEffectHandle = PlayEffekseer3DEffect(effectHandle);
    }

    //�Đ��J�E���g��i�߂�
    if (loop) playCount++;
    else playCount = effectPlayInterval;
}