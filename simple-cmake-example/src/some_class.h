// Not sure yet if using this header guard or #pragma once is better...
#ifndef SOME_CLASS_H_
#define SOME_CLASS_H_

class SomeClass
{
public:
    void printSecretMessage();

private:
    int m_privateNumber = 42;
};

#endif // SOME_CLASS_H_
