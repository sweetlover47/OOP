#pragma once
#include "CommandCreator.h"
class PopCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class PopCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new PopCommand();
	}

};

