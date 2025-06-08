#include "Theatre.h"

Theatre::Theatre()
{
    for (int i = 0; i < 50; i++) {
        index[i] = 0;
        name[i] = " ";
        price[i] = 0;
    }
    info = "Ћьв≥вська нац≥ональна опера - це один з найкрасив≥ших театр≥в св≥ту";
    Theatrename = "Ћьв≥вська опера";
}

Theatre::Theatre(string name)
{
    for (int i = 0; i < 50; i++) {
        index[i] = 0;
        this->name[i] = " ";
        price[i] = 0;
    }
    info = "Ћьв≥вська нац≥ональна опера - це один з найкрасив≥ших театр≥в св≥ту";
    Theatrename = name;
}

int Theatre::Info()
{
    cout << info << endl;
    return 0;
}

void Theatre::GetName()
{
    cout << "Ћаскаво просимо до " << Theatrename << "!" << endl;
}