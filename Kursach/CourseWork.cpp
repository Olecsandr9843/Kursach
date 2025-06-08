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
    cout << "�� ������ �� ��������!" << endl;
    cout << "1.������ ���� ���������" << endl
        << "2.���������� ��������" << endl
        << "3.������ ���������" << endl
        << "4.������ ���� ����" << endl
        << "5.������ ������ �� Wi-Fi" << endl
        << "6.������ ������ �����" << endl
        << "7.�����" << endl;
}

void print_vmenu(Theatre& obj) {
    system("cls");
    obj.GetName();
    cout << "1.���������� ���������" << endl
        << "2.�����" << endl
        << "3.����" << endl
        << "4.��������" << endl
        << "5.Wi-Fi" << endl
        << "6.��������� �������" << endl
        << "7.��������" << endl
        << "8.���������� ��� �����" << endl
        << "9.�����" << endl;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    string wifi = "12345678";
    string pass = "qwerty";

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string n;
    int m, cm;
    cout << "������ ��'�: " << endl;
    cin >> n;
    cout << "������ ������� ������: " << endl;
    cin >> m;
    cout << "������ ������� ������ �� ������: " << endl;
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
    cout << "³���, " << n << "!������ ��� �� � : " << endl
        << "1.³�������" << endl
        << "2.��������" << endl
        << "3.�����" << endl;
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
            cout << "��������� ������: " << endl;
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
                    cout << "��� ������� � ����� ������ ����� �����: " << endl
                        << "��� ���������� ����� ������ - 0." << endl;
                    cin >> operanum;
                    if (operanum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(operanum, reper);
                        cout << "������ ������ �� ������" << endl;
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
                    cout << "��� ������� � ����� ������ ����� ������: " << endl
                        << "��� ���������� ����� ������ - 0." << endl;
                    cin >> balletnum;
                    if (balletnum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(balletnum + 5, reper);
                        cout << "������ ������ �� ������" << endl;
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
                    cout << "��� ������� � ����� ������ ����� ������ �������: " << endl
                        << "��� ���������� ����� ������ - 0." << endl;
                    cin >> childnum;
                    if (childnum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(childnum + 10, reper);
                        cout << "������ ������ �� ������" << endl;
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
                    cout << "��� ������� � ����� ������ ����� ��������: " << endl
                        << "��� ���������� ����� ������ - 0." << endl;
                    cin >> concertnum;
                    if (concertnum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(concertnum + 15, reper);
                        cout << "������ ������ �� ������" << endl;
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
                    cout << "��� ������� � ����� ������ ����� �������: " << endl
                        << "��� ���������� ����� ������ - 0." << endl;
                    cin >> perfnum;
                    if (perfnum == 0) {
                        system("cls");
                        goto rmenu;
                    }
                    else {
                        basket.BuyRepertoire(perfnum + 20, reper);
                        cout << "������ ������ �� ������" << endl;
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
            cout << "��� �����:" << endl;
            basket.List();
            cout << "1.��������." << endl;
            cout << "2.�������� � ������." << endl;
            cout << "3.�����." << endl;
            int basketmenu;
            cin >> basketmenu;
            switch (basketmenu) {
            case 1:
                cout << "������ ����� ������: " << endl
                    << "1.�����" << endl
                    << "2.������" << endl
                    << "3.�����" << endl;
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
                cout << "��� ��������� � ������ ������ ����� ������: " << endl
                    << "��� ���������� ����� ������ - 0." << endl;
                cin >> bdelete;
                if (bdelete == 0) {
                    goto basketmenu;
                }
                else {
                    basket.Delete(bdelete);
                    cout << "����� �������� � ������" << endl;
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
            cout << "1.���� ��. " << endl;
            cout << "2.���� �����. " << endl;
            cout << "3.�����. " << endl;
            int cafechoice;
            cin >> cafechoice;
            switch (cafechoice) {
            case 1:
                cafe.MenuFood();
                cout << "��� ������� � ����� ������ ����� ������: " << endl
                    << "��� ���������� ����� ������ - 0." << endl;
                int cafenum;
                cin >> cafenum;
                if (cafenum == 0) {
                    goto cafe;
                }
                else {
                    basket.BuyCafe(cafenum + 30, cafe);
                    cout << "����� ������ �� ������" << endl;
                    Sleep(2000);
                    goto cafe;
                }
                break;
            case 2:
                cafe.MenuDrinks();
                cout << "��� ������� � ����� ������ ����� �����: " << endl
                    << "��� ���������� ����� ������ - 0." << endl;
                cin >> cafenum;
                if (cafenum == 0) {
                    goto cafe;
                }
                else {
                    basket.BuyCafe(cafenum + 36, cafe);
                    cout << "����� ������ �� ������" << endl;
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
            cout << "1.������" << endl;
            cout << "2.����� �� ������" << endl;
            cout << "3.���������. " << endl;
            cout << "4.����� �����. " << endl;
            cout << "5.�����. " << endl;
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
            cout << "���������� ��� Wi-Fi " << endl;
            cout << "������: " << wifi << endl;
            cout << "1.�����. " << endl;
            int wifichoice;
            cin >> wifichoice;
            if (wifichoice == 1) {
                goto vmenu;
            }
            break;
        case 6:
        shop:
            system("cls");
            cout << "1.������ � ���������. " << endl;
            cout << "2.�����. " << endl;
            int shopchoice;
            cin >> shopchoice;
            switch (shopchoice) {
            case 1:
                shop.Goods();
                int shopnumber;
                cout << "��� ������� � ����� ������ ����� ������: " << endl
                    << "��� ���������� ����� ������ - 0." << endl;
                cin >> shopnumber;
                if (shopnumber == 0) {
                    goto shop;
                }
                else {
                    basket.BuyShop(shopnumber + 25, shop);
                    cout << "����� ������ �� ������" << endl;
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
            cout << "1.����� �����. " << endl;
            cout << "2.����� �����. " << endl;
            cout << "3.�����. " << endl;
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
            cout << "���������� ��� ����� " << endl;
            opera.Info();
            cout << endl;
            cout << "1.�����. " << endl;
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
        cout << "������ ������: ";
        cin >> input;
        if (pass == input) {
            print_dmenu();
            int dmenu;
            cin >> dmenu;
            switch (dmenu) {
            case 1:
                cout << "������� ���� ��� ���������" << endl;
                Sleep(2000);
                break;
            case 2:
                basket.CountIncome();
                Sleep(3000);
                break;
            case 3:
                cout << "������� ���� ����������" << endl;
                Sleep(2000);
                break;
            case 4:
                cout << "������� ���� ���� ����" << endl;
                Sleep(2000);
                break;
            case 5:
                cout << "������ ����� ������ Wi-Fi: ";
                cin >> wifi;
                cout << "������ ������!" << endl;
                Sleep(2000);
                break;
            case 6:
                cout << "������ ����� ������ �����: ";
                cin >> pass;
                cout << "������ ������!" << endl;
                Sleep(2000);
                break;
            case 7:
                goto main;
                break;
            }
        }
        else {
            cout << "������������ ������!" << endl;
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