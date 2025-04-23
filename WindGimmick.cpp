#include "WindGimmick.h"
#include "SoundManager.h"
#include "Player.h"
#include "BoxCollider.h"
#include "Time.h"

//�R���X�g���N�^
WindGimmick::WindGimmick(const Vector3& position, Player* player) :
	GimmickBase("Wind", position),
	m_elapsedTime(0)
{
	//�G�t�F�N�g
	m_effect = new Effect("Resource/Effect/wind.efk", 10, 130);
	m_effectOffset = Vector3(0, -50, 0);

	//�p�����
	m_transform.position = SnapPosition(position + SpawnOffset);
	m_transform.scale = Scale;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);

	//�v���C���[�̎擾
	m_player = player;

	//���ʉ�
	SoundManager::Play("Resource/sound/se_gimmick_wind.mp3");
}

//�X�V
void WindGimmick::Update()
{
	//�{���̍X�V
	GimmickBase::Update();

	//���Ԍo�߂ō폜
	m_elapsedTime += Time::GetInstance()->GetDeltaTime();
	if (EffectDrawTime < m_elapsedTime)
	{
		m_player->SetCanWindBottleThrow();
		Destroy();
	}
}

//���ʂ̔���
void WindGimmick::Active()
{
	//���G�t�F�N�g�̕\��
	m_effect->Play();
}

Vector3 WindGimmick::SnapPosition(const Vector3& playerPos)
{
	//��}�X�̃T�C�Y
	const int TileSize = 100;

	//�����_���Ȃ�
	Vector3 position;
	int posX = static_cast<int>(playerPos.x);
	int posY = static_cast<int>(playerPos.y);
	int posZ = static_cast<int>(playerPos.z);

	//�ڐG�����}�X�ڂ̍��W���Z�o
	position.x = static_cast<float>(posX % TileSize > 50 ? posX / TileSize * TileSize + TileSize : posX / TileSize * TileSize);
	position.y = static_cast<float>(posY / TileSize * TileSize);
	position.z = static_cast<float>(posZ % TileSize > 50 ? posZ / TileSize * TileSize + TileSize : posZ / TileSize * TileSize);
	
	return position;
}