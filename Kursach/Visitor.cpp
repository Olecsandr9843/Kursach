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
    cout << "������ ����� �����: " << endl;
    cin >> card;
inputsum:
    cout << "������ ����, �� ��� ������ ��������� �����: ";
    cin >> sum;
    if (sum > money) {
        cout << "����������� ������.̳������� ���� ��� ����������: " << money << endl;
        if (money == 0) {
            cout << "� ��� ���� ������.�������� ���������." << endl;
        }
        else {
            cout << "��������� �� ��� �� ������ ���� ����." << endl;
            goto inputsum;
        }
    }
    else {
        cout << "�������� ������!" << endl;
        money -= sum;
        cardmoney += sum;
        MoneyShow();
        CardmoneyShow();
    }
}
void Visitor::MoneyShow()
{
    cout << "� ��� " << money << " ������." << endl;
}
void Visitor::CardmoneyShow()
{
    cout << "� ��� �� ������ �� ����: " << cardmoney << endl;
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
    cout << "������ �����:" << endl;
    cin >> p;
    if (pin == p) {
        cout << "������ ����, ��� ������ �����" << endl;
        cin >> sum;
        if (sum <= cardmoney) {
            cardmoney = cardmoney - sum;
            money += sum;
            cout << "�������� ������" << endl;
        }
        else
            cout << "����������� �����" << endl;
    }
    else {
        cout << "������������ ����� " << endl;
        goto enter;
    }


}