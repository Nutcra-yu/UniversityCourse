#include "B5.3.cpp"
#include "B5.4.cpp"

class ClockWithData : public date, public Clock
{

public:
    ClockWithData(int year, int month, int day, int hour, int minute, int second) :
         date(year, month, day), Clock(hour, minute, second)
    {
    }

    void show()
    {
        date::show();
        cout << ' ' << Hour << ' ' << Minute << ' ' << Second << endl;
    }
    void AddSecond()
    {

        Second++;
        if (Second == 60)
        {
            Second = 0;
            //分增加
            Minute++;
            if (Minute == 60)
            {
                Minute = 0;
                //时增加
                Hour++;
                if (Hour == 24)
                {
                    Hour == 0;
                    NewDay();
                }
            }
        }
    }
};

int main()
{
    ClockWithData a(2022, 10, 19, 23, 59, 55);

    int i;
    for (i = 0; i < 10; i++)
    {
        a.AddSecond();
        a.show();
    }

    system("pause");
}

