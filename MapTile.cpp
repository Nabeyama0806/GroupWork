#include "MapTile.h"
#include "FireGimmick.h"
#include "WaterGimmick.h"
#include "WindGimmick.h"
#include "TileCube.h"

MapTile::MapTile(CreateMap::TileType tile, const Vector3& pos, const Vector3& size) :
	ModelActor("Tile"),
	m_tile(tile),
	m_size(size)
{
	Create(pos);
}

void MapTile::Create(const Vector3& position)
{
	switch (m_tile)
	{
	case CreateMap::TileType::None:
		break;

	case CreateMap::TileType::Fire:
		AddChild(new FireGimmick(position, Vector3(25, 25, 25)));
		break;

	case CreateMap::TileType::Water:
		AddChild(new WaterGimmick(position, Vector3(25, 25, 25)));
		break;

	case CreateMap::TileType::PowerUp:
		/*
		AddChild(new PowerUp(position));
		*/
		break;

	case CreateMap::TileType::Wall:
		AddChild(new TileCube(position, m_size));
		break;

	default:
		break;
	}
}