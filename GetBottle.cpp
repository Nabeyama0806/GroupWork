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
   // ���f��  
   m_model = new Model(fileName);  
   // �p�����  
   m_transform.position = spawnPos + SpawnOffset;  
   m_transform.scale = Scale;  
   // �Փ˔���  
   m_collider = new BoxCollider(ColliderScale);  
}

void GetBottle::OnCollision(const ModelActor* other)
{
	// �v���C���[�ƏՓ˂����玩�g���폜  
	if (other->GetName() == "Player")
	{
		// �v���C���[�Ƀ{�g����n��
		m_player->GetElement(m_type);
		Destroy();

		//���ʉ�
		SoundManager::Play("Resource/sound/se_bottle_get.mp3");
	}
}