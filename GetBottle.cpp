#include "GetBottle.h"  
#include "BoxCollider.h"  
#include "SoundManager.h"
#include "Model.h"
#include "Player.h"

GetBottle::GetBottle(const Vector3& spawnPos,Player* player, const char* fileName, GetBottle::Type type) :  
	ModelActor("GetBottle"),
	m_player(player),
	m_type(type)
{  
   // モデル  
   m_model = new Model(fileName);  
   // 姿勢情報  
   m_transform.position = spawnPos + SpawnOffset;  
   m_transform.scale = Scale;  
   // 衝突判定  
   m_collider = new BoxCollider(ColliderScale);  
}

void GetBottle::OnCollision(const ModelActor* other)
{
	// プレイヤーと衝突したら自身を削除  
	if (other->GetName() == "Player")
	{
		// プレイヤーにボトルを渡す
		m_player->GetElement(m_type);
		Destroy();

		//効果音
		SoundManager::Play("Resource/sound/se_bottle_get.mp3");
	}
}