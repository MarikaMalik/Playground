#pragma once

/*
Uloha:
V konstruktore bude trieda akceptovat pocet bytov, ktore ma alokovat
Pamat si staci odlozit do privatnej premennej typu void *
Trieda musi podporovat kopirovanie a assignovanie (copy konstruktor, move konstruktor, …)
Pri zmazani poslednej instancie sa alokovana pamat dealokuje

Uloha2:
*/

class SharedPointer
{
public:
    explicit SharedPointer(const size_t memorySize);
    SharedPointer(const SharedPointer& other);
    SharedPointer(SharedPointer&& other);
    SharedPointer& operator=(const SharedPointer& other);
    SharedPointer& operator=(SharedPointer&& other);

    virtual ~SharedPointer();

    void reset();

private:
    uint* m_referenceCounter;
    void* m_memory;
};