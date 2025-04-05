#include "DxLib.h"
#include "EffectManager.h"

// �R���X�g���N�^
EffectManager::EffectManager()
    : effectResourceHandle(-1)
    , playingEffectHandle(-1)
    , playCount(0)
{
    // ������
    Initialize();

    // �ǂݍ���
    Load();
}

// �f�X�g���N�^
EffectManager::~EffectManager()
{
    // �G�t�F�N�g���\�[�X�̊J��
    // (Effekseer�I�����ɔj�������̂ō폜���Ȃ��Ă�����)
    DeleteEffekseerEffect(effectResourceHandle);
}

// ������
void EffectManager::Initialize()
{
    // DirectX11���g�p����悤�ɂ���B(DirectX9���A�ꕔ�@�\�s��)
    // Effekseer���g�p����ɂ͕K���ݒ肷��B
    SetUseDirect3DVersion(DX_DIRECT3D_11);

    // �����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
    if (Effkseer_Init(EffectParticleLimit) == -1) { DxLib_End(); }

    // �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
    // Effekseer���g�p����ꍇ�͕K���ݒ肷��B
    SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

    // DX���C�u�����̃f�o�C�X���X�g�������̃R�[���o�b�N��ݒ肷��B
    // �E�C���h�E�ƃt���X�N���[���̐؂�ւ�����������ꍇ�͕K�����s����B
    Effekseer_SetGraphicsDeviceLostCallbackFunctions();

    // Z�o�b�t�@��L���ɂ���B
    // Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
    SetUseZBuffer3D(TRUE);

    // Z�o�b�t�@�ւ̏������݂�L���ɂ���B
    // Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
    SetWriteZBuffer3D(TRUE);
}

// �ǂݍ���
void EffectManager::Load()
{
    // �G�t�F�N�g�̃��\�[�X��ǂݍ���
    effectResourceHandle = LoadEffekseerEffect(EffectFilePath, EffectSize);
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="playPosition">�Đ����W</param>
void EffectManager::Update(Vector3 playPosition)
{
    // ����I�ɃG�t�F�N�g���Đ�����
    if (!(playCount % EffectPlayInterval))
    {
        // �G�t�F�N�g���Đ�����B
        playingEffectHandle = PlayEffekseer3DEffect(effectResourceHandle);
    }

    // �Đ��J�E���g��i�߂�
    playCount++;

    // �Đ����̃G�t�F�N�g���ړ�����B
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, playPosition.x, playPosition.y, playPosition.z);

    // Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
    UpdateEffekseer3D();
}

// �`��
void EffectManager::Draw()
{
    // Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
    DrawEffekseer3D();
}
