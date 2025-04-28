#include "CreateMap.h"
#include "ModelActor.h"
#include "MapTile.h"
#include "Player.h"
#include "FireGimmick.h"
#include "WaterGimmick.h"
#include "WindGimmick.h"
#include "TransparentGimmick.h"
#include "KeyGimmick.h"
#include "KeyItem.h"
#include "TileCube.h"

CreateMap::CreateMap(Player* player) :
	m_player(player),
	m_mapNode(nullptr),
	m_mapIndex(static_cast<int>(MapType::Map5))
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

	for (int i = 0; i < MapHeight; i++)
	{
		//マップの読み込み
		std::vector<std::vector<int>> data = LoadMap::GetInstance()->ReadCSV(GetMapName(m_mapIndex, i));
		Create(data, i);
	}
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
				m_player->SetSpawnPosition(pos);
				continue;
			}

			m_mapNode->AddChild(new MapTile(static_cast<TileType>(tileType), pos, TileSize, m_player, this));
		}
	}
}