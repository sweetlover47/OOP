#include "MulCommand.h"
#include "CommandFactory.h"

namespace {
	bool f()
	{
		CommandFactory::getInstance().registerCommand("*", new MulCommandCreator());
		return true;
	}
	bool fake = f();
}

void MulCommand::execute(Context &cntxt, list<string> &arg)
{
	if (cntxt.getLength() < 2)
		throw not_enough_on_Stack();
	double value1 = cntxt.Pick();
	cntxt.Pop();
	double value2 = cntxt.Pick();
	cntxt.Pop();
	cntxt.Push(value1*value2);
	return;
}

