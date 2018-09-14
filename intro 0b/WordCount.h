#ifndef INTRO_0B_WORDCOUNT_H
#define INTRO_0B_WORDCOUNT_H
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <map>
using namespace std;

class WordCount {
private:
    int total = 0;
    multimap<string, int> WordMap;

    void universalize(char *&word);

public:
    void read(istream &in);

    void write(ostream &out);
};

#endif //INTRO_0B_WORDCOUNT_H
