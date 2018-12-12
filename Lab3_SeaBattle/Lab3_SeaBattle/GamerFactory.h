#pragma once
#include "GamerCreator.h"
#include <map>
#include <string>
#include <iostream>

class GamerFactory
{
private:
	std::map <std::string, GamerCreator*> gamers;
	GamerFactory() = default;
public:
	virtual ~GamerFactory()
	{
		for (auto it : gamers)
			delete it.second;
	}
	static GamerFactory &getInstance()
	{
		static GamerFactory f;
		return f;
	}
	Gamer *getGamer(const std::string &name)
	{
		auto it = gamers.find(name);
		if (it == gamers.end())
		{
			std::cout << "GamerType not found" << std::endl;
			return nullptr;
		}
		else
			return it->second->create();
	}
	void registerGamer(const std::string &name, GamerCreator *creator)
	{
		auto it = gamers.find(name);
		if (it != gamers.end())
		{
			if (it->second == creator)
				return;
			delete it->second;
		}
		gamers[name] = creator;
	}
};

