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
		OnOffBlock,
		OnOffSwitch,
		Transparent,
		Goal,

		Length,
	};

private:
	static constexpr int MapWidth = 10;		//�}�b�v�̉���
	static constexpr int MapHeight = 15;		//�}�b�v�̏c��
	static constexpr int MapDepth = 10;		//�}�b�v�̉��s��
	static constexpr Vector3 TileSize = Vector3(100, 100, 100);	//�J�n���̍��W

	Player* m_player;	//�v���C���[
	
	const char MapName[MapHeight][256] = 
	{
		"MapData/Map1_data/Map1.csv",
		"MapData/Map1_data/Map2.csv",
		"MapData/Map1_data/Map3.csv",
		"MapData/Map1_data/Map4.csv",
		"MapData/Map1_data/Map5.csv",
		"MapData/Map1_data/Map6.csv",
		"MapData/Map1_data/Map7.csv",
		"MapData/Map1_data/Map8.csv",
		"MapData/Map1_data/Map9.csv",
		"MapData/Map1_data/Map10.csv",
		"MapData/Map1_data/Map11.csv",
		"MapData/Map1_data/Map12.csv",
		"MapData/Map1_data/Map13.csv",
		"MapData/Map1_data/Map14.csv",
		"MapData/Map1_data/Map15.csv",
	};

	void Create(std::vector<std::vector<int>> data, int positionY);

public:
	CreateMap(Player* m_player);
};