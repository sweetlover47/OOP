#pragma once
#include "CommandCreator.h"
class SubCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class SubCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new SubCommand();
	}

};

