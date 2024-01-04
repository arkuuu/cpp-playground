#include "some_class.h"
#include <iostream>

void SomeClass::printSecretMessage()
{
    std::cout << "Secret message: The number is " << m_privateNumber << std::endl;
}
