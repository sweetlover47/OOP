#pragma once
#include "CommandFactory.h"

using namespace std;

class Calculator
{
public:
	Calculator() = default;
	~Calculator() = default;
	void run(istream &in);
};

