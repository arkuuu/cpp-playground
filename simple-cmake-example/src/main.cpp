#include "SomeClass.h"
#include <iostream>

int main()
{
    std::cout << "Hello World, I was built with the help of cmake" << std::endl;

    SomeClass someClassInstance;
    someClassInstance.printSecretMessage();

    return 0;
}
