#include "ConsoleGamer.h"
#include "GamerFactory.h"
namespace
{
	bool f()
	{
		GamerFactory::getInstance().registerGamer("console", new ConsoleGamerCreator());

		return true;
	}
	bool fake = f();
}

std::pair<int, int> ConsoleGamer::parser(std::string point)
{
	std::pair<int, int> answer;
	if (isdigit(point[0]))
	{
		answer.second = point[0] - '0';
		answer.first = static_cast<int>(point[1] - 'a');
	}
	else
	{
		answer.second = point[1] - '0';
		answer.first = static_cast<int>(point[0] - 'a');
	}
	return answer;
}

void ConsoleGamer::setShips(GameView *console, Controller *controller)
{
	std::cout << "ConsoleGamer" << std::endl;
	int BattleShip = 1, Cruiser = 2, Destroyer = 3, Submarine = 4;
	while (BattleShip || Cruiser || Destroyer || Submarine)
	{
		// ConsoleViewMessage: std::cout << "Enter start and finish coordinates of ship:" << std::endl;
		std::string firstPoint, secondPoint;
		std::pair<int, int> start, finish;
		std::cin >> firstPoint >> secondPoint;
		start = parser(firstPoint);
		finish = parser(secondPoint);
		int length = (finish.first + finish.second) - (start.first + start.second);
		if (length < 0)
		{
			swap(start, finish);
			length = -length;
		}
		if (controller->isShip(start, finish))
			std::cout << "";//ConsoleViewMessage: попробуйте поставить корабль в другое место
		else
		{
			switch (length)
			{
			case 0:
				--Submarine;
				break;
			case 1:
				--Destroyer;
				break;
			case 2:
				--Cruiser;
				break;
			case 3:
				--BattleShip;
				break;
			default:
				std::cout << ""; //ConsoleViewMessage: неверная длина корабля
			}
			controller->setShip(start, finish);
		}
		console->show(controller);
	}
	std::cout << ""; //ConsoleViewMessage: корабли успешно установлены.
	return;
}

///////////////////////////////////////////////////////////////////////////////////////

void ConsoleGamer::checkCell(GameView *console, Controller *controller)
{
	int result = 0;
	std::string point;
	std::pair<int, int>cell = std::make_pair(-1, -1);
	do
	{
		if (cell.first > -1)
			if (controller->isShip(cell))
			{
				controller->setInjure(cell);
			}
			else
				controller->setMiss(cell);
		console->show(controller);
		std::cout << "Attack!" << std::endl;
		std::cin >> point;
		cell = parser(point);
		std::cout << "Check (" << cell.first << ";" << cell.second << ")" << std::endl;  //ConsoleViewMessage: Проверена клетка ( ; )
	} while (controller->alreadyChecked(cell) || controller->isShip(cell));
	controller->setMiss(cell);
	std::cout << ""; // ConsoleViewMessage: мимо!

}