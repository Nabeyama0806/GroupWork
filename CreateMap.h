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
	static constexpr int MapWidth = 10;		//マップの横幅
	static constexpr int MapHeight = 15;		//マップの縦幅
	static constexpr int MapDepth = 10;		//マップの奥行き
	static constexpr Vector3 TileSize = Vector3(100, 100, 100);	//開始時の座標

	Player* m_player;	//プレイヤー
	
	const char MapName[MapHeight][256] = 
	{
		"Resource/MapData/Map1_data/Map1.csv",
		"Resource/MapData/Map1_data/Map2.csv",
		"Resource/MapData/Map1_data/Map3.csv",
		"Resource/MapData/Map1_data/Map4.csv",
		"Resource/MapData/Map1_data/Map5.csv",
		"Resource/MapData/Map1_data/Map6.csv",
		"Resource/MapData/Map1_data/Map7.csv",
		"Resource/MapData/Map1_data/Map8.csv",
		"Resource/MapData/Map1_data/Map9.csv",
		"Resource/MapData/Map1_data/Map10.csv",
		"Resource/MapData/Map1_data/Map11.csv",
		"Resource/MapData/Map1_data/Map12.csv",
		"Resource/MapData/Map1_data/Map13.csv",
		"Resource/MapData/Map1_data/Map14.csv",
		"Resource/MapData/Map1_data/Map15.csv",
	};

	void Create(std::vector<std::vector<int>> data, int positionY);

public:
	CreateMap(Player* m_player);
};