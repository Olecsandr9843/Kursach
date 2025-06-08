#include "Director.h"
#include <Windows.h>
#include <iomanip>
#include <string>
#include <fstream>
class Basket;
class Shop;
void Director::Change(Repertoire& obj)
{
    cout << setiosflags(ios::left);
    for (int i = 0; i < 24; i++) {
        if (obj.name[i] != " " && obj.price[i] != 0) {
            cout << i + 1 << "." << setw(25) << obj.name[i] << setw(5) << "  " << obj.price[i] << " грн" << endl;
        }
    }
}

int Director::ChangeInfo(int num, Repertoire& obj)
{
    num -= 1;
    cin >> obj.name[num];
    cin >> obj.price[num];
    return 0;
}
void Director::Change(Shop& obj)
{
    cout << setiosflags(ios::left);
    for (int i = 24; i < 29; i++) {
        if (obj.name[i] != " " && obj.price[i] != 0) {
            cout << i + 1 << "." << setw(25) << obj.name[i] << setw(5) << "  " << obj.price[i] << " грн" << endl;
        }
    }
}
int Director::ChangeInfo(int num, Shop& obj)
{
    num -= 1;
    cin >> obj.name[num];
    cin >> obj.price[num];
    return 0;
}
int Director::ChangeInfo(int num, Cafe& obj)
{
    num -= 1;
    cin >> obj.name[num];
    cin >> obj.price[num];
    return 0;
}

void Director::Change(Cafe& obj)
{
    cout << setiosflags(ios::left);
    for (int i = 29; i < 50; i++) {
        if (obj.name[i] != " " && obj.price[i] != 0) {
            cout << i + 1 << "." << setw(25) << obj.name[i] << setw(5) << "  " << obj.price[i] << " грн" << endl;
        }
    }
}