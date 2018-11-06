#pragma once
#include "MyExceptions.h"
#include <stack>
#include <map>
#include <list>
using namespace std;

class Context
{
private:
	stack <double> Stack;
	map <string, double> DefineList;
public:
	Context() = default;
	~Context() = default;
	void Push(double n);
	void Pop();
	int getLength();
	double Pick();
	void addLiteral(string &name, double value);
	double getLiteral(string &name);
};

