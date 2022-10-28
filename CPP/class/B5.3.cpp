#include <iostream>
using namespace std;

class date
{
private:
	int Year, Month, Day;
	//非闰年天数
	const int MonthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
	date(int year, int month, int day)
	{

		//判断是闰年的2月29
		if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && day <= 29)
		{
			Year = year;
			Month = month;
			Day = day;
		}
		else if (month <= 12 && day <= MonthDay[month - 1])
		{
			Year = year;
			Month = month;
			Day = day;
		}
		else
		{
			cout << "输入错误" << year << " " << month << " " << day;
		}
	}

	void show()
	{
		cout << Year << "/" << Month << "/" << Day ;
	}

	void NewDay()
	{

		//判断是闰年的2月
		if (((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0) && Month == 2)
		{
			// 2.28
			if (Day == 29)
			{

				Day = 1;
				Month = (Month + 1) % 12;
			}
			else if (Day == 28)
			{
				Day++;
			}
		} //平年天数超过
		else if (Day == MonthDay[Month - 1])
		{
			Day = 1;
			Month = (Month + 1) % 12;
		}
		else
		{
			Day++;
		}
	}
};

int main01()
{
	date A(2020, 2, 29);

	int i;
	for (i = 0; i < 40; i++)
	{
		A.show();
		A.NewDay();
	}

	system("pause");
}
