#pragma once
#include "Theatre.h"
#include <iomanip>

class Cafe : public Theatre
{
    friend class Basket;
public:
    Cafe();
    void MenuFood();
    void MenuDrinks();
};