#pragma once
#include<iostream>
using namespace std;

class Visitor
{
    friend class Basket;
protected:
    int pin;
    string namevisitor;
    int money;
    int cardmoney;
public:
    Visitor();
    void Deposit();
    void MoneyShow();
    void CardmoneyShow();
    Visitor(string name, int money, int cardmoney);
    void Withdraw();
};