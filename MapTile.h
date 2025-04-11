#pragma once
#include "ModelActor.h"
#include "CreateMap.h"

class MapTile : public ModelActor
{
private:
	const char ModelName[static_cast<int>(CreateMap::TileType::Length)][256] =
	{
		"None",
		"Fire",
		"Water",
		"PowerUp",
		"Resource/bottle_fire.mv1",
	};

	CreateMap::TileType m_tile;
	Vector3 m_size;

	void Create(const Vector3& position);

public:
	MapTile(CreateMap::TileType tile, const Vector3& pos, const Vector3& size);
};