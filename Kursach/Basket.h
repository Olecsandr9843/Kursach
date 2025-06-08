#pragma once
#include "Visitor.h"
#include "Theatre.h"
#include "Repertoire.h"
#include "Shop.h"
#include "Cafe.h"
class Basket :public Visitor, public Repertoire, public Shop, public Cafe
{
    int i;
    friend class Director;
    int income;
    string listname[50];
    int listprice[50];
    int listduration[50];
public:
    Basket(int cardmoney, int money);
    Basket();
    void CountIncome();
    int BuyRepertoire(int index, Repertoire& obj);
    int List();
    int BuyShop(int index, Shop& obj);
    int BuyCafe(int index, Cafe& obj);
    int Pay(int choice, Visitor& obj);
    void Delete(int choice);
};