#pragma once
#include "Theatre.h"
#include <fstream>
#include <iomanip>

class Shop : public Theatre
{
    friend class Basket;
public:
    Shop();
    int Goods();
};