#include "Player.h"
#include "PlayerFoot.h"
#include "Bottle.h"
#include "FireBottle.h"
#include "ThunderBottle.h"
#include "WaterBottle.h"
#include "WindBottle.h"
#include "UiBottle.h"
#include "Input.h"
#include "Time.h"
#include "SoundManager.h"
#include "BoxCollider.h"
#include "ModelLoader.h"
#include "ModelAnimation.h"
#include "CreateMap.h"
#include "Camera.h"

//�R���X�g���N�^
Player::Player(Camera* camera, UiBottle* uiBottle) :
	ModelActor("Player"),
	m_camera(camera),
	m_uiBottle(uiBottle),
	m_createBottle(false),
	m_holdMove(0, 0, 0),
	m_isExistenceKey(false),
	m_getKey(false),
	m_canWindBottleThrow(true),
	m_onWallHit(false),
	m_isGoal(false),
	m_getBottleFlag(15),
	m_playerFoot(nullptr),
	m_map(nullptr)
{
	//�p�����̒���
	m_transform.scale = Scale;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
	m_playerFoot = new PlayerFoot(this, m_transform.position);
	AddChild(m_playerFoot, false);
}

//�X�V
void Player::Update()
{
	// �S�[�������瓮���𕕂���
	if (m_isGoal) return;

	if (!m_camera->GetIsPlayer())
	{
		//�{���̍X�V
		ModelActor::Update();
		return;
	}

	//�ړ�
	Move();

	//���N���b�N�Ń{�g���𐶐�
	if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT))
	{
		CreateBottle();
	}

	m_uiBottle->SetGetBottleFlag(m_getBottleFlag, m_canWindBottleThrow);
	m_uiBottle->SetCreateBottle(m_createBottle);
}

//�w�肳�ꂽ�{�g���̍쐬
void Player::CreateBottle()
{
	if (m_createBottle) return;

	if (m_uiBottle->GetType() == Bottle::Type::Wind && !m_canWindBottleThrow) return;
	if (!(m_getBottleFlag & (1 << static_cast<int>(m_uiBottle->GetType())))) return;

	switch (m_uiBottle->GetType())
	{
	case Bottle::Type::Fire:
		AddChild(new FireBottle(m_camera->GetCameraPos(), m_camera->GetForward(), this));
		break;

	case Bottle::Type::Thunder:
		AddChild(new ThunderBottle(m_camera->GetCameraPos(), m_camera->GetForward(), this));
		break;

	case Bottle::Type::Water:
		AddChild(new WaterBottle(m_camera->GetCameraPos(), m_camera->GetForward(), this));
		break;

	case Bottle::Type::Wind:
		AddChild(new WindBottle(m_camera->GetCameraPos(), m_camera->GetForward(), this));
		m_canWindBottleThrow = false;
		break;

	default:
		break;
	}

	m_createBottle = true;
	SoundManager::Play("Resource/sound/se_bottle_create.mp3");
}

//�ړ�
void Player::Move()
{
	//���͕����̎擾
	Vector3 move = Vector3(0, 0, 0);
	float speedRate = 1.0f;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_LSHIFT))	speedRate = DashSpeed;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_W)) move.z = 1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_S)) move.z = -1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_D)) move.x = 1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_A)) move.x = -1;

	//�J�����̐��ʃx�N�g�����쐬
	Vector3 cameraForward = Vector3::Scale(m_camera->GetForward(), Vector3(1, 0, 1)).Normalized();

	//�J�����̌������l�������ړ���
	move = cameraForward * move.z + m_camera->GetRight() * move.x;

	//�����Ă��鎞
	if (!move.IsZero())
	{
		//�ړ�
		move.Normalize();
		m_holdMove = move * Speed * speedRate;
		m_transform.position += m_holdMove;

		//��]
		m_transform.rotation = Quaternion::Slerp(
			m_transform.rotation,
			Quaternion::LookRotation(move),
			0.2f
		);
	}

	// �d��
	if (!m_playerFoot->GetIsGronded())
	{
		m_holdMove.y = GravityScale;
		m_transform.position.y -= m_holdMove.y;
	}
	
	//��������
	if (m_transform.position.y < -500)
	{
		m_getKey = false;
		m_map->LoadMap(false);
	}

	m_onWallHit = false;
}

void Player::Draw()
{
	if (!m_camera->GetIsPlayer())
	{
		//�{���̍X�V
		ModelActor::Draw();
	}

#ifdef _DEBUG	
	// X
	DrawLine3D(
		VGet(m_transform.position.x, m_transform.position.y, m_transform.position.z),
		VGet(m_transform.position.x + 30, m_transform.position.y, m_transform.position.z),
		GetColor(255, 0, 0));

	// Y
	DrawLine3D(
		VGet(m_transform.position.x, m_transform.position.y, m_transform.position.z),
		VGet(m_transform.position.x, m_transform.position.y + 30, m_transform.position.z),
		GetColor(255, 255, 0));

	// Z
	DrawLine3D(
		VGet(m_transform.position.x, m_transform.position.y, m_transform.position.z),
		VGet(m_transform.position.x, m_transform.position.y, m_transform.position.z + 30),
		GetColor(0, 0, 255));
#endif
}

//�Փ˃C�x���g
void Player::OnCollision(const ModelActor* other)
{
	//��
	if (other->GetName() == "Wall" || other->GetName() == "Fire" || 
		other->GetName() == "KeyBlock" || other->GetName() == "Transparent")
	{
		// �ǂ̃T�C�Y
		Vector3 colCenter = other->GetPosition();

		// �v���C���[���������Ă���ǂ��ǂ̕�����
		float distanceX = abs(colCenter.x - abs(m_transform.position.x - m_holdMove.x));
		float distanceZ = abs(colCenter.z - abs(m_transform.position.z - m_holdMove.z));
		distanceX > distanceZ ? 
			m_transform.position.x -= m_holdMove.x:
			m_transform.position.z -= m_holdMove.z;

		m_onWallHit = true;
		m_playerFoot->FollowPlayer();
	}

	if (other->GetName() == "Key")
	{
		m_getKey = true;
	}

	if (other->GetName() == "Goal")
	{
		m_isGoal = true;
	}
}