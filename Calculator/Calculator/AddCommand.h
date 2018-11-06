#pragma once
#pragma once
#include "CommandCreator.h"
class AddCommand : public Command
{
	virtual void execute(Context &cntxt, list<string> &arg) override;
};

class AddCommandCreator : public CommandCreator
{
public:
	virtual Command *create()
	{
		return new AddCommand();
	}

};

