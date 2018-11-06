#pragma once
#include "CommandCreator.h"
class PrintCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class PrintCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new PrintCommand();
	}

};

