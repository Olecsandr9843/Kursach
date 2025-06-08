#include <Windows.h>
#include <chrono>
#include <iostream>

#include "Basket.h"
#include "Cafe.h"
#include "Director.h"
#include "Repertoire.h"
#include "Shop.h"
#include "Theatre.h"
#include "Visitor.h"
#include "Wardrobe.h"

using namespace std;

void print_dmenu() {
    system("cls");
    cout << "Ви увійшли як директор!" << endl;
    cout << "1.Змінити ціни спектаклів" << endl
        << "2.Подивитися прибуток" << endl
        << "3.Змінити репертуар" << endl
        << "4.Змінити меню кафе" << endl
        << "5.Змінити пароль на Wi-Fi" << endl
        << "6.Змінити пароль входу" << endl
        << "7.Вихід" << endl;
}

void print_vmenu(Theatre& obj) {
    system("cls");
    obj.GetName();
    cout << "1.Подивитися репертуар" << endl
        << "2.Кошик" << endl
        << "3.Кафе" << endl
        << "4.Банкомат" << endl
        << "5.Wi-Fi" << endl
        << "6.Сувенірний магазин" << endl
        << "7.Гардероб" << endl
        << "8.Інформація про театр" << endl
        << "9.Вихід" << endl;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    string wifi = "12345678";
    string pass = "qwerty";

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string n;
    int m, cm;
    cout << "Введіть ім'я: " << endl;
    cin >> n;
    cout << "Введіть кількість грошей: " << endl;
    cin >> m;
    cout << "Введіть кількість грошей на картці: " << endl;
    cin >> cm;

    Shop shop;
    Director director;
    Visitor visitor(n, m, cm);
    Wardrobe ward;
    Basket basket(cm, m);
    Theatre opera("Lviv Opera");
    Repertoire reper;
    Cafe cafe;

main:
    system("cls");
    cout << "Вітаю, " << n << "!Оберіть хто ви є : " << endl
        << "1.Відвідувач" << endl
        << "2.Директор" << endl
        << "3.Вихід" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
    vmenu:
        print_vmenu(opera);
        int vmenu;
        cin >> vmenu;
        switch (vmenu) {
        case 1:
        rmenu:
            system("cls");
            cout << "Репертуар театру: " << endl;
            int rmenu;
            reper.General();
            cin >> rmenu;
            switch (rmenu) {
            case 1:
                system("cls");
            opera:
                {
                    int operanum;
                    reper.Opera();
                    cout << "Для покупки у кошик введіть номер опери: " << endl
                        << "Для повернення назад введіть - 0." << endl;
                    cin >> operanum;
                    if (operanum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(operanum, reper);
                        cout << "Квиток додано до кошика" << endl;
                        Sleep(2000);
                        goto opera;
                    }
                }
                break;
            case 2:
                system("cls");
            ballet:
                {
                    int balletnum;
                    reper.Ballet();
                    cout << "Для покупки у кошик введіть номер балету: " << endl
                        << "Для повернення назад введіть - 0." << endl;
                    cin >> balletnum;
                    if (balletnum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(balletnum + 5, reper);
                        cout << "Квиток додано до кошика" << endl;
                        Sleep(2000);
                        goto ballet;
                    }
                }
                break;
            case 3:
                system("cls");
            children:
                {
                    int childnum;
                    reper.Children();
                    cout << "Для покупки у кошик введіть номер дитячої вистави: " << endl
                        << "Для повернення назад введіть - 0." << endl;
                    cin >> childnum;
                    if (childnum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(childnum + 10, reper);
                        cout << "Квиток додано до кошика" << endl;
                        Sleep(2000);
                        goto children;
                    }
                }
                break;
            case 4:
                system("cls");
            concert:
                {
                    int concertnum;
                    reper.Concerts();
                    cout << "Для покупки у кошик введіть номер концерту: " << endl
                        << "Для повернення назад введіть - 0." << endl;
                    cin >> concertnum;
                    if (concertnum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(concertnum + 15, reper);
                        cout << "Квиток додано до кошика" << endl;
                        Sleep(2000);
                        goto concert;
                    }
                }
                break;
            case 5:
                system("cls");
            perfomance:
                {
                    int perfnum;
                    reper.Perfomances();
                    cout << "Для покупки у кошик введіть номер вистави: " << endl
                        << "Для повернення назад введіть - 0." << endl;
                    cin >> perfnum;
                    if (perfnum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(perfnum + 20, reper);
                        cout << "Квиток додано до кошика" << endl;
                        Sleep(2000);
                        goto perfomance;
                    }
                }
                break;
            case 6:
                goto vmenu;
                break;
            }
            break;
        case 2:
        basketmenu:
            system("cls");
            cout << "Ваш кошик:" << endl;
            basket.List();
            cout << "1.Оплатити." << endl;
            cout << "2.Видалити з кошика." << endl;
            cout << "3.Назад." << endl;
            int basketmenu;
            cin >> basketmenu;
            switch (basketmenu) {
            case 1:
                cout << "Оберіть спосіб оплати: " << endl
                    << "1.Карта" << endl
                    << "2.Готівка" << endl
                    << "3.Назад" << endl;
                int pay;
                cin >> pay;
                switch (pay) {
                case 1:
                    basket.Pay(pay, visitor);
                    Sleep(3000);
                    goto basketmenu;
                    break;
                case 2:
                    basket.Pay(pay, visitor);
                    Sleep(3000);
                    goto basketmenu;
                    break;
                case 3:
                    goto basketmenu;
                    break;
                }
                break;
            case 2:
            {
                int bdelete;
                cout << "Для видалення з кошика введіть номер товару: " << endl
                    << "Для повернення назад введіть - 0." << endl;
                cin >> bdelete;
                if (bdelete == 0) {
                    goto basketmenu;
                }
                else {
                    basket.Delete(bdelete);
                    cout << "Товар видалено з кошика" << endl;
                    Sleep(2000);
                    goto basketmenu;
                }
            }
            break;
            case 3:
                goto vmenu;
                break;
            }
            break;
        case 3:
        cafe:
            system("cls");
            cout << "1.Меню їжі. " << endl;
            cout << "2.Меню напоїв. " << endl;
            cout << "3.Назад. " << endl;
            int cafechoice;
            cin >> cafechoice;
            switch (cafechoice) {
            case 1:
                cafe.MenuFood();
                cout << "Для покупки у кошик введіть номер страви: " << endl
                    << "Для повернення назад введіть - 0." << endl;
                int cafenum;
                cin >> cafenum;
                if (cafenum == 0) {
                    goto cafe;
                }
                else {
                    basket.BuyCafe(cafenum + 30, cafe);
                    cout << "Товар додано до кошика" << endl;
                    Sleep(2000);
                    goto cafe;
                }
                break;
            case 2:
                cafe.MenuDrinks();
                cout << "Для покупки у кошик введіть номер напою: " << endl
                    << "Для повернення назад введіть - 0." << endl;
                cin >> cafenum;
                if (cafenum == 0) {
                    goto cafe;
                }
                else {
                    basket.BuyCafe(cafenum + 36, cafe);
                    cout << "Товар додано до кошика" << endl;
                    Sleep(2000);
                    goto cafe;
                }
                break;
            case 3:
                goto vmenu;
                break;
            }
            break;
        case 4:
        bmenu:
            system("cls");
            cout << "1.Готівка" << endl;
            cout << "2.Гроші на картці" << endl;
            cout << "3.Поповнити. " << endl;
            cout << "4.Зняти гроші. " << endl;
            cout << "5.Назад. " << endl;
            int bmenu;
            cin >> bmenu;
            switch (bmenu) {
            case 1:
                system("cls");
                visitor.MoneyShow();
                Sleep(3000);
                goto bmenu;
                break;
            case 2:
                system("cls");
                visitor.CardmoneyShow();
                Sleep(3000);
                goto bmenu;
                break;
            case 3:
                system("cls");
                visitor.Deposit();
                Sleep(3000);
                goto bmenu;
                break;
            case 4:
                system("cls");
                visitor.Withdraw();
                Sleep(3000);
                goto bmenu;
                break;
            case 5:
                goto vmenu;
                break;
            }
            break;
        case 5:
            system("cls");
            cout << "Інформація про Wi-Fi " << endl;
            cout << "Пароль: " << wifi << endl;
            cout << "1.Назад. " << endl;
            int wifichoice;
            cin >> wifichoice;
            if (wifichoice == 1) {
                goto vmenu;
            }
            break;
        case 6:
        shop:
            system("cls");
            cout << "1.Товари з сувенірами. " << endl;
            cout << "2.Назад. " << endl;
            int shopchoice;
            cin >> shopchoice;
            switch (shopchoice) {
            case 1:
                shop.Goods();
                int shopnumber;
                cout << "Для покупки у кошик введіть номер товару: " << endl
                    << "Для повернення назад введіть - 0." << endl;
                cin >> shopnumber;
                if (shopnumber == 0) {
                    goto shop;
                }
                else {
                    basket.BuyShop(shopnumber + 25, shop);
                    cout << "Товар додано до кошика" << endl;
                    Sleep(2000);
                    goto shop;
                }
                break;
            case 2:
                goto vmenu;
                break;
            }
            break;
        case 7:
        wmenu:
            system("cls");
            cout << "1.Взяти номер. " << endl;
            cout << "2.Здати номер. " << endl;
            cout << "3.Назад. " << endl;
            int wmenu;
            cin >> wmenu;
            switch (wmenu) {
            case 1:
                ward.ReceiveNumber();
                Sleep(3000);
                goto wmenu;
                break;
            case 2:
                ward.GiveNumber();
                Sleep(3000);
                goto wmenu;
                break;
            case 3:
                system("cls");
                goto vmenu;
                break;
            }
            break;
        case 8:
            system("cls");
            cout << "Інформація про театр " << endl;
            opera.Info();
            cout << endl;
            cout << "1.Назад. " << endl;
            int info;
            cin >> info;
            if (info == 1) {
                goto vmenu;
            }
            break;
        case 9:
            system("cls");
            goto main;
            break;
        }
        break;
    case 2:
    {
        string input;
        cout << "Введіть пароль: ";
        cin >> input;
        if (pass == input) {
            print_dmenu();
            int dmenu;
            cin >> dmenu;
            switch (dmenu) {
            case 1:
                cout << "Функція зміни цін спектаклів" << endl;
                Sleep(2000);
                break;
            case 2:
                basket.CountIncome();
                Sleep(3000);
                break;
            case 3:
                cout << "Функція зміни репертуару" << endl;
                Sleep(2000);
                break;
            case 4:
                cout << "Функція зміни меню кафе" << endl;
                Sleep(2000);
                break;
            case 5:
                cout << "Введіть новий пароль Wi-Fi: ";
                cin >> wifi;
                cout << "Пароль змінено!" << endl;
                Sleep(2000);
                break;
            case 6:
                cout << "Введіть новий пароль входу: ";
                cin >> pass;
                cout << "Пароль змінено!" << endl;
                Sleep(2000);
                break;
            case 7:
                goto main;
                break;
            }
        }
        else {
            cout << "Неправильний пароль!" << endl;
            Sleep(2000);
            goto main;
        }
    }
    break;
    case 3:
        break;
    default:
        goto main;
    }

    if (choice != 3) {
        goto main;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Duration: " << duration.count() << " seconds" << endl;
    return 0;
}