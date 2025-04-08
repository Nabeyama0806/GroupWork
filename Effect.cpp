#include "Effect.h"
#include "EffectManager.h"
#include "DxLib.h"

//コンストラクタ
Effect::Effect(const char* fileName) :
    effectHandle(-1),
    playingEffectHandle(-1),
    playCount(0)
{
    //エフェクトの登録
    effectHandle = EffectManager::GetInstance()->Load(fileName, EffectSize);
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
    //定期的にエフェクトを再生する
    if (!(playCount % EffectPlayInterval))
    {
        //エフェクトを再生する。
        playingEffectHandle = PlayEffekseer3DEffect(effectHandle);
    }

    //再生カウントを進める
    playCount++;

    //再生中のエフェクトを移動する。
    SetPosPlayingEffekseer3DEffect(playingEffectHandle, position.x, position.y, position.z);
}