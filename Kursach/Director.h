#pragma once
#include "Repertoire.h"
#include "Shop.h"
#include "Cafe.h"
class Director :protected Theatre
{
public:
    void Change(Repertoire& obj);
    void Change(Shop& obj);
    int ChangeInfo(int num, Repertoire& obj);
    int ChangeInfo(int num, Shop& obj);
    int ChangeInfo(int num, Cafe& obj);
    void Change(Cafe& obj);
    friend class Repertoire;
    friend class Shop;
};