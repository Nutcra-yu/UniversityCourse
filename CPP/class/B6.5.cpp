#include <iostream>
#include "B5.4.cpp"
using namespace std;

enum flag
{
    AM,
    PM
};

class NewClock : public Clock
{
private:
    flag flag;

public:
    NewClock(int hour, int minute, int second) : Clock(hour, minute, second)
    {
        if (hour < 12 && hour > 0)
            flag = AM;
        else
            flag = PM;
    }

    ShowFlag()
    {
        if (flag)
            cout << "PM" << endl;
        else
            cout << "AM" << endl;
    }
};

int main()
{
    NewClock C1(11, 59, 59);
    NewClock C2(12, 0, 1);

    C1.ShowFlag();
    C2.ShowFlag();

    system("pause");
}