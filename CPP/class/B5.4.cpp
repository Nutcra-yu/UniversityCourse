#include <iostream>
using namespace std;

struct Alarm
{
    int a_hour, a_minute, a_second;
};

class Clock
{
protected:
    int Hour, Minute, Second;
    Alarm malarm;

public:
    Clock(int hour, int minute, int second)
    {
        if (hour < 24 && hour >= 0 && minute < 60 && minute >= 0 && second < 60 && second >= 0)
        {
            this->Hour = hour;
            this->Minute = minute;
            this->Second = second;
        }
    }

    void SetAlarm(int hour, int minute, int second)
    {

        if (hour < 24 && hour >= 0 && minute < 60 && minute >= 0 && second < 60 && second >= 0)
        {
            malarm.a_hour = hour;
            malarm.a_minute = minute;
            malarm.a_second = second;
        }
    }

    void run()
    {
        cout << Hour << ' ' << Minute << ' ' << Second << endl;

        int i;
        for (i = 0; i < 100; i++)
        {
            //秒增加
            if (Second < 59)
            {
                Second++;
            }
            else if (Second == 59)
            {
                Second = 0;
                //分增加
                if (Minute < 59)
                {
                    Minute++;
                }
                else if (Minute == 59)
                {
                    Minute == 0;
                    //时增加
                    if (Hour < 23)
                    {
                        Hour++;
                    }
                    else if (Hour == 23)
                    {
                        Hour == 0;
                    }
                }
            }

            cout << Hour << ' ' << Minute << ' ' << Second << endl;

            if (malarm.a_hour == Hour && malarm.a_minute == Minute && malarm.a_second == Second)
            {
                cout << "闹钟响了" << '\a';
                break;
            }
        }
    }
};

int main1()
{
    Clock mclock(12, 00, 59);
    mclock.SetAlarm(12, 01, 02);
    mclock.run();

    system("pause");
}
