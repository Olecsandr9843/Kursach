#include "Wardrobe.h"

Wardrobe::Wardrobe()
{
    num = 0;
}
//to fix
void Wardrobe::GiveNumber()
{
give:
    cout << "������ ��� ����� ������ �����: ";
    cout << "0.�����." << endl;
    int i;
    cin >> i;
    if (num == i) {
        cout << "��������� ��� ���� ��� �����" << endl;
    }
    else {
        cout << "�� ����� ������������ �����.��������� �� ���" << endl;
        goto give;
    }


}

void Wardrobe::ReceiveNumber()
{
    srand(time(NULL));
    num = 1 + rand() % 100;
    cout << "��� ���� ���������� �� " << num << " �������" << endl;
    ;
}



