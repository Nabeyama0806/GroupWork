#include "CreateMap.h"
#include "ModelActor.h"
#include "FireGimmick.h"
#include "WaterGimmick.h"
#include "WindGimmick.h"
#include "HitCollider.h"
#include "MapTile.h"


CreateMap::CreateMap()
{
	for (int i = 0; i < MapHeight; i++)
	{
		//マップの読み込み
		std::vector<std::vector<int>> data = LoadMap::GetInstance()->ReadCSV(MapName[i]);
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
			if (tileType != static_cast<int>(TileType::None))
			{
				Vector3 pos = Vector3(
					TileSize.x * x,
					TileSize.y * positionY - 100,
					TileSize.z * z
				);

				AddChild(new MapTile(static_cast<TileType>(tileType), pos, TileSize));
				/*
				switch (static_cast<TileType>(tileType))
				{
				case TileType::Fire:
					AddChild(new FireGimmick(pos));
					break;

				case TileType::Water:
					AddChild(new WaterGimmick(pos, Vector3(1,1,1)));
					break;

				case TileType::PowerUp:
					AddChild(new FireGimmick(pos));
					break;

				case TileType::Wall:
					AddChild(new HitCollider(
						"Wall",
						pos,
						Vector3(TileSize.x, TileSize.y, TileSize.z)
					));
					break;

				default:
					break;
				}
				*/
			}
		}
	}
}