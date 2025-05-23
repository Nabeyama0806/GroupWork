#include "KeyGimmick.h"
#include "BoxCollider.h"
#include "SoundManager.h"
#include "Effect.h"
#include "Player.h"
#include "Time.h"

//�R���X�g���N�^
KeyGimmick::KeyGimmick(const Vector3& position, Player* player, bool isFake) :
	GimmickBase("KeyBlock", position),
	m_player(player),
	m_destroyWall(false),
	m_isFake(isFake),
	m_destroyTime(DestroyTime)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/key_block.mv1");
	m_effect = new Effect("Resource/Effect/open.efk", 10, 70);

	//�p�����
	m_transform.position = position;
	m_transform.scale = Scale;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
}

//���ʂ̔���
void KeyGimmick::Active()
{
	if (m_destroyWall)
	{
		m_destroyTime -= Time::GetInstance()->GetDeltaTime();
		m_effect->Play();

		if (m_destroyTime <= 0) Destroy();
	}
}

//�Փ˃C�x���g
void KeyGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Player" || other->GetName() == "PlayerFoot")
	{
		if (m_player->GetIsKey())
		{
			//���g���U���Ȃ�v���C���[�̍��W��߂�
			if (m_isFake)
			{
				m_player->SetSpawnPosition(m_player->GetSpawnPos());
				Destroy();
			}
			else
			{
				m_destroyWall = true;
				m_player->UseKey();

				//���ʉ�
				SoundManager::Play("Resource/sound/se_open.mp3");
			}
		}
	}
}