#pragma once
#include "Command.h"
class CommandCreator
{
public:
	virtual Command * create() = 0;
};

