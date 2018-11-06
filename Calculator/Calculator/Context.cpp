#include "Context.h"

int Context::getLength()
{
	return Stack.size();
}

double Context::Pick()
{
	return Stack.top();
}

void Context::Push(double n)
{
	Stack.push(n);
	return;
}

void Context::Pop()
{
	Stack.pop();
	return;
}

void Context::addLiteral(string &name, double value)
{
	DefineList[name] = value;
}

double Context::getLiteral(string &name)
{
	auto it = DefineList.find(name);
	if (it == DefineList.end())
		throw not_literal();
	return it->second;
}
