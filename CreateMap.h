#pragma once
#include "Node.h"
#include "LoadMap.h"
#include "Vector3.h"
#include "Player.h"

class PlayData;
class Camera;

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

		FireBottle,
		ThunderBottle,
		WaterBottle,
		WindBottle,

		FakeKeyBlock,

		Length,
	};

	enum class MapType
	{
		Map0,
		Map1,
		Map2,
		Map3,
		Map4,
		Map5,
		Map6,
		Map7,
		Map8,
		Map9,

		Length,
	};

	void SetMap(int stageNum);
	void LoadMap(bool nextMap = true);

private:
	static constexpr int MapWidth = 10;		//マップの横幅
	static constexpr int MapHeight = 15;	//マップの縦幅
	static constexpr int MapDepth = 10;		//マップの奥行き
	static constexpr Vector3 TileSize = Vector3(100, 100, 100);	//開始時の座標

	PlayData* m_playData;
	Player* m_player;	//プレイヤー
	Camera* m_camera;
	Node* m_mapNode;
	int m_mapIndex;		//マップのインデックス
	bool m_isExistenceKey;
	bool m_isReset;

	std::vector<Vector3> m_spawnPos;

	void Create(std::vector<std::vector<int>> data, int positionY);

	std::string GetMapName(int typeNum, int posY) const
	{
		return "Resource/MapData/Map" + std::to_string(typeNum) + "_data/Map" + std::to_string(posY + 1) + ".csv";
	};

	void SelectBlock(CreateMap::TileType tile, const Vector3& position, const Vector3& size);

public:
	CreateMap(Player* m_player, PlayData* playData, Camera* camera, bool isReset);
	
	int GetMapIndex() const
	{
		return m_mapIndex;
	};
};