#pragma once
#include "CommandCreator.h"
class DefineCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class DefineCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new DefineCommand();
	}

};

