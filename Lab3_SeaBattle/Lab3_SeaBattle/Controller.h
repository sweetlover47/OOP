#pragma once
#include <utility>
#include "Model.h"
class Controller
{
	int player;
	Model *model = new Model();
public:
	Controller();
	void setPlayer(int i) { this->player = i; model->setPlayer(i); };
	~Controller();
	bool isShip(std::pair<int, int> start, std::pair<int, int> finish);
	bool isShip(std::pair<int, int> cell);
	bool alreadyChecked(std::pair<int, int> cell);
	void setShip(std::pair<int, int> start, std::pair<int, int> finish);
	bool isKilled(std::pair<int, int> cell);
	void clearAround(std::pair<int, int> cell);
	void setInjure(std::pair<int, int> cell);
	void setMiss(std::pair<int, int> cell);
	bool isWin();
	std::vector<std::vector<int>> myMap();
	std::vector<std::vector<int>> enemyMap();
};

