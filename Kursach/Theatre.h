#pragma once
#include <windows.h>
#include<iostream>
using namespace std;
class Theatre
{
    friend class Director;
protected:
    string info;
    string Theatrename;
    int index[50];
    string name[50];
    int price[50];
public:
    Theatre();
    int Info();
    Theatre(string name);
    void GetName();
};