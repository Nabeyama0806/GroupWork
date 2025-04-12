#pragma once
#include "Node.h"
#include "LoadMap.h"
#include "Vector3.h"

class CreateMap : public Node
{
public:
	enum class TileType
	{
		None,
		Fire,
		Water,
		PowerUp,
		Wall,

		Length,
	};

private:
	static constexpr int MapWidth = 10;		//マップの横幅
	static constexpr int MapHeight = 15;		//マップの縦幅
	static constexpr int MapDepth = 10;		//マップの奥行き
	static constexpr Vector3 TileSize = Vector3(100, 100, 100);	//開始時の座標
	
	const char MapName[MapHeight][256] = 
	{
		"MapData/Map1.csv",
		"MapData/Map2.csv",
		"MapData/Map3.csv",
		"MapData/Map4.csv",
		"MapData/Map5.csv",
		"MapData/Map6.csv",
		"MapData/Map7.csv",
		"MapData/Map8.csv",
		"MapData/Map9.csv",
		"MapData/Map10.csv",
		"MapData/Map11.csv",
		"MapData/Map12.csv",
		"MapData/Map13.csv",
		"MapData/Map14.csv",
		"MapData/Map15.csv",
	};

	void Create(std::vector<std::vector<int>> data, int positionY);

public:
	CreateMap();
};