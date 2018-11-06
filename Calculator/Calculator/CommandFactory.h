#pragma once
#include "CommandCreator.h"
#include <string>
#include <map>
using namespace std;
class CommandFactory
{
private:
	map<string, CommandCreator*> Commands;
	CommandFactory() = default;
public:
	virtual ~CommandFactory()
	{
		for (auto item : Commands)
			delete item.second;
	}
	static CommandFactory &getInstance()
	{
		static CommandFactory f;
		return f;
	}
	Command *getCommand(const string &name)
	{
		auto it = Commands.find(name);
		if (it == Commands.end())
			throw command_not_found();
		else
			return it->second->create();
	}
	void registerCommand(const string &name, CommandCreator *creator)
	{
		auto it = Commands.find(name);
		if (it != Commands.end())
		{
			if (it->second == creator)
				return;
			delete it->second;
		}
		Commands[name] = creator;
	}
};

