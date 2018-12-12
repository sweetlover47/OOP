#pragma once
#include "Gamer.h"
#include <utility>
#include <string>
#include "GamerCreator.h"
#include "ConsoleView.h"
#include "Controller.h"

class ConsoleGamer : public Gamer
{
private:
	std::pair<int, int> parser(std::string point);
public:
	ConsoleGamer() = default;
	~ConsoleGamer() = default;
	void setShips(GameView *console, Controller *controller) override;
	void checkCell(GameView *console, Controller *controller) override;
	bool isWin(Controller *controller) override
	{
		return controller->isWin();
	}
};

class ConsoleGamerCreator : public GamerCreator
{
	virtual Gamer *create()
	{
		return new ConsoleGamer();
	}
};
