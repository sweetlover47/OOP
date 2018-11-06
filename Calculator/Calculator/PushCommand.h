#pragma once
#include "CommandCreator.h"
class PushCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class PushCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new PushCommand();
	}

};

