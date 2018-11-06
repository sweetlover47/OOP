#include "PrintCommand.h"
#include "CommandFactory.h"
#include <iostream>

namespace {
	bool f()
	{
		CommandFactory::getInstance().registerCommand("PRINT", new PrintCommandCreator());
		return true;
	}
	bool fake = f();
}

void PrintCommand::execute(Context &cntxt, list<string> &arg)
{
	if (cntxt.getLength() < 1)
		throw not_enough_on_Stack();
	cout << cntxt.Pick() << endl;
	return;
}

