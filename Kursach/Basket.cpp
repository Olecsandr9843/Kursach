#include "Basket.h"
#include <Windows.h>
#include <string>
#include <fstream>
#include <iomanip>

Basket::Basket(int cardmoney, int money)
{
    income = 0;
    i = 0;
    this->cardmoney = cardmoney;
    this->money = money;
    for (int j = 0; j < 50; j++)
        listduration[j] = 0;
    for (int j = 0; j < 50; j++)
        listprice[j] = 0;
    for (int j = 0; j < 50; j++)
        listname[j] = " ";
}

Basket::Basket()
{
    income = 0;
    i = 0;
    for (int j = 0; j < 50; j++)
        listduration[j] = 0;
    for (int j = 0; j < 50; j++)
        listprice[j] = 0;
    for (int j = 0; j < 50; j++)
        listname[j] = " ";
}

void Basket::CountIncome()
{
    cout << "Ваш загальний дохід: " << income << " грн" << endl;
}

int Basket::BuyRepertoire(int index, Repertoire& obj)
{
    index -= 1;
    if (i < 50) {
        listname[i] = obj.name[index];
        listprice[i] = obj.price[index];
        i++;
    }
    return 0;
}

int Basket::BuyShop(int index, Shop& obj)
{
    index -= 1;
    if (i < 50) {
        listname[i] = obj.name[index];
        listprice[i] = obj.price[index];
        i++;
    }
    return 0;
}

int Basket::BuyCafe(int index, Cafe& obj)
{
    index -= 1;
    if (i < 50) {
        listname[i] = obj.name[index];
        listprice[i] = obj.price[index];
        i++;
    }
    return 0;
}

int Basket::List()
{
    bool hasItems = false;
    for (int j = 0; j < 50; j++) {
        if (listname[j] != " " && listprice[j] != 0) {
            cout << j + 1 << "." << setw(25) << listname[j] << setw(5) << "  " << listprice[j] << " грн" << endl;
            hasItems = true;
        }
    }
    if (!hasItems) {
        cout << "Кошик порожній" << endl;
    }
    return 0;
}

int Basket::Pay(int choice, Visitor& obj)
{
    int sum = 0;
    for (int j = 0; j < 50; j++) {
        if (listprice[j] != 0) {
            sum += listprice[j];
        }
    }
    
    if (sum == 0) {
        cout << "Кошик порожній!" << endl;
        return 0;
    }
    
    cout << "До сплати: " << sum << " грн" << endl;
    
    if (choice == 1) {
        if (obj.cardmoney >= sum) {
            cout << "Платіж успішний!" << endl;
            for (int j = 0; j < 50; j++) {
                listprice[j] = 0;
                listname[j] = " ";
            }
            obj.cardmoney -= sum;
            income += sum;
            i = 0;
        }
        else {
            cout << "Недостатньо коштів. Поповніть рахунок." << endl;
        }
    }
    else {
        if (obj.money >= sum) {
            cout << "Платіж успішний!" << endl;
            for (int j = 0; j < 50; j++) {
                listprice[j] = 0;
                listname[j] = " ";
            }
            obj.money -= sum;
            income += sum;
            i = 0;
        }
        else {
            cout << "Недостатньо коштів. Поповніть готівку." << endl;
        }
    }
    return 0;
}

void Basket::Delete(int choice)
{
    choice--;
    if (choice >= 0 && choice < 50) {
        if (listname[choice] != " " && listprice[choice] != 0) {
            listname[choice] = " ";
            listprice[choice] = 0;
        }
    }
}