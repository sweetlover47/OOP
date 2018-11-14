#include "Calculator.h"
#include "CommandFactory.h"
#include "Context.h"
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

void Calculator::run(istream &in)
{
	string str;
	string arg;
	string operation;
	list<string> arguments;
	Context context;
	while (!in.eof())
	{
		getline(in, str);
		if (str.compare(0, 1, "#") != 0)
		{
			istringstream sstr(str);
			getline(sstr, operation, ' ');
			while (getline(sstr, arg, ' '))
			{
				arguments.push_back(arg);
			}
			try
			{
				auto_ptr<Command> cmd = static_cast <auto_ptr<Command>>(CommandFactory::getInstance().getCommand(operation));
				cmd->execute(context, arguments);
				arguments.clear();
			}
			catch (const MyExceptions &exc)
			{
				cout << exc.what() << endl;

			}
		}
	}
	system("pause");
}
