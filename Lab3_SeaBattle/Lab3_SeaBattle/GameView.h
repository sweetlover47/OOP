#pragma once
#include "Controller.h"
class GameView
{
public:
	GameView();
	~GameView();
	virtual void show(Controller *controller) = 0;
};

