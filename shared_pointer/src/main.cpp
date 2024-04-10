#include <iostream>
#include <memory>
#include "SharedPointer.hpp"

int main() // int argc, char** argv)
{
    // auto a = SharedPointer(7);
    auto b = SharedPointer(8);

    SharedPointer c(b);
    SharedPointer d(b);
    // SharedPointer e = std::move(b);

    b.reset();

    std::cout << "------------------------------------------------" << std::endl;

    // copy assigment
    std::cout << "-------COPY ASSIGMENT---------------------------" << std::endl;

    // a = b;

    // move assigment
    std::cout << "-------MOVE ASSIGMENT---------------------------" << std::endl;

    // auto c = SharedPointer(3);
    // c = std::move(a);

    return 0;
}
