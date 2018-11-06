#pragma once
#include "CommandCreator.h"
class MulCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class MulCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new MulCommand();
	}

};

