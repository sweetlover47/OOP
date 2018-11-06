#pragma once
#include "CommandCreator.h"
class DivCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class DivCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new DivCommand();
	}

};

