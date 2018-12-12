#pragma once
#include "GameView.h"
#include "Controller.h"
class Gamer
{
public:
	~Gamer() = default;
	virtual void setShips(GameView *view, Controller *controller) = 0;
	virtual void checkCell(GameView *console, Controller *controller) = 0;
	virtual bool isWin(Controller *controller) = 0;
};

