#pragma once
#include "Gamer.h"
#include "GamerCreator.h"
class RandomGamer :
	public Gamer
{
private:
	void setBattleShip(Controller *controller);
	void setCruiser(Controller *controller);
	void setDestroyer(Controller *controller);
	void setSubmarine(Controller *controller);
	std::pair<int, int> generateTurn(Controller *controller);
public:
	RandomGamer() = default;
	~RandomGamer() = default;
	void setShips(GameView *view, Controller *controller) override;
	void checkCell(GameView *console, Controller *controller) override;
	bool isWin(Controller *controller) override
	{
		return controller->isWin();
	}
};


class RandomGamerCreator : public GamerCreator
{
	virtual Gamer *create()
	{
		return new RandomGamer();
	}
};

