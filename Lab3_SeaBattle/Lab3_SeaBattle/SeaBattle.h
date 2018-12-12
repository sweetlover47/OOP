#pragma once
#include "Gamer.h"
#include "GameView.h"
class SeaBattle
{
private:
	int round;
	GameView *firstView;
	GameView *secondView;
public:
	SeaBattle();
	SeaBattle(GameView *first, GameView *second, int count) { round = count; firstView = first; secondView = second; };
	~SeaBattle();
	void run(Gamer* first, Gamer* second);
};

