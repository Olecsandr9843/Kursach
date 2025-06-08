#include "Cafe.h"

Cafe::Cafe()
{
    //� 30 �� 35 ���
    name[30] = "������";
    name[31] = "��������";
    name[32] = "ҳ������";
    name[33] = "���������";
    price[30] = 150;
    price[31] = 90;
    price[32] = 50;
    price[33] = 50;
    //36-40 drinks
    name[36] = "����";
    name[37] = "���";
    name[38] = "����";
    name[39] = "����";
    price[36] = 20;
    price[37] = 15;
    price[38] = 10;
    price[39] = 20;
}

void Cafe::MenuFood()
{
    cout << setiosflags(ios::left);
    cout << "������ �����: " << endl;
    int n = 1;
    for (int i = 30; i < 35; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << "  " << price[i] << " ���" << endl;
            n++;
        }
    }
}

void Cafe::MenuDrinks()
{
    cout << setiosflags(ios::left);
    cout << "������ �����: " << endl;
    int n = 1;
    for (int i = 36; i < 40; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << "  " << price[i] << " ���" << endl;
            n++;
        }
    }
}