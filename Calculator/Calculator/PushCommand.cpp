#include "PushCommand.h"
#include "CommandFactory.h"
#include <locale>

namespace {
	bool f()
	{
		CommandFactory::getInstance().registerCommand("PUSH", new PushCommandCreator());
		return true;
	}
	bool fake = f();
}

void PushCommand::execute(Context &cntxt, list<string> &arg)
{
	if (arg.size() < 1)
		throw not_enough_arguments();
	locale loc;
	double value = 0.0;
	if (!isdigit(arg.front()[0], loc))
	{
		value = cntxt.getLiteral(arg.front());
	}
	else
	{
		value = stod(arg.front());
	}
	cntxt.Push(value);
	return;
}

