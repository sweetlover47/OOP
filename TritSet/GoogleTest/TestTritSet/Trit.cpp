#include "Trit.h"

Trit operator&(const Trit a, const Trit b)
{
	Trit table[3][3] = { { UNKNOWN, UNKNOWN, FALSE },{ UNKNOWN, TRUE, FALSE },{ FALSE, FALSE, FALSE } };
	return table[a][b];
}

Trit operator|(const Trit a, const Trit b)
{
	Trit table[3][3] = { { UNKNOWN, TRUE, UNKNOWN },{ TRUE, TRUE, TRUE },{ UNKNOWN, TRUE, FALSE } };
	return table[a][b];
}

Trit operator~(const Trit a)
{
	Trit table[3] = { UNKNOWN, FALSE, TRUE };
	return table[a];
}