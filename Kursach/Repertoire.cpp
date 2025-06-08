#include "Repertoire.h"
#include <Windows.h>
#include <iomanip>
#include <string>
#include <fstream>

Repertoire::Repertoire()
{
    for (int i = 0; i < 50; i++)
        duration[i] = 0;
    //³� 0 �� 4 �� �����(������ 5 � ��������� ������ �� ������)
    duration[0] = 2.30;
    duration[1] = 2.10;
    duration[2] = 2;
    duration[3] = 2.15;
    //³� 5 �� 9 �� ������
    duration[5] = 1.30;
    duration[6] = 1.45;
    duration[7] = 2;
    //³� 10 �� 14 �� ��� �������
    duration[10] = 2;
    duration[11] = 1.50;
    //³� 15 �� 19 �� ��������
    duration[15] = 2.45;
    duration[16] = 3.10;
    //³� 20 �� 24 �������
    duration[20] = 2.30;
    duration[21] = 2;

    //³� 0 �� 4 �� �����(������ 5 � ��������� ������ �� ������)
    name[0] = "���������� �� �����";
    name[1] = "����";
    name[2] = "������� ��������";
    name[3] = "�����";
    //³� 5 �� 9 �� ������
    name[5] = "��������";
    name[6] = "���������";
    name[7] = "����� � ���������";
    //³� 10 �� 14 �� ��� �������
    name[10] = "������� �������";
    name[11] = "�������-�����������";
    //³� 15 �� 19 �� ��������
    name[15] = "ϳ��������� �������";
    name[16] = "��������� �������";
    //³� 20 �� 24 �������
    name[20] = "������";
    name[21] = "����� � ���������";

    //³� 0 �� 4 �� �����(������ 5 � ��������� ������ �� ������)
    price[0] = 125;
    price[1] = 150;
    price[2] = 175;
    price[3] = 200;
    //³� 5 �� 9 �� ������
    price[5] = 200;
    price[6] = 150;
    price[7] = 250;
    //³� 10 �� 14 �� ��� �������
    price[10] = 80;
    price[11] = 100;
    //³� 15 �� 19 �� ��������
    price[15] = 400;
    price[16] = 300;
    //³� 20 �� 24 �������
    price[20] = 250;
    price[21] = 220;  // ���������� � price[24] �� price[21]
}

void Repertoire::General()
{
    cout << "1.�����" << endl;
    cout << "2.������" << endl;
    cout << "3.������ �������" << endl;
    cout << "4.��������" << endl;
    cout << "5.�������" << endl;
    cout << "6.�����. " << endl;

}

void Repertoire::Opera()
{
    cout << setiosflags(ios::left);
    cout << "������ ����: " << endl;
    int n = 1;
    for (int i = 0; i < 4; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " ���." << setw(5) << "  " << price[i] << " ���" << endl;
            n++;
        }
    }
}

void Repertoire::Ballet()
{
    cout << setiosflags(ios::left);
    cout << "������ ������: " << endl;
    int n = 1;
    for (int i = 5; i < 9; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " ���." << setw(5) << "  " << price[i] << " ���" << endl;
            n++;
        }
    }
}

void Repertoire::Children()
{
    cout << setiosflags(ios::left);
    cout << "������ ������� ������: " << endl;
    int n = 1;
    for (int i = 10; i < 14; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " ���." << setw(5) << "  " << price[i] << " ���" << endl;
            n++;
        }
    }
}

void Repertoire::Concerts()
{
    cout << setiosflags(ios::left);
    cout << "������ ��������: " << endl;
    int n = 1;
    for (int i = 15; i < 19; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " ���." << setw(5) << "  " << price[i] << " ���" << endl;
            n++;
        }
    }
}

void Repertoire::Perfomances()
{
    cout << setiosflags(ios::left);
    cout << "������ ������: " << endl;
    int n = 1;
    for (int i = 20; i < 24; i++) {
        if (name[i] != " ") {
            cout << n << ".";
            cout << setw(25) << name[i] << setw(5) << duration[i] << " ���." << setw(5) << "  " << price[i] << " ���" << endl;
            n++;
        }
    }
}