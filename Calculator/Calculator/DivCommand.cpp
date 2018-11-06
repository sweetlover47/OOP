#include "DivCommand.h"
#include "CommandFactory.h"
#include <cmath>
namespace {
	bool f()
	{
		CommandFactory::getInstance().registerCommand("/", new DivCommandCreator());
		return true;
	}
	bool fake = f();
}

void DivCommand::execute(Context &cntxt, list<string> &arg)
{
	if (cntxt.getLength() < 2)
		throw not_enough_on_Stack();
	double value1 = cntxt.Pick();
	cntxt.Pop();
	double value2 = cntxt.Pick();
	cntxt.Pop();
	if (fabs(value1) < DBL_EPSILON)
		throw div_zero();
	cntxt.Push(value2/value1);
	return;
}

