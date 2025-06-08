#include "Wardrobe.h"

Wardrobe::Wardrobe()
{
    num = 0;
}
//to fix
void Wardrobe::GiveNumber()
{
give:
    cout << "Введіть ваш номер вашого вішака: ";
    cout << "0.Назад." << endl;
    int i;
    cin >> i;
    if (num == i) {
        cout << "Повертаємо Ваш одяг Вам назад" << endl;
    }
    else {
        cout << "Ви ввели неправильний номер.Спробуйте ще раз" << endl;
        goto give;
    }


}

void Wardrobe::ReceiveNumber()
{
    srand(time(NULL));
    num = 1 + rand() % 100;
    cout << "Ваш одяг зберігається під " << num << " номером" << endl;
    ;
}



