#include <iostream>
#include <stdlib.h>
#include "SharedPointer.hpp"

SharedPointer::SharedPointer(const size_t memorySize)
{
    m_memory = malloc(memorySize);
    m_referenceCounter = new uint(1);

    std::cout << "[SharedPointer] constructor, allocated memorySize:" << memorySize << ", memory:" << m_memory
              << ", referenceCounter:" << *m_referenceCounter << std::endl;
}

SharedPointer::SharedPointer(const SharedPointer& other)
{
    m_memory = other.m_memory;
    m_referenceCounter = other.m_referenceCounter;
    (*m_referenceCounter)++;

    std::cout << "[SharedPointer] copy constructor, allocated memory:" << m_memory << ", referenceCounter:" << *m_referenceCounter << std::endl;
}

SharedPointer::SharedPointer(SharedPointer&& other)
{
    m_memory = other.m_memory;
    m_referenceCounter = other.m_referenceCounter;
    other.m_memory = nullptr;
    other.m_referenceCounter = nullptr;

    std::cout << "[SharedPointer] move constructor, allocated memory:" << m_memory << ", referneceCounter:" << *m_referenceCounter << std::endl;
}

SharedPointer& SharedPointer::operator=(const SharedPointer& other)
{
    if(this != &other)
    {
        reset();

        m_memory = other.m_memory;
        m_referenceCounter = other.m_referenceCounter;

        if(m_referenceCounter)
        {
            (*m_referenceCounter)++;
        }

        std::cout << "[SharedPointer] copy assigment, allocated memory:" << m_memory << ", referenceCounter:" << *m_referenceCounter << std::endl;
    }

    return *this;
}

SharedPointer& SharedPointer::operator=(SharedPointer&& other)
{
    if(this != &other)
    {
        reset();

        m_memory = other.m_memory;
        m_referenceCounter = other.m_referenceCounter;

        other.m_memory = nullptr;
        other.m_referenceCounter = nullptr;

        std::cout << "[SharedPointer] move assigment, allocated memory:" << m_memory << ", referenceCounter:" << *m_referenceCounter << std::endl;
    }

    return *this;
}

SharedPointer::~SharedPointer()
{
    reset();
}

void SharedPointer::reset()
{
    if(m_memory != nullptr && m_referenceCounter != nullptr)
    {
        std::cout << "[SharedPointer] destructor, allocated memory:" << m_memory << ", referenceCounter:" << *m_referenceCounter << std::endl;

        (*m_referenceCounter)--;
        std::cout << "[SharedPointer] destructor, decrementing referenceCounter:" << *m_referenceCounter << std::endl;

        if(*m_referenceCounter == 0)
        {
            std::cout << "[SharedPointer] destructor, free memory:" << m_memory << std::endl;
            free(m_memory);
            free(m_referenceCounter);
        }
    }
}
