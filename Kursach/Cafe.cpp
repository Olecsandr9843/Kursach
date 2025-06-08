#include "Cafe.h"

Cafe::Cafe()
{
    //з 30 до 35 їжа
    name[30] = "Сирник";
    name[31] = "Штрудель";
    name[32] = "Тістечко";
    name[33] = "Шоколадка";
    price[30] = 150;
    price[31] = 90;
    price[32] = 50;
    price[33] = 50;
    //36-40 drinks
    name[36] = "Кава";
    name[37] = "Чай";
    name[38] = "Вода";
    name[39] = "Кола";
    price[36] = 20;
    price[37] = 15;
    price[38] = 10;
    price[39] = 20;
}

void Cafe::MenuFood()
{
    cout << setiosflags(ios::left);
    cout << "Список страв: " << endl;
    int n = 1;
    for (int i = 30; i < 35; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << "  " << price[i] << " грн" << endl;
            n++;
        }
    }
}

void Cafe::MenuDrinks()
{
    cout << setiosflags(ios::left);
    cout << "Список напоїв: " << endl;
    int n = 1;
    for (int i = 36; i < 40; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << "  " << price[i] << " грн" << endl;
            n++;
        }
    }
}