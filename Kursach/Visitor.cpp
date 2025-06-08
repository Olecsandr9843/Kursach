#include "Visitor.h"
Visitor::Visitor()
{
    cardmoney = 0;
    money = 0;
    pin = 0;
}
void Visitor::Deposit()
{
    long int card;
    int sum;
    cout << "Введіть номер карти: " << endl;
    cin >> card;
inputsum:
    cout << "Введіть суму, на яку хочете поповнити карту: ";
    cin >> sum;
    if (sum > money) {
        cout << "Недостатньо готівки.Мінімальна сума для поповнення: " << money << endl;
        if (money == 0) {
            cout << "У вас немає готівки.Операція неможлива." << endl;
        }
        else {
            cout << "Спробуйте ще раз та введіть іншу суму." << endl;
            goto inputsum;
        }
    }
    else {
        cout << "Операція успішна!" << endl;
        money -= sum;
        cardmoney += sum;
        MoneyShow();
        CardmoneyShow();
    }
}
void Visitor::MoneyShow()
{
    cout << "У вас " << money << " готівки." << endl;
}
void Visitor::CardmoneyShow()
{
    cout << "У вас на балансі на карті: " << cardmoney << endl;
}
Visitor::Visitor(string name, int money, int cardmoney) {
    pin = 1111;
    this->namevisitor = name;
    this->money = money;
    this->cardmoney = cardmoney;
}

void Visitor::Withdraw()
{
    int sum;
    int p;
enter:
    cout << "Введіть пінкод:" << endl;
    cin >> p;
    if (pin == p) {
        cout << "Введіть суму, яку хочете зняти" << endl;
        cin >> sum;
        if (sum <= cardmoney) {
            cardmoney = cardmoney - sum;
            money += sum;
            cout << "Операція успішна" << endl;
        }
        else
            cout << "Недостатньо коштів" << endl;
    }
    else {
        cout << "Неправильний пінкод " << endl;
        goto enter;
    }


}