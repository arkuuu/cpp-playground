#include <iostream>
#include "some_class.h"

int main()
{
    std::cout << "Hello World, I was built with the help of cmake" << std::endl;

    SomeClass someClassInstance;
    someClassInstance.printSecretMessage();

    return 0;
}
