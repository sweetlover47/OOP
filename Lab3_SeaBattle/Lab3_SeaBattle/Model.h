#pragma once
#include <utility>
#include <vector>
enum Cell
{
	empty = -1,
	set = 0,
	miss = 1,
	injure = 2,
	kill = 3
};

/*
	Первая компонента карты это x, вторая компонента карты это y.
*/

class Model
{
private:
	int player;
	std::pair<int, int> statistics = std::make_pair(0, 0);
	std::vector<std::vector<int>> firstPlayerMap;
	std::vector<std::vector<int>> secondPlayerMap;
	std::vector<std::pair<int, int>> ship1, ship2;
	void setKill(std::pair<int, int> cell);

public:
	Model()
	{
		firstPlayerMap.resize(10);
		secondPlayerMap.resize(10);
		for (int i = 0; i < 10; ++i)
		{
			firstPlayerMap[i].resize(10);
			secondPlayerMap[i].resize(10);
			for (int j = 0; j < 10; ++j)
			{
				firstPlayerMap[i][j] = Cell::empty;
				secondPlayerMap[i][j] = Cell::empty;
			}
		}
	};
	~Model() = default;
	void setPlayer(int i) { player = i; };
	bool isShip(std::pair<int, int> start, std::pair<int, int> finish);
	bool isShip(std::pair<int, int> cell);
	bool checkAround(std::pair<int, int> cell);
	void setShip(std::pair<int, int> start, std::pair<int, int> finish);
	bool alreadyChecked(std::pair<int, int> cell);
	bool isKilled(std::pair<int, int> cell);
	void makeKilled();
	void clearAround(std::pair<int, int>);
	void setInjure(std::pair<int, int> cell);
	void setMiss(std::pair<int, int> cell);
	bool isWin();
	std::vector<std::pair<int, int>> *ship();
	std::vector<std::vector<int>> *map();
	std::vector<std::vector<int>> privatize();
};

