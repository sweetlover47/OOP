#include "RandomGamer.h"
#include "GamerFactory.h"
#include <random>

namespace
{
	bool f()
	{
		GamerFactory::getInstance().registerGamer("random", new RandomGamerCreator());
		return true;
	}
	bool fake = f();
}

void RandomGamer::setShips(GameView *view, Controller *controller)
{
	std::cout << "RandomGamer" << std::endl;
	int BattleShip = 1, Cruiser = 2, Destroyer = 3, Submarine = 4;
	while (BattleShip)
	{
		setBattleShip(controller);
		--BattleShip;
	}
	while (Cruiser)
	{
		setCruiser(controller);
		--Cruiser;
	}
	while (Destroyer)
	{
		setDestroyer(controller);
		--Destroyer;
	}
	while (Submarine)
	{
		setSubmarine(controller);
		--Submarine;
	}
	return;
}

void RandomGamer::setBattleShip(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair<int, int> start, finish;
	do {
		int x = mersene() % 10;
		int y = mersene() % 10;
		int direction = mersene() % 4;
		switch (direction)
			// 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево
		{
		case 0:
			if (y < 3)
			{
				start = std::make_pair(x, 0);
				finish = std::make_pair(x, 3);
			}
			else
			{
				start = std::make_pair(x, y - 3);
				finish = std::make_pair(x, y);
			}
			break;
		case 1:
			if (x > 6)
			{
				start = std::make_pair(6, y);
				finish = std::make_pair(9, y);
			}
			else
			{
				start = std::make_pair(x, y);
				finish = std::make_pair(x + 3, y);
			}
			break;
		case 2:
			if (y > 6)
			{
				start = std::make_pair(x, 6);
				finish = std::make_pair(x, 9);
			}
			else
			{
				start = std::make_pair(x, y);
				finish = std::make_pair(x, y + 3);
			}
			break;
		case 3:
			if (x < 3)
			{
				start = std::make_pair(0, y);
				finish = std::make_pair(3, y);
			}
			else
			{
				start = std::make_pair(x - 3, y);
				finish = std::make_pair(x, y);
			}
			break;

		}
	} while (controller->isShip(start, finish));
	controller->setShip(start, finish);
	return;
}

void RandomGamer::setCruiser(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair<int, int> start, finish;
	do {
		int x = mersene() % 10;
		int y = mersene() % 10;
		int direction = mersene() % 4;
		switch (direction)
			// 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево
		{
		case 0:
			if (y < 2)
			{
				start = std::make_pair(x, 0);
				finish = std::make_pair(x, 2);
			}
			else
			{
				start = std::make_pair(x, y - 2);
				finish = std::make_pair(x, y);
			}
			break;
		case 1:
			if (x > 7)
			{
				start = std::make_pair(7, y);
				finish = std::make_pair(9, y);
			}
			else
			{
				start = std::make_pair(x, y);
				finish = std::make_pair(x + 2, y);
			}
			break;
		case 2:
			if (y > 7)
			{
				start = std::make_pair(x, 7);
				finish = std::make_pair(x, 9);
			}
			else
			{
				start = std::make_pair(x, y);
				finish = std::make_pair(x, y + 2);
			}
			break;
		case 3:
			if (x < 2)
			{
				start = std::make_pair(0, y);
				finish = std::make_pair(2, y);
			}
			else
			{
				start = std::make_pair(x - 2, y);
				finish = std::make_pair(x, y);
			}
			break;

		}
	} while (controller->isShip(start, finish));
	controller->setShip(start, finish);
	return;
}

void RandomGamer::setDestroyer(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair<int, int> start, finish;
	do {
		int x = mersene() % 10;
		int y = mersene() % 10;
		int direction = mersene() % 4;
		switch (direction)
			// 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево
		{
		case 0:
			if (y < 1)
			{
				start = std::make_pair(x, 0);
				finish = std::make_pair(x, 1);
			}
			else
			{
				start = std::make_pair(x, y - 1);
				finish = std::make_pair(x, y);
			}
			break;
		case 1:
			if (x > 8)
			{
				start = std::make_pair(8, y);
				finish = std::make_pair(9, y);
			}
			else
			{
				start = std::make_pair(x, y);
				finish = std::make_pair(x + 1, y);
			}
			break;
		case 2:
			if (y > 8)
			{
				start = std::make_pair(x, 8);
				finish = std::make_pair(x, 9);
			}
			else
			{
				start = std::make_pair(x, y);
				finish = std::make_pair(x, y + 1);
			}
			break;
		case 3:
			if (x < 1)
			{
				start = std::make_pair(0, y);
				finish = std::make_pair(1, y);
			}
			else
			{
				start = std::make_pair(x - 1, y);
				finish = std::make_pair(x, y);
			}
			break;

		}
	} while (controller->isShip(start, finish));
	controller->setShip(start, finish);
	return;
}

void RandomGamer::setSubmarine(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair<int, int> start;
	do {
		int x = mersene() % 10;
		int y = mersene() % 10;
		start = std::make_pair(x, y);
	} while (controller->isShip(start, start));
	controller->setShip(start, start);
	return;
}

///////////////////////////////////////////////////////////////////////////////////////

void RandomGamer::checkCell(GameView *view, Controller *controller)
{
	std::pair<int, int> cell;
	int result = 0;
	do
	{
		cell = generateTurn(controller);
		std::cout <<"Check (" << cell.first << ";" << cell.second << ")" << std::endl; //ConsoleViewMessage: Проверена клетка ( ; )
	} while (controller->alreadyChecked(cell) || controller->isShip(cell));
	std::cout << ""; // ConsoleViewMessage: мимо!
}

std::pair<int, int> RandomGamer::generateTurn(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair <int, int>cell;
	do
	{
		int x = mersene() % 10;
		int y = mersene() % 10;
		cell = std::make_pair(x, y);
	} while (controller->alreadyChecked(cell) || controller->isShip(cell));
	return cell;
}