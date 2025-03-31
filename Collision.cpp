#include "Collision.h"
#include "Vector3.h"
#include "Transform.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include <cmath>
using std::abs;
using std::powf;

bool Collision::Check(
	const Transform& transform1, const BoxCollider* box1,
	const Transform& transform2, const BoxCollider* box2
	)
{
	//�e��`�̒��S���W�ƃT�C�Y���Z�o
	Vector3 center1 = transform1.position + box1->m_offset;
	Vector3 size1 = box1->m_size;

	Vector3 center2 = transform2.position + box2->m_offset;
	Vector3 size2 = box2->m_size;

	//�e���̒��S���W���m�̋����ƁA�T�C�Y/2�̍��v���r
	if (abs(center1.x - center2.x) <= (size1.x + size2.x) / 2
	&&  abs(center1.y - center2.y) <= (size1.y + size2.y) / 2
	&&  abs(center1.z - center2.z) <= (size1.z + size2.z) / 2)
	{
		return true;
	}
	return false;
}

bool Collision::Check(
	const Transform& transform1, const BoxCollider* box,
	const Transform& transform2, const CircleCollider* circle
	)
{
	//�e��`�Ɖ~�`�̒��S���W�ƃT�C�Y���Z�o
	Vector3 center1 = transform1.position + box->m_offset;
	Vector3 boxSize = box->m_size;

	Vector3 center2 = transform2.position + circle->m_offset;
	int circleSize = circle->m_radius;

	
	return false;
}

bool Collision::Check(
	const Transform& transform1, const CircleCollider* circle1,
	const Transform& transform2, const CircleCollider* circle2
	)
{
	//�e�~�`�̒��S���W�ƃT�C�Y���Z�o
	Vector3 center1 = transform1.position + circle1->m_offset;
	int size1 = circle1->m_radius;

	Vector3 center2 = transform2.position + circle2->m_offset;
	int size2 = circle2->m_radius;

	// 1��2�̒��S���W�̍��̓��
	float distanceX2 = abs(center1.x - center2.x) * abs(center1.x - center2.x);
	float distanceY2 = abs(center1.y - center2.y) * abs(center1.y - center2.y);
	float distanceZ2 = abs(center1.z - center2.z) * abs(center1.z - center2.z);

	// �Εӂ̒����̓��
	float hypotenuseX = distanceX2 + distanceY2;
	float hypotenuseY = distanceY2 + distanceZ2;
	float hypotenuseZ = distanceZ2 + distanceX2;

	// 2�̔��a�̍��v�̓��
	float sumSize = abs(size1 + size2) * abs(size1 + size2);

	//�~�`�̒��S�̋��������a��𑫂���������菬�������ǂ���
	if (hypotenuseX <= sumSize && hypotenuseY <= sumSize &&	hypotenuseZ <= sumSize)
	{
		return true;
	}
	return false;
}