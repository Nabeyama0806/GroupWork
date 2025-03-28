#include "Player.h"
#include "Input.h"
#include "Time.h"
#include "Quaternion.h"
#include "BoxCollider.h"
#include "ModelLoader.h"
#include "ModelAnimation.h"

//�R���X�g���N�^
Player::Player(Camera* camera) :
	ModelActor("Player"),
	m_camera(camera)
{
	//�A�j���[�V�����̓o�^
	m_model = new Model("Man/Man.mv1");
	for (int i = 0; i < AnimeAmount; ++i)
	{
		//�A�j���[�V�����̃t�@�C���p�X��n��
		m_model->Register(AnimeFileName[i]);
	}

	//�p�����̒���
	m_transform.position = SpawnPos;
	m_transform.scale = Scale;

	/*
	Vector3 colliderScale = Vector3(100, 170, 100) * Scale.x;
	//�Փ˔���
	m_collider = new BoxCollider(colliderScale, Vector3(0,80,0) * Scale.x);
	*/
	m_collider = new BoxCollider(m_transform.scale);
}

//�X�V
void Player::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	//���͕����̎擾
	Vector3 move = Vector3(0, 0, 0);
	float speedRate = 1.0f;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_LSHIFT))	speedRate = DashSpeed;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_W)) move.z =  1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_S)) move.z = -1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_D)) move.x =  1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_A)) move.x = -1;

	//�J�����̐��ʃx�N�g�����쐬
	Vector3 cameraForward = Vector3::Scale(m_camera->GetForward(), Vector3(1, 0, 1)).Normalized();

	//�J�����̌������l�������ړ���
	move = cameraForward * move.z + m_camera->GetRight() * move.x;

	//�ҋ@�A�j���[�V������ݒ�
	int animeIndex = static_cast<int>(Model::Anime::Idle);

	//�����Ă��鎞
	if (!move.IsZero())
	{
		//�ړ�
		move.Normalize();
		m_transform.position += move * Speed * speedRate;

		//��]
		m_transform.rotation = Quaternion::Slerp(
			m_transform.rotation,
			Quaternion::LookRotation(move),
			0.2f);

		//�ړ��A�j���[�V������ݒ�
		animeIndex = static_cast<int>(Model::Anime::Run);
	}
	
	//�ݒ肵���A�j���[�V�����̍Đ�
	m_model->PlayAnime(animeIndex);
}

//�`��
void Player::Draw()
{
	ModelActor::Draw();
}

//�Փ˃C�x���g
void Player::OnCollision(const ModelActor* other)
{
	//��
	if (other->GetName() == "Wall")
	{
		m_transform.position = SpawnPos;
	}
}