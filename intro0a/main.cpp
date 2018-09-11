#include "module1.h"
#include "module2.h"
#include "module3.h"
#include <iostream>

// for use cout instead of std::cout you should write using namespace std;



int main(int argc, char** argv) {
    std::cout << "Hello world!" << "\n";

    std::cout << Module1::getMyName() << "\n";
    std::cout << Module2::getMyName() << "\n";
    {
        using namespace Module1;
        std::cout << getMyName() << "\n"; // (A)
        std::cout << Module2::getMyName() << "\n";
    }
    //using namespace Module2; // (B)
    // std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)
    // You should use { } for Module1, then you can use Module2::getMyName() as getMyName() \
       or you should specify what module you want to use in line 17
    using Module2::getMyName;
    std::cout << getMyName() << "\n"; // (D)
    // For (A) program use Module1, where we print "John" \
       For (D) program use Module2, where we print "James"
    std::cout << Module3::getMyName() << std::endl;

}
