/*第一题： 定义一个时间类Time, 它包含时、分、秒，重载+运算符实现时间相加，并输出时间信息。
 */

#include <iostream>
using namespace std;

class Time
{
private:
    int Hour, Minute, Second;

public:
    Time(int hour, int minute, int second)
    {
        bool flag = false;

        if (hour >= 0 && hour < 24)
            Hour = hour;
        else
            flag = true;
        if (minute >= 0 && minute < 60)
            Minute = minute;
        else
            flag = true;
        if (second >= 0 && second < 60)
            Second = second;
        else
            flag = true;

        if (flag)
        {
            cout << "time input error" << endl;
            Hour = Minute = Second = 0;
        }
    }

    void Show()
    {
        cout << Hour << ':' << Minute << ':' << Second << endl;
    }

    friend Time operator+(Time &A, Time &B)
    {
        int hour = 0, minute = 0, second = 0;
        second = A.Second + B.Second;
        if (second >= 60)
        {
            minute += 1;
            second = second % 60;
        }
        minute += A.Minute + B.Minute;
        if (minute >= 60)
        {
            hour += 1;
            minute = minute % 60;
        }
        hour += A.Hour + B.Hour;
        if (hour >= 24)
            hour = hour % 24;
        return Time(hour, minute, second);
    }
};

int main()
{
    Time a(25, 00, 59);
    Time b(10, 20, 20);
    Time c(02, 10, 10);
    cout << "b:";
    b.Show();
    cout << "c:";
    c.Show();

    a = b + c;
    cout << "a = b+c:";
    a.Show();

    system("pause");
}