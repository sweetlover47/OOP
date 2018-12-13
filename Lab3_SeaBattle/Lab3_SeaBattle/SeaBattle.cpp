#include "SeaBattle.h"
#include "Controller.h"
#include "ConsoleView.h"
#include <iostream>


SeaBattle::SeaBattle()
{
}


SeaBattle::~SeaBattle()
{
}

void SeaBattle::run(Gamer *first, Gamer *second)
{
	Controller *controller = new Controller();
	for (int i = 0; i < round; ++i)
	{
		controller->setPlayer(0);
		first->setShips(firstView, controller);
		controller->setPlayer(1);
		second->setShips(secondView, controller);
		while (!first->isWin(controller) || !second->isWin(controller)) {
			controller->setPlayer(0);
			first->checkCell(firstView, controller);
			firstView->show(controller);
			controller->setPlayer(1);
			second->checkCell(secondView, controller);
			secondView->show(controller);
		}
		controller->setPlayer(0);
		if (first->isWin(controller))
			std::cout << "First player is win" << std::endl;
		else
			std::cout << "Second player is win" << std::endl;
	}
}