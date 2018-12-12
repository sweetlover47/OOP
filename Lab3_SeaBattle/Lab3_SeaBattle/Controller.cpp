#include "Controller.h"



Controller::Controller()
{
}

Controller::~Controller()
{
}

bool Controller::isWin()
{
	model->setPlayer(player);
	return model->isWin();
}

bool Controller::isShip(std::pair<int, int> start, std::pair<int, int> finish)
{
	model->setPlayer(player);
	return model->isShip(start, finish);
}

void Controller::setShip(std::pair<int, int> start, std::pair<int, int> finish)
{
	model->setPlayer(player);
	model->setShip(start, finish);
	return;
}

bool Controller::alreadyChecked(std::pair<int, int> cell)
{
	model->setPlayer(player);
	return model->alreadyChecked(cell);
}

bool Controller::isShip(std::pair<int, int> cell)
{
	model->setPlayer(player);
	return model->isShip(cell);
}

bool Controller::isKilled(std::pair<int, int> cell)
{
	model->setPlayer(player);
	return model->isKilled(cell);
}
void Controller::setInjure(std::pair<int, int> cell)
{
	model->setPlayer(player);
	return model->setInjure(cell);
}

void Controller::setMiss(std::pair<int, int> cell)
{
	model->setPlayer(player);
	return model->setMiss(cell);
}

void Controller::clearAround(std::pair<int, int> cell)
{
	model->setPlayer(player ^ 1);
	model->clearAround(cell);
	model->setPlayer(player ^ 1);

}

////////////////		V	I	E	W		//////////////////

std::vector<std::vector<int>> Controller::myMap()
{
	return *(model->map());
}


std::vector<std::vector<int>> Controller::enemyMap()
{
	return model->privatize();
}
