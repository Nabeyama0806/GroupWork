#pragma once
#include "ModelActor.h"

class CreateMap;

class Goal : public ModelActor
{
private:
	CreateMap* m_map;	//マップポインタ

public:
	//コンストラクタ
	Goal(const Vector3& position, CreateMap* map);
	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};