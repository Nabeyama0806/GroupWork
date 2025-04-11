#include "CreateMap.h"
#include "ModelActor.h"
#include "FireGimmick.h"

CreateMap::CreateMap(Node* layer)
{
	for (int i = 0; i < MapHeight; i++)
	{
		//マップの読み込み
		std::vector<std::vector<int>> data = LoadMap::GetInstance()->ReadCSV(MapName[i]);
		Create(layer, data, i);
	}
}

void CreateMap::Create(Node* layer, std::vector<std::vector<int>> data, int positionY)
{
	//マップの生成
	for (int x = 0; x < MapWidth; x++)
	{
		for (int z = 0; z < MapDepth; z++)
		{
			int tileType = data[x][z];
			if (tileType != static_cast<int>(TileModel::None))
			{
				Vector3 pos = Vector3(
					TileSize.x * x,
					TileSize.y * positionY,
					TileSize.z * z
				);
				layer->AddChild(new FireGimmick(pos));
			}
		}
	}
}