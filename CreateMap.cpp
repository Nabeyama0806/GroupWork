#include "CreateMap.h"
#include "ModelActor.h"
#include "MapTile.h"
#include "Player.h"


CreateMap::CreateMap(Player* player) :
	m_player(player)
{
	for (int i = 0; i < MapHeight; i++)
	{
		//�}�b�v�̓ǂݍ���
		std::vector<std::vector<int>> data = LoadMap::GetInstance()->ReadCSV(GetMapName(1, i));
		Create(data, i);
	}
}

void CreateMap::Create(std::vector<std::vector<int>> data, int positionY)
{
	//�}�b�v�̐���
	for (int x = 0; x < MapWidth; x++)
	{
		for (int z = 0; z < MapDepth; z++)
		{
			int tileType = data[x][z];

			//�v���C���[�̃X�|�[���n�_
			if (tileType == static_cast<int>(TileType::PlayerSpawn))
			{
				Vector3 pos = Vector3(
					TileSize.x * x,
					TileSize.y * positionY - 100,
					TileSize.z * z
				);
				m_player->SetPosition(pos);
				continue;
			}

			// �^�C���̐���
			if (tileType != static_cast<int>(TileType::None))
			{
				Vector3 pos = Vector3(
					TileSize.x * x,
					TileSize.y * positionY - 100,
					TileSize.z * z
				);

				AddChild(new MapTile(static_cast<TileType>(tileType), pos, TileSize, m_player));
			}
		}
	}
}