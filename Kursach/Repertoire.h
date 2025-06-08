#pragma once
#include "Theatre.h"
class Repertoire :protected Theatre
{
    friend class Basket;
private:
    double duration[50];
public:
    Repertoire();
    void General();
    void Opera();
    void Ballet();
    void Children();
    void Concerts();
    void Perfomances();
    friend class Director;
};