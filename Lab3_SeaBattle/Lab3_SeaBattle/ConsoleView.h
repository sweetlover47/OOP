#pragma once
#include "GameView.h"
#include "Gamer.h"
#include <vector>

class ConsoleView : public GameView
{
private:
	std::vector<std::vector<int>> mapMine;
	std::vector<std::vector<int>> mapEnemy;
public:
	ConsoleView();
	~ConsoleView();
	void show(Controller *controller) override;
};

