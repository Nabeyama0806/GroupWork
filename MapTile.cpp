#include "MapTile.h"
#include "FireGimmick.h"
#include "WaterGimmick.h"
#include "WindGimmick.h"
#include "TransparentGimmick.h"
#include "KeyGimmick.h"
#include "KeyItem.h"
#include "TileCube.h"
#include "Goal.h"
#include "GetBottle.h"
#include "HitCollider.h"
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
		AddChild(new FireGimmick(position));
		break;

	case CreateMap::TileType::Water:
		AddChild(new WaterGimmick(position));
		break;

	case CreateMap::TileType::WaterEnd:
		AddChild(new HitCollider("WaterGimmickEnd", position, m_size));
		break;

	case CreateMap::TileType::KeyBlock:
		AddChild(new KeyGimmick(position, m_player));
		break;

	case CreateMap::TileType::KeyItem:
		AddChild(new KeyItem(position));
		break;

	case CreateMap::TileType::Transparent:
		AddChild(new TransparentGimmick(position));
		break;

	case CreateMap::TileType::Goal:
		AddChild(new Goal(position, m_map));
		break;

	case CreateMap::TileType::FireBottle:
		AddChild(new GetBottle(position, m_player, "Resource/Model/bottle_fire.mv1", GetBottle::Type::Fire));
		break;

	case CreateMap::TileType::ThunderBottle:
		AddChild(new GetBottle(position, m_player, "Resource/Model/bottle_thunder.mv1", GetBottle::Type::Thunder));
		break;

	case CreateMap::TileType::WaterBottle:
		AddChild(new GetBottle(position, m_player, "Resource/Model/bottle_water.mv1", GetBottle::Type::Water));
		break;

	case CreateMap::TileType::WindBottle:
		AddChild(new GetBottle(position, m_player, "Resource/Model/bottle_wind.mv1", GetBottle::Type::Wind));
		break;

	default:
		break;
	}
}