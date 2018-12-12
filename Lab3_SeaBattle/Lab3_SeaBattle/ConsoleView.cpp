#include "ConsoleView.h"
#include <iostream>


ConsoleView::ConsoleView()
{
}


ConsoleView::~ConsoleView()
{
}

/*
	ћожно вместо cin и cout использовать потоки, которые задаютс€ в конструкторе. ≈сли не указаны,
	то по умолчанию ставитс€ cin и cout
*/
void ConsoleView::show(Controller *controller)
{
	mapMine = controller->myMap();
	mapEnemy = controller->enemyMap();
	system("cls");
	for (int k = 0; k < 2; ++k)
	{
		std::cout << " |";
		for (char i = 'a'; i < 'k'; ++i)
		{
			std::cout << i << "|";
		}
		std::cout << '\t';
	}
	std::cout << std::endl;
	for (int j = 0; j < 10; ++j)
	{
		std::cout << j << '|';
		for (int i = 0; i < 10; ++i)
		{
			char c;
			switch (mapMine[i][j])
			{
			case -1:
				c = ' ';
				break;
			case 0:
				c = 's';
				break;
			case 1:
				c = 'o';
				break;
			case 2:
				c = '@';
				break;
			case 3:
				c = 'x';
				break;
			default:
				break;
			}
			std::cout << c << '|';
		}
		std::cout << '\t' << j << '|';
		for (int i = 0; i < 10; ++i)
		{
			char c;
			switch (mapEnemy[i][j])
			{
			case -1:
				c = ' ';
				break;
			case 1:
				c = 'o';
				break;
			case 2:
				c = '@';
				break;
			case 3:
				c = 'x';
				break;
			default:
				break;
			}
			std::cout << c << '|';
		}
		std::cout << std::endl;

	}
}