#include "Model.h"
#include <algorithm>

bool Model::isShip(std::pair<int, int> start, std::pair<int, int> finish)
{
	int beginPoint, endPoint;
	if (start.first == finish.first)
	{
		beginPoint = start.second;
		endPoint = finish.second;
	}
	else
	{
		beginPoint = start.first;
		endPoint = finish.first;
	}
	for (int i = beginPoint; i <= endPoint; ++i)
	{
		if (start.first == finish.first)
		{
			if (!checkAround(std::make_pair(start.first, i)))
				return true;
		}
		else
		{
			if (!checkAround(std::make_pair(i, start.second)))
				return true;
		}
	}
	return false;
}

bool Model::checkAround(std::pair<int, int> cell)
{
	std::vector<std::vector<int>> *_map = map();
	for (int i = std::max(cell.first - 1, 0); i <= std::min(cell.first + 1, 9); ++i)
		for (int j = std::max(cell.second - 1, 0); j <= std::min(cell.second + 1, 9); ++j)
			if ((*_map)[i][j] == Cell::set)
				return false;
	return true;
}

void Model::setShip(std::pair<int, int> start, std::pair<int, int> finish)
{
	std::vector<std::vector<int>> *_map = map();
	for (int i = start.first; i <= finish.first; ++i)
		for (int j = start.second; j <= finish.second; ++j)
			(*_map)[i][j] = Cell::set;
}

std::vector<std::vector<int>> *Model::map()
{
	return player ? &secondPlayerMap : &firstPlayerMap;
}

bool Model::alreadyChecked(std::pair<int, int> cell)
{
	if (privatize()[cell.first][cell.second] == Cell::empty)
		return false;
	return true;
}

std::vector<std::vector<int>> Model::privatize()
{
	std::vector<std::vector<int>> answer;
	answer.resize(10);
	if (player)
	{
		for (int i = 0; i < 10; ++i)
		{
			answer[i].resize(10);
				for (int j = 0; j < 10; ++j)
				{
					if (firstPlayerMap[i][j] == Cell::set)
						answer[i][j] = Cell::empty;
					else
						answer[i][j] = firstPlayerMap[i][j];
				}
		}
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			answer[i].resize(10);
			for (int j = 0; j < 10; ++j)
			{
				if (secondPlayerMap[i][j] == Cell::set)
					answer[i][j] = Cell::empty;
				else
					answer[i][j] = secondPlayerMap[i][j];
			}
		}
	}
	return answer;
}

bool Model::isShip(std::pair<int, int> cell)
{
	this->player ^= 1;
	std::vector<std::vector<int>> *_map = map();
	if ((*_map)[cell.first][cell.second] >= Cell::set)
	{
		this->player ^= 1;
		return true;
	}
	this->player ^= 1;
	return false;
}

void Model::setInjure(std::pair<int, int> cell)
{
	player ^= 1;
	std::vector<std::vector<int>> *_map = map();
	(*_map)[cell.first][cell.second] = Cell::injure;
	player ^= 1;
	if (isKilled(cell))
		setKill(cell);
	return;
}

void Model::setMiss(std::pair<int, int> cell)
{
	player ^= 1;
	std::vector<std::vector<int>> *_map = map();
	(*_map)[cell.first][cell.second] = Cell::miss;
	player ^= 1;
	return;
}

bool Model::isKilled(std::pair<int, int> cell)
{
	if (!isShip(cell))
		return false;
	player ^= 1; 
	std::vector<std::pair<int, int>> *_ship = ship();
	(*_ship).push_back(cell);
	for (auto it : (*_ship))
	{
		if (!checkAround(it))
		{
			player ^= 1;
			return false;
		}
	}
	player ^= 1;
	return true;
}

std::vector<std::pair<int, int>> *Model::ship()
{
	return player ? &ship2 : &ship1;
}

void Model::setKill(std::pair<int, int> cell)
{
	player ^= 1;
	makeKilled();
	std::vector<std::pair<int, int>> *_ship = ship();
	(*_ship).erase((*_ship).begin(), (*_ship).end());
	player ^= 1;
	return;
}

void Model::makeKilled()
{
	std::vector<std::vector<int>> *_map = map();
	std::vector<std::pair<int, int>> *_ship = ship();
	for (auto it : (*_ship))
	{
		(*_map)[it.first][it.second] = Cell::kill;
	}
}

void Model::clearAround(std::pair<int, int> cell)
{
	std::vector<std::vector<int>> *_map = map();
	std::pair<int, int> direction = std::make_pair(0, 0);
	if (cell.first < 9 && (*_map)[cell.first + 1][cell.second] == Cell::kill)
		direction = std::make_pair(1, 0);
	if (cell.second < 9 && (*_map)[cell.first][cell.second + 1] == Cell::kill)
		direction = std::make_pair(0, 1);
	if (cell.first > 0 && (*_map)[cell.first - 1][cell.second] == Cell::kill)
		direction = std::make_pair(-1, 0);
	if (cell.second > 0 && (*_map)[cell.first][cell.second - 1] == Cell::kill)
		direction = std::make_pair(0, -1);
	do
	{
		for (int i = std::max(cell.first - 1, 0); i <= std::min(cell.first + 1, 9); ++i)
			for (int j = std::max(cell.second - 1, 0); j <= std::min(cell.second + 1, 9); ++j)
			{
				if ((*_map)[i][j] != Cell::kill)
					(*_map)[i][j] = Cell::miss;
			}
		cell = std::make_pair(cell.first + direction.first, cell.second + direction.second);
	} while (abs(direction.first+direction.second) > 0 && (*_map)[cell.first][cell.second] == Cell::kill);
}

bool Model::isWin()
{
	player ^= 1;
	std::vector<std::vector<int>> *_map = map();
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			if ((*_map)[i][j] == Cell::set)
			{
				player ^= 1;
				return false;
			}
	player ^= 1;
	return true;
}