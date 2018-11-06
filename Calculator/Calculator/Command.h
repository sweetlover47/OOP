#pragma once
#include "Context.h"
class Command
{
public:
	virtual void execute(Context &cntxt, list<string> &arg) = 0;
};

