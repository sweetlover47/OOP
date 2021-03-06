#include "AddCommand.h"
#include "CommandFactory.h"

namespace {
	bool f()
	{
		CommandFactory::getInstance().registerCommand("+", new AddCommandCreator());
		return true;
	}
	bool fake = f();
}

void AddCommand::execute(Context &cntxt, list<string> &arg)
{
	if (cntxt.getLength() < 2)
		throw not_enough_on_Stack();
	double value1 = cntxt.Pick();
	cntxt.Pop();
	double value2 = cntxt.Pick();
	cntxt.Pop();
	cntxt.Push(value1+value2);
	return;
}

