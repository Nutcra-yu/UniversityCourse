/*
1）定义一个人员类Person，并派生出学生类Student和教师类Teacher，由学生类和教师类共同派生出助教类Stu_Teacher，
    人员类有姓名、性别、出生日期和身份ID，以及Display()函数输出基本信息。
    学生有姓名，籍贯 ，学号，年龄，成绩五个成员数据，
    教师有职称信息。
2）编写构造函数，拷贝构造函数，同时编写Display(),成员函数显示学生的信息。
3）编写“+”运算符重载函数，使Student类的两个对象相加返回两个对象总成绩相加的和。
4）编写主函数，定义两个Student类对象，分别调用成员函数Display（），显示两个对象的学生信息，同时显示两个对象相加的结果
5）定义一个抽象类指针，分别指向派生类对象，使得根据派生类对象的不同，通过该指针或引用，能正确调用派生类的成员函数Display（）。
*/
#include <iostream>
using namespace std;

enum Gender
{
    female = 0,
    male = 1
};
struct date
{
    int year, month, day;
};

class Person
{
protected:
    char *Name;           //姓名
    Gender gender;        //性别
    char *ID;             // ID
    struct date Birthday; //生日

public:
    Person(char *Name, Gender gender, char *ID, struct date &birthday)
    {
        this->Name = Name;
        this->gender = gender;
        this->ID = ID;
        this->Birthday.day = birthday.day;
        this->Birthday.month = birthday.month;
        this->Birthday.year = birthday.year;
    }
    Person(char *Name, Gender gender, char *ID, struct date *birthday)
    {
        this->Name = Name;
        this->gender = gender;
        this->ID = ID;
        this->Birthday.day = birthday->day;
        this->Birthday.month = birthday->month;
        this->Birthday.year = birthday->year;
    }

    virtual void Display()
    {
        cout << Name;
        if (gender == 0)
            cout << " 女 " << endl;
        else
            cout << " 男 " << endl;
        cout << " 身份证:" << ID << endl;
        cout << " 出生日期:" << Birthday.year << ' ' << Birthday.month << ' ' << Birthday.day << endl;
    }
};

class Student : virtual public Person
{
protected:
    //姓名 性别 ID 生日
    char *StuId;       //学号
    float score;       //成绩
    char *NativePlace; //籍贯
    int age;           //年龄

public:
    Student(char *StuId, float score, char *nativePlace, char *Name, Gender gender, char *ID, struct date &birthday) : Person(Name, gender, ID, birthday)
    {
        this->StuId = StuId;
        this->score = score;
        this->NativePlace = nativePlace;
        age = 2022 - birthday.year;
    }

    Student(Student &a) : Person(a.Name, a.gender, a.ID, a.Birthday)
    {
        Name = a.Name;
        gender = a.gender;
        ID = a.ID;
        Birthday = a.Birthday;
        StuId = a.StuId;
        score = a.score;
        NativePlace = a.NativePlace;
        age = a.age;
    }

    void Display()
    {
        Person::Display();
        cout << " 学号:" << StuId << endl;
        cout << " 成绩:" << score << endl;
        cout << " 籍贯:" << NativePlace << endl;
        cout << " 年龄:" << age << endl;
    }

    friend int operator+(Student &A, Student &B)
    {
        return A.score + B.score;
    }
};

class Teacher : virtual public Person
{
protected:
    char *title;

public:
    Teacher(char *title, char *Name, Gender gender, char *ID, struct date &birthday) : Person(Name, gender, ID, birthday)
    {
        this->title = title;
    }

    void Display()
    {
        Person::Display();
        cout << " 职称:" << title << endl;
    }
};

class Stu_Tech : public Teacher, public Student
{
public:
    Stu_Tech(char *StuId, float score, char *nativePlace, char *title, char *Name, Gender gender, char *ID, struct date &birthday) : Student(StuId, score, nativePlace, Name, gender, ID, birthday), Teacher(title, Name, gender, ID, birthday), Person(Name, gender, ID, birthday)
    {
    }

    void Display()
    {
        Student::Display();
        cout << " 职称:" << title << endl;
    }
};

int main()
{
    date bir1;
    bir1.year = 2022;
    bir1.year = 11;
    bir1.day = 4;

    date bir2;
    bir2.year = 2000;
    bir2.year = 1;
    bir2.day = 1;

    Student A("0001", 7, "WuHan", "stu_A", male, "WH0001", bir1);
    Student B("0002", 8, "GuangZhou", "stu_b", female, "GZ0001", bir2);

    A.Display();
    B.Display();

    cout << A + B << endl;

    Person *point = &A;
    point->Display();
    point = &B;
    point->Display();
}
