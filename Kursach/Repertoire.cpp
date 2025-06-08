#include "Repertoire.h"
#include <Windows.h>
#include <iomanip>
#include <string>
#include <fstream>

Repertoire::Repertoire()
{
    for (int i = 0; i < 50; i++)
        duration[i] = 0;
    //Від 0 до 4 це опери(індекс 5 і наступний вільний за замовч)
    duration[0] = 2.30;
    duration[1] = 2.10;
    duration[2] = 2;
    duration[3] = 2.15;
    //Від 5 до 9 це балети
    duration[5] = 1.30;
    duration[6] = 1.45;
    duration[7] = 2;
    //Від 10 до 14 це для дитячих
    duration[10] = 2;
    duration[11] = 1.50;
    //Від 15 до 19 це концерти
    duration[15] = 2.45;
    duration[16] = 3.10;
    //Від 20 до 24 вистави
    duration[20] = 2.30;
    duration[21] = 2;

    //Від 0 до 4 це опери(індекс 5 і наступний вільний за замовч)
    name[0] = "Запорожець за Дунаєм";
    name[1] = "Аїда";
    name[2] = "Наталка Полтавка";
    name[3] = "Тоска";
    //Від 5 до 9 це балети
    name[5] = "Лебедине";
    name[6] = "Лускунчик";
    name[7] = "Ромео і Джульєтта";
    //Від 10 до 14 це для дитячих
    name[10] = "Червона шапочка";
    name[11] = "Колобок-путешествие";
    //Від 15 до 19 це концерти
    name[15] = "Піаністичний концерт";
    name[16] = "Новорічний концерт";
    //Від 20 до 24 вистави
    name[20] = "Гамлет";
    name[21] = "Ромео і Джульєтта";

    //Від 0 до 4 це опери(індекс 5 і наступний вільний за замовч)
    price[0] = 125;
    price[1] = 150;
    price[2] = 175;
    price[3] = 200;
    //Від 5 до 9 це балети
    price[5] = 200;
    price[6] = 150;
    price[7] = 250;
    //Від 10 до 14 це для дитячих
    price[10] = 80;
    price[11] = 100;
    //Від 15 до 19 це концерти
    price[15] = 400;
    price[16] = 300;
    //Від 20 до 24 вистави
    price[20] = 250;
    price[21] = 220;  // Виправлено з price[24] на price[21]
}

void Repertoire::General()
{
    cout << "1.Опери" << endl;
    cout << "2.Балети" << endl;
    cout << "3.Дитячі вистави" << endl;
    cout << "4.Концерти" << endl;
    cout << "5.Вистави" << endl;
    cout << "6.Назад. " << endl;

}

void Repertoire::Opera()
{
    cout << setiosflags(ios::left);
    cout << "Список опер: " << endl;
    int n = 1;
    for (int i = 0; i < 4; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " год." << setw(5) << "  " << price[i] << " грн" << endl;
            n++;
        }
    }
}

void Repertoire::Ballet()
{
    cout << setiosflags(ios::left);
    cout << "Список балетів: " << endl;
    int n = 1;
    for (int i = 5; i < 9; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " год." << setw(5) << "  " << price[i] << " грн" << endl;
            n++;
        }
    }
}

void Repertoire::Children()
{
    cout << setiosflags(ios::left);
    cout << "Список дитячих вистав: " << endl;
    int n = 1;
    for (int i = 10; i < 14; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " год." << setw(5) << "  " << price[i] << " грн" << endl;
            n++;
        }
    }
}

void Repertoire::Concerts()
{
    cout << setiosflags(ios::left);
    cout << "Список концертів: " << endl;
    int n = 1;
    for (int i = 15; i < 19; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " год." << setw(5) << "  " << price[i] << " грн" << endl;
            n++;
        }
    }
}

void Repertoire::Perfomances()
{
    cout << setiosflags(ios::left);
    cout << "Список вистав: " << endl;
    int n = 1;
    for (int i = 20; i < 24; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " год." << setw(5) << "  " << price[i] << " грн" << endl;
            n++;
        }
    }
}