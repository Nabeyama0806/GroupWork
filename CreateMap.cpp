#include "CreateMap.h"
#include "ModelActor.h"
#include "Player.h"
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

CreateMap::CreateMap(Player* player) :
	m_player(player),
	m_mapNode(nullptr),
	m_mapIndex(static_cast<int>(MapType::Map9))
{
	m_player->SetMap(this);
	LoadMap(false);
}

void CreateMap::LoadMap(bool nextMap)
{
	if (nextMap) m_mapIndex++;
	if (m_mapNode) m_mapNode->Destroy();
	m_mapNode = new Node();
	AddChild(m_mapNode);
	m_spawnPos.clear();

	for (int i = 0; i < MapHeight; i++)
	{
		//マップの読み込み
		std::vector<std::vector<int>> data = LoadMap::GetInstance()->ReadCSV(GetMapName(m_mapIndex, i));
		Create(data, i);
	}

	int spawnPosIndex = GetRand(m_spawnPos.size() - 1);
	m_player->SetSpawnPosition(m_spawnPos[spawnPosIndex]);
}

void CreateMap::Create(std::vector<std::vector<int>> data, int positionY)
{
	//マップの生成
	for (int x = 0; x < MapWidth; x++)
	{
		for (int z = 0; z < MapDepth; z++)
		{
			int tileType = data[x][z];
			Vector3 pos = Vector3(
				TileSize.x * x,
				TileSize.y * positionY,
				TileSize.z * z
			);

			//プレイヤーのスポーン地点
			if (tileType == static_cast<int>(TileType::PlayerSpawn))
			{
				m_spawnPos.push_back(pos);
				continue;
			}

			SelectBlock(static_cast<TileType>(tileType), pos, TileSize);
		}
	}
}

void CreateMap::SelectBlock(CreateMap::TileType tile, const Vector3& position, const Vector3& size)
{
	switch (tile)
	{
	case CreateMap::TileType::Wall:
		m_mapNode->AddChild(new TileCube(position, size));
		break;

	case CreateMap::TileType::Fire:
		m_mapNode->AddChild(new FireGimmick(position));
		break;

	case CreateMap::TileType::Water:
		m_mapNode->AddChild(new WaterGimmick(position));
		break;

	case CreateMap::TileType::WaterEnd:
		m_mapNode->AddChild(new HitCollider("WaterGimmickEnd", position, size));
		break;

	case CreateMap::TileType::KeyBlock:
		m_mapNode->AddChild(new KeyGimmick(position, m_player));
		break;

	case CreateMap::TileType::KeyItem:
		if (m_player->GetIsKey()) break;
		m_mapNode->AddChild(new KeyItem(position));
		break;

	case CreateMap::TileType::Transparent:
		m_mapNode->AddChild(new TransparentGimmick(position));
		break;

	case CreateMap::TileType::Goal:
		m_mapNode->AddChild(new Goal(position, this));
		break;

	case CreateMap::TileType::FireBottle:
		if (m_player->GetElement() & (1 << static_cast<int>(GetBottle::Type::Fire))) break;
		m_mapNode->AddChild(new GetBottle(position, m_player, "Resource/Model/bottle_fire.mv1", GetBottle::Type::Fire));
		break;

	case CreateMap::TileType::ThunderBottle:
		if (m_player->GetElement() & (1 << static_cast<int>(GetBottle::Type::Thunder))) break;
		m_mapNode->AddChild(new GetBottle(position, m_player, "Resource/Model/bottle_thunder.mv1", GetBottle::Type::Thunder));
		break;

	case CreateMap::TileType::WaterBottle:
		if (m_player->GetElement() & (1 << static_cast<int>(GetBottle::Type::Water))) break;
		m_mapNode->AddChild(new GetBottle(position, m_player, "Resource/Model/bottle_water.mv1", GetBottle::Type::Water));
		break;

	case CreateMap::TileType::WindBottle:
		if (m_player->GetElement() & (1 << static_cast<int>(GetBottle::Type::Wind))) break;
		m_mapNode->AddChild(new GetBottle(position, m_player, "Resource/Model/bottle_wind.mv1", GetBottle::Type::Wind));
		break;

	default:
		break;
	}
}