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
    EffectManager::GetInstance()->Load(fileName);
}

//デストラクタ
Effect::~Effect()
{
    //エフェクトの開放
    DeleteEffekseerEffect(effectHandle);
}

//読み込み
void Effect::Load(const char* fileName)
{
    //エフェクトのリソースを読み込む
    effectHandle = EffectManager::GetInstance()->Load(fileName);
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

    //本来の更新
    EffectManager::GetInstance()->Update(position);
}

//描画
void Effect::Draw()
{
    //本来の描画
    EffectManager::GetInstance()->Draw();
}

void Effect::Play(const char* effectName)
{

}