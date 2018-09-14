#include "WordCount.h"

int main(int argc, char* argv[]) {
    try {
        if (argc != 3)
            throw -3;
        else {
            ifstream in(argv[1]);
            if (!in.is_open())
                throw -1;
            ofstream out(argv[2]);
            if (!out.is_open())
                throw -2;

            WordCount wc;
            wc.read(in);
            wc.write(out);
            in.close();
            out.close();
        }
    }
    catch (int e) {
        if (e == -1)
            cerr << "InputFile does not exist" << endl;
        if (e == -2)
            cerr << "OutputFile does not exist" << endl;
        if (e == -3)
            cerr << "Too few arguments" << endl;
    }
    return 0;
}