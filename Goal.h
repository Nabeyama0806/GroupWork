#pragma once
#include "ModelActor.h"

class CreateMap;

class Goal : public ModelActor
{
private:
	CreateMap* m_map;	//�}�b�v�|�C���^

public:
	//�R���X�g���N�^
	Goal(const Vector3& position, CreateMap* map);
	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};