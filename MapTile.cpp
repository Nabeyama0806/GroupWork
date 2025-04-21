#include "MapTile.h"
#include "FireGimmick.h"
#include "WaterGimmick.h"
#include "WaterGimmickEnd.h"
#include "WindGimmick.h"
#include "TransparentGimmick.h"
#include "KeyGimmick.h"
#include "KeyItem.h"
#include "TileCube.h"
#include "Goal.h"
#include "Player.h"

MapTile::MapTile(CreateMap::TileType tile, const Vector3& pos, const Vector3& size, Player* player, CreateMap* map) :
	ModelActor("Tile"),
	m_tile(tile),
	m_size(size),
	m_player(player),
	m_map(map)
{
	Create(pos);
}

void MapTile::Create(const Vector3& position)
{
	switch (m_tile)
	{
	case CreateMap::TileType::None:
		// ‰½‚à‚È‚µ
		break;

	case CreateMap::TileType::Wall:
		AddChild(new TileCube(position, m_size));
		break;

	case CreateMap::TileType::Fire:
		AddChild(new FireGimmick(position, Vector3(25, 25, 25)));
		break;

	case CreateMap::TileType::Water:
		AddChild(new WaterGimmick(position, Vector3(25, 25, 25)));
		break;

	case CreateMap::TileType::WaterEnd:
		AddChild(new WaterGimmickEnd(position, Vector3(25, 25, 25)));
		break;

	case CreateMap::TileType::KeyBlock:
		AddChild(new KeyGimmick(position, Vector3(25, 25, 25), m_player));
		break;

	case CreateMap::TileType::KeyItem:
		AddChild(new KeyItem(position, Vector3(25, 25, 25)));
		break;

	case CreateMap::TileType::Transparent:
		AddChild(new TransparentGimmick(position, Vector3(25, 25, 25)));
		break;

	case CreateMap::TileType::Goal:
		AddChild(new Goal(position, m_map));
		break;

	default:
		break;
	}
}