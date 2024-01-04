#include "SomeClass.h"
#include <iostream>

void SomeClass::printSecretMessage()
{
    std::cout << "Secret message: The number is " << privateNumber << std::endl;
}
