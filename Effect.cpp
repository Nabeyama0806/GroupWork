#include "Effect.h"
#include "EffectManager.h"
#include "DxLib.h"

//コンストラクタ
Effect::Effect(const char* fileName, const int effectSize, const int playInterval) :
    effectHandle(-1),
    playingEffectHandle(-1),
    effectPlayInterval(playInterval),
    playCount(0)
{
    //エフェクトの登録
    effectHandle = EffectManager::GetInstance()->Load(fileName, effectSize);
}

//デストラクタ
Effect::~Effect()
{
    //エフェクトの開放
    DeleteEffekseerEffect(effectHandle);
}

//更新
void Effect::Update(Vector3& position)
{
    //再生中のエフェクトを移動する。
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, position.x, position.y, position.z);
}

//エフェクトを再生する
void Effect::Play(bool loop)
{
    //定期的にエフェクトを再生する
    if (!(playCount % effectPlayInterval))
    {
        playingEffectHandle = PlayEffekseer3DEffect(effectHandle);
    }

    //再生カウントを進める
    if (loop) playCount++;
    else playCount = effectPlayInterval;
}