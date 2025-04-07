#include "WindGimmick.h"
#include "BoxCollider.h"
#include "EffectManager.h"

WindGimmick::WindGimmick(Vector3 position) :
	ModelActor("Wind")
{
	m_model = new Model("Resource/bottle_wind.mv1");
	m_transform.position = position + SpawnOffset;
	m_transform.scale = Scale;

	//�Փ˔���
	Vector3 colliderScale = ColliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale, ColliderOffset.Scale(m_transform.scale));

//	EffectManager::GetInstance()->Load("Resource/Effect/asset/NextSoft01/effect_wind.efk");
	EffectManager::GetInstance()->Load("Data/wind.efk");
}

void WindGimmick::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	EffectManager::GetInstance()->Update(m_transform.position);
}

void WindGimmick::Draw()
{
	//�{���̍X�V
	ModelActor::Draw();
}

void WindGimmick::OnCollision(const ModelActor* other)
{
	
}