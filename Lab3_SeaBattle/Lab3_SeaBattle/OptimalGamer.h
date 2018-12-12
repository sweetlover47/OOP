#pragma once
#include "Gamer.h"
#include "GamerCreator.h"
#include <deque>
#include <vector>
class OptimalGamer : 
	public Gamer
{
private:
	void setBattleShip(Controller *controller);
	void setCruiser(Controller *controller);
	void setDestroyer(Controller *controller);
	void setSubmarine(Controller *controller);

	std::pair<int, int> injure = std::make_pair(-1, -1);
	int prBattleShip = 1;
	int prCruiser = 2;
	int prDestroyer = 3;
	int prSubmarine = 4;
	std::deque<int> tableBattleShip = { 20,31,12,3,24,35,16,7,28,39,60,71,52,43,64,75,56,47,68,79,92,83,96,87 };
	std::deque<int> tableCruiser = { 1,23,5,27,9,41,63,45,67,49,81,85,89 };
	std::deque<int> tableDestroyer = { 10,21,32,14,25,36,18,29,50,61,72,54,65,76,58,69,90,94,98,30,34,38,70,74,78 };
	std::pair<int, int> generateTurn(Controller *controller);
	std::pair<int, int> crowsFeet(Controller *controller);
	std::pair<int, int> nextCell(Controller *controller);
	std::vector<std::pair<int, int>> injured;

public:
	OptimalGamer() = default;
	~OptimalGamer() = default;
	void setShips(GameView *view, Controller *controller) override;
	bool isWin(Controller *controller) override
	{
		return controller->isWin();
	}
	void checkCell(GameView *console, Controller *controller) override;
};


class OptimalGamerCreator : public GamerCreator
{
	virtual Gamer *create()
	{
		return new OptimalGamer();
	}
};