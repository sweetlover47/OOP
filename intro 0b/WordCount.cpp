#include "WordCount.h"

void WordCount::universalize(char* &word) {
    int i = 0;
    while (i < strlen(word) && word[i] > 0) {

        if ((word[i] > 96 && word[i] < 123) || (word[i] > 64 && word[i] < 91) || (word[i] > 47 && word[i] < 58)) {
            if ((word[i] - 'a' < 0) && (word[i] > 60)) {
                word[i] = word[i] - 'A' + 'a';
            }
        }
        i++;
    }
    return;
}

void WordCount::read(istream &in) {
    char *new_word = new char[255];
    string str;
    int i = 0, k = 0;
    while (getline(in, str)) {
        while (str[i]) {
            if ((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)) {
                new_word[k] = str[i];
                k++;
            } else if (strlen(new_word) > 0) {
                new_word[k] = '\0';
                universalize(new_word);
                k = 0;
                total++;
                if (WordMap.find(new_word) == WordMap.end())
                    WordMap.insert(pair<string, int>(new_word, 1));
                else
                    WordMap.find(new_word)->second++;
                new_word[0] = '\0';
            }
            i++;
        }
        i = 0;
    }
    delete[] new_word;
}

void WordCount::write(ostream &out) {
    multimap<int, string, greater<>> sortedByCount;
    for (auto it : WordMap) {
        sortedByCount.insert(pair<int, string>(it.second, it.first));
    }
    out << "Слово,Частота,Частота в %" << endl;
    for (auto it: sortedByCount) {
        out << it.second << "," << it.first << "," << (double) it.first / total << endl;
    }
}