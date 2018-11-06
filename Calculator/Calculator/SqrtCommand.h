#pragma once
#include "CommandCreator.h"
class SqrtCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class SqrtCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new SqrtCommand();
	}

};

