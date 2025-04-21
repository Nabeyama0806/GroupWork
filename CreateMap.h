#pragma once
#include "Node.h"
#include "LoadMap.h"
#include "Vector3.h"

class Player;

class CreateMap : public Node
{
public:
	enum class TileType
	{
		PlayerSpawn = -1,
		None,
		Wall,
		Fire,
		Water,
		WaterEnd,
		KeyBlock,
		KeyItem,
		Transparent,
		Goal,

		Length,
	};

	enum class MapType
	{
		Map1,
		Map2,
		Map3,

		Length,
	};

	void LoadMap();

private:
	static constexpr int MapWidth = 10;		//�}�b�v�̉���
	static constexpr int MapHeight = 15;	//�}�b�v�̏c��
	static constexpr int MapDepth = 10;		//�}�b�v�̉��s��
	static constexpr Vector3 TileSize = Vector3(100, 100, 100);	//�J�n���̍��W

	Player* m_player;	//�v���C���[
	Node* m_mapNode;
	int m_mapIndex;	//�}�b�v�̃C���f�b�N�X

	void Create(std::vector<std::vector<int>> data, int positionY);

	std::string GetMapName(int typeNum, int posY)
	{
		return "Resource/MapData/Map" + std::to_string(typeNum+1) + "_data/Map" + std::to_string(posY+1) + ".csv";
	};

public:
	CreateMap(Player* m_player);
};