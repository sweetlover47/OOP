#pragma once

using namespace std;

enum Trit : size_t { UNKNOWN = 0, TRUE, FALSE };
Trit operator~(const Trit a);
Trit operator&(const Trit a, const Trit b);
Trit operator|(const Trit a, const Trit b);
