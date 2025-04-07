#include "WindGimmick.h"
#include "BoxCollider.h"

WindGimmick::WindGimmick(Vector3 position) :
	ModelActor("Wind")
{
	m_model = new Model("Resource/bottle_wind.mv1");
	m_transform.position = position + SpawnOffset;
	m_transform.scale = Scale;

	//�Փ˔���
	Vector3 colliderScale = ColliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale, ColliderOffset.Scale(m_transform.scale));

	//�G�t�F�N�g
	m_effect = new Effect("Data/wind.efk");
}

void WindGimmick::Update()
{
	//�{���̍X�V
	ModelActor::Update();
	m_effect->Update(m_transform.position);
}

void WindGimmick::Draw()
{
	//�{���̍X�V
	ModelActor::Draw();
	m_effect->Draw();
}