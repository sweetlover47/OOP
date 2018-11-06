#include <iostream>
#include "Calculator.h"
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	Calculator C;
	if (argc > 1)
	{
		ifstream in(argv[1]);
		if (!in)
		{
			cout << "File not found" << endl;
			return 0;
		}
		else
			C.run(in);
	}
	else
		C.run(cin);
	return 0;
}