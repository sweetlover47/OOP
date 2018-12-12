#include "OptimalGamer.h"
#include "GamerFactory.h"
#include <random>

namespace
{
	bool f()
	{
		GamerFactory::getInstance().registerGamer("optimal", new OptimalGamerCreator());
		return true;
	}
	bool fake = f();
}

void OptimalGamer::setShips(GameView *view, Controller *controller)
{
	std::cout << "OptimalGamer" << std::endl;
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

void OptimalGamer::setBattleShip(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair<int, int> start, finish;
	do {
		int coordinata = mersene() % 8;
		int direction = mersene() % 2; // 0 - влево, 1 - вправо ИЛИ 0 - вверх, 1 - вниз
		int location = mersene() % 4;
		switch (location)
			// 0 - левый столбец, 1 - нижняя строка, 2 - правый столбец, 3 - верхняя строка
		{
		case 0:
			if (coordinata < 3)
			{
				start = std::make_pair(0, 1);
				finish = std::make_pair(0, 4);
			}
			else if (coordinata > 4)
			{
				start = std::make_pair(0, 5);
				finish = std::make_pair(0, 8);
			}
			else
			{
				start = std::make_pair(0, coordinata + 1);
				finish = std::make_pair(0, coordinata + 3 * (direction - direction ^ 1) + 1);
			}
			break;
		case 1:
			if (coordinata < 3)
			{
				start = std::make_pair(1, 9);
				finish = std::make_pair(4, 9);
			}
			else if (coordinata > 4)
			{
				start = std::make_pair(5, 9);
				finish = std::make_pair(8, 9);
			}
			else
			{
				start = std::make_pair(coordinata + 1, 9);
				finish = std::make_pair(coordinata + 3 * (direction - direction ^ 1) + 1, 9);
			}
			break;
		case 2:
			if (coordinata < 3)
			{
				start = std::make_pair(9, 1);
				finish = std::make_pair(9, 4);
			}
			else if (coordinata > 4)
			{
				start = std::make_pair(9, 5);
				finish = std::make_pair(9, 8);
			}
			else
			{
				start = std::make_pair(9, coordinata + 1);
				finish = std::make_pair(9, coordinata + 3 * (direction - direction ^ 1) + 1);
			}
			break;
		case 3:
			if (coordinata < 3)
			{
				start = std::make_pair(1, 0);
				finish = std::make_pair(4, 0);
			}
			else if (coordinata > 4)
			{
				start = std::make_pair(5, 0);
				finish = std::make_pair(8, 0);
			}
			else
			{
				start = std::make_pair(coordinata + 1, 0);
				finish = std::make_pair(coordinata + 3 * (direction - direction ^ 1) + 1, 0);
			}
			break;

		}
	} while (controller->isShip(start, finish));
	controller->setShip(start, finish);
	return;
}

void OptimalGamer::setCruiser(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair<int, int> start, finish;
	do {
		int coordinata = mersene() % 8;
		int direction = mersene() % 2; // 0 - влево, 1 - вправо ИЛИ 0 - вверх, 1 - вниз
		int location = mersene() % 4;
		switch (location)
			// 0 - левый столбец, 1 - нижняя строка, 2 - правый столбец, 3 - верхняя строка
		{
		case 0:
			if (coordinata < 2)
			{
				start = std::make_pair(0, 1);
				finish = std::make_pair(0, 3);
			}
			else if (coordinata > 5)
			{
				start = std::make_pair(0, 6);
				finish = std::make_pair(0, 8);
			}
			else
			{
				start = std::make_pair(0, coordinata + 1);
				finish = std::make_pair(0, coordinata + 2 * (direction - direction ^ 1) + 1);
			}
			break;
		case 1:
			if (coordinata < 2)
			{
				start = std::make_pair(1, 9);
				finish = std::make_pair(3, 9);
			}
			else if (coordinata > 5)
			{
				start = std::make_pair(6, 9);
				finish = std::make_pair(8, 9);
			}
			else
			{
				start = std::make_pair(coordinata + 1, 9);
				finish = std::make_pair(coordinata + 2 * (direction - direction ^ 1) + 1, 9);
			}
			break;
		case 2:
			if (coordinata < 2)
			{
				start = std::make_pair(9, 1);
				finish = std::make_pair(9, 3);
			}
			else if (coordinata > 5)
			{
				start = std::make_pair(9, 6);
				finish = std::make_pair(9, 8);
			}
			else
			{
				start = std::make_pair(9, coordinata + 1);
				finish = std::make_pair(9, coordinata + 2 * (direction - direction ^ 1) + 1);
			}
			break;
		case 3:
			if (coordinata < 2)
			{
				start = std::make_pair(1, 0);
				finish = std::make_pair(3, 0);
			}
			else if (coordinata > 5)
			{
				start = std::make_pair(6, 0);
				finish = std::make_pair(8, 0);
			}
			else
			{
				start = std::make_pair(coordinata + 1, 0);
				finish = std::make_pair(coordinata + 2 * (direction - direction ^ 1) + 1, 0);
			}
			break;

		}
	} while (controller->isShip(start, finish));
	controller->setShip(start, finish);
	return;
}

void OptimalGamer::setDestroyer(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair<int, int> start, finish;
	do {
		int coordinata = mersene() % 8;
		int direction = mersene() % 2; // 0 - влево, 1 - вправо ИЛИ 0 - вверх, 1 - вниз
		int location = mersene() % 4;
		switch (location)
			// 0 - первая строка, 1 - правый столбец, 2 - нижняя строка, 3 - левый столбец
		{
		case 0:
			if (coordinata < 1)
			{
				start = std::make_pair(0, 1);
				finish = std::make_pair(0, 2);
			}
			else if (coordinata > 6)
			{
				start = std::make_pair(0, 7);
				finish = std::make_pair(0, 8);
			}
			else
			{
				start = std::make_pair(0, coordinata + 1);
				finish = std::make_pair(0, coordinata + (direction - direction ^ 1) + 1);
			}
			break;
		case 1:
			if (coordinata < 1)
			{
				start = std::make_pair(1, 9);
				finish = std::make_pair(2, 9);
			}
			else if (coordinata > 6)
			{
				start = std::make_pair(7, 9);
				finish = std::make_pair(8, 9);
			}
			else
			{
				start = std::make_pair(coordinata + 1, 9);
				finish = std::make_pair(coordinata + (direction - direction ^ 1) + 1, 9);
			}
			break;
		case 2:
			if (coordinata < 1)
			{
				start = std::make_pair(9, 1);
				finish = std::make_pair(9, 2);
			}
			else if (coordinata > 6)
			{
				start = std::make_pair(9, 7);
				finish = std::make_pair(9, 8);
			}
			else
			{
				start = std::make_pair(9, coordinata + 1);
				finish = std::make_pair(9, coordinata + (direction - direction ^ 1) + 1);
			}
			break;
		case 3:
			if (coordinata < 1)
			{
				start = std::make_pair(1, 0);
				finish = std::make_pair(2, 0);
			}
			else if (coordinata > 6)
			{
				start = std::make_pair(7, 0);
				finish = std::make_pair(8, 0);
			}
			else
			{
				start = std::make_pair(coordinata + 1, 0);
				finish = std::make_pair(coordinata + (direction - direction ^ 1) + 1, 0);
			}
			break;

		}
	} while (controller->isShip(start, finish));
	controller->setShip(start, finish);
	return;
}

void OptimalGamer::setSubmarine(Controller *controller)
{
	std::random_device rd;
	std::mt19937 mersene(rd());
	std::pair<int, int> start;
	int x, y;
	do {
		x = mersene() % 6;
		y = mersene() % 6;
		start = std::make_pair(x + 2, y + 2);
	} while (controller->isShip(start, start) || x == y || x == 9 - y);
	return;
}


///////////////////////////////////////////////////////////////////////////////////////

void OptimalGamer::checkCell(GameView *view, Controller *controller)
{
	std::pair<int, int> cell = std::make_pair(-1, -1);
	do
	{
		if (cell.first > -1 && controller->isShip(cell))
		{
			controller->setInjure(cell);
			if (controller->isKilled(cell))
			{
				controller->clearAround(cell);
				injured.erase(injured.begin(), injured.end());
			}
			else
			{
				injured.push_back(cell);
			}
		}
		else if (cell.first > -1)
			controller->setMiss(cell);
		cell = generateTurn(controller);
		std::cout << "Check (" << cell.first << ";" << cell.second << ")" << std::endl; //ConsoleViewMessage: Проверена клетка ( ; )
	} while (controller->alreadyChecked(cell) || controller->isShip(cell));
	controller->setMiss(cell);
	std::cout << ""; // ConsoleViewMessage: мимо!
}

std::pair<int, int> OptimalGamer::generateTurn(Controller *controller)
{
	if (injured.size() == 0)	// Нет недобитых кораблей
	{
		return crowsFeet(controller);
	}
	else
	{
		return nextCell(controller);
	}
}

std::pair<int, int> OptimalGamer::nextCell(Controller *controller)
{
	std::pair<int, int> cell = injured.back();
	if (!controller->alreadyChecked(std::make_pair(cell.first, std::max(0, cell.second-1))))			// Если клетка сверху не проверена, выбираем ее
	{
		cell = std::make_pair(cell.first, std::max(0, cell.second - 1));
	}
	else if (!controller->alreadyChecked(std::make_pair(std::min(9, cell.first + 1), cell.second)))		// Если клетка справа не проверена, выбираем ее
	{
		cell = std::make_pair(std::min(9, cell.first + 1), cell.second);
	}
	else if (!controller->alreadyChecked(std::make_pair(cell.first, std::min(9, cell.second + 1))))		// Если клетка снизу не проверена, выбираем ее
	{
		cell = std::make_pair(cell.first, std::min(9, cell.second + 1));
	}
	else if (!controller->alreadyChecked(std::make_pair(std::max(0, cell.first - 1), cell.second)))		// Если клетка слева не проверена, выбираем ее
	{
		cell = std::make_pair(std::max(0, cell.first - 1), cell.second);
	}
	else
	{
		injured.erase(injured.begin()+1, injured.end());
		cell = nextCell(controller);
	}
	return cell;
}

std::pair<int, int> OptimalGamer::crowsFeet(Controller *controller)
{
	std::pair<int, int> cell;
	if (prBattleShip)
	{
		if (tableBattleShip.empty())
			prBattleShip = 0;
		else {
			do
			{
				cell = std::make_pair(tableBattleShip.front() % 10, tableBattleShip.front() / 10);
				tableBattleShip.pop_front();
			} while (controller->alreadyChecked(cell));
			if (controller->isKilled(cell))
				--prBattleShip;
		}
	}
	else if (prCruiser)
	{
		if (tableCruiser.empty())
			prCruiser = 0;
		do
		{
			cell = std::make_pair(tableCruiser.front() % 10, tableCruiser.front() / 10);
			tableCruiser.pop_front();
		} while (controller->alreadyChecked(cell));
		if (controller->isKilled(cell))
			--prCruiser;
	}
	else if (prDestroyer)
	{
		if (tableDestroyer.empty())
			prDestroyer = 0;
		do
		{
			cell = std::make_pair(tableDestroyer.front() % 10, tableDestroyer.front() / 10);
			tableDestroyer.pop_front();
		} while (controller->alreadyChecked(cell));
		if (controller->isKilled(cell))
			--prDestroyer;
	}
	else
	{
		std::random_device rd;
		std::mt19937 mersene(rd());
		do
		{
			int x = mersene() % 10;
			int y = mersene() % 10;
			cell = std::make_pair(x, y);
		} while (controller->alreadyChecked(cell));
		if (controller->isKilled(cell))
			--prSubmarine;
	}
	return cell;
}