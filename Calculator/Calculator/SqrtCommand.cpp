#include "SqrtCommand.h"
#include "CommandFactory.h"
#include <cmath>
namespace {
	bool f()
	{
		CommandFactory::getInstance().registerCommand("SQRT", new SqrtCommandCreator());
		return true;
	}
	bool fake = f();
}

void SqrtCommand::execute(Context &cntxt, list<string> &arg)
{
	if (cntxt.getLength() < 1)
		throw not_enough_on_Stack();
	double value = cntxt.Pick();
	cntxt.Pop();
	if (value < 0)
		throw not_real_sqrt();
	cntxt.Push(sqrt(value));
	return;
}

