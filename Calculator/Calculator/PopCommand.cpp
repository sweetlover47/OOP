#include "PopCommand.h"
#include "CommandFactory.h"

namespace {
	bool f()
	{
		CommandFactory::getInstance().registerCommand("POP", new PopCommandCreator());
		return true;
	}
	bool fake = f();
}

void PopCommand::execute(Context &cntxt, list<string> &arg)
{
	if (cntxt.getLength() < 1)
		throw not_enough_on_Stack();
	cntxt.Pop();
	return;
}

