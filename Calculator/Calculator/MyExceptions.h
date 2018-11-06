#pragma once
#include <exception>
#include <string>
#include <iostream>
using namespace std;


class MyExceptions : public exception {
public:
	const char* what() const throw() = 0;
};

class not_enough_on_Stack : public MyExceptions
{
public:
	const char* what() const throw()
	{
		return "Not enough numbers on Stack";
	}
};

class not_enough_arguments : public MyExceptions
{
public:
	const char* what() const throw()
	{
		return "Not enough arguments";
	}
};


class div_zero : public MyExceptions
{
public:
	const char* what() const throw()
	{
		return "Division by zero";
	}
};


class not_real_sqrt : public MyExceptions
{
public:
	const char* what() const throw()
	{
		return "Negative value under root";
	}
};

class not_literal : public MyExceptions
{
public:
	const char* what() const throw()
	{
		return "Definition is not found";
	}
};

class command_not_found : public MyExceptions
{
public:
	const char* what() const throw()
	{
		return "Command not found";
	}
};


