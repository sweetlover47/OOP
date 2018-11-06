#include "DefineCommand.h"
#include "CommandFactory.h"

namespace {
	bool f()
	{
		CommandFactory::getInstance().registerCommand("DEFINE", new DefineCommandCreator());
		return true;
	}
	bool fake = f();
}

void DefineCommand::execute(Context &cntxt, list<string> &arg)
{
	if (arg.size() < 2)
		throw not_enough_arguments();
	string name = arg.front();
	arg.pop_front();
	double value = stod(arg.front());
	arg.pop_front();
	cntxt.addLiteral(name, value);
	return;
}

