#include "Shop.h"

Shop::Shop()
{
    //?? 25-29 ??????
    name[25] = "??????";
    name[26] = "????????";
    price[25] = 50;
    price[26] = 200;
}

int Shop::Goods()
{
    cout << setiosflags(ios::left);
    cout << "?????? ??????: " << endl;
    int n = 1;
    for (int i = 25; i < 29; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << "  " << price[i] << " ???" << endl;
            n++;
        }
    }
    return 0;
}