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
private:
    char *Name;
    Gender gender;
    char *ID;
    struct date birthday;

public:
    Person(char *Name, Gender gender, char *ID, struct date *birthday)
    {
        this->Name = Name;
        this->gender = gender;
        this->ID = ID;
        this->birthday.day = birthday->day;
        this->birthday.month = birthday->month;
        this->birthday.year = birthday->year;
    }
};

class Student : virtual public Person
{
private:
    char *StuId;
    float score;

public:
    Student(char *StuId, float score, char *Name, Gender gender, char *ID, struct date *birthday) : Person(Name, gender, ID, birthday)
    {
        this->StuId = StuId;
        this->score = score;
    }
};

class Teacher : virtual public Person
{
private:
    char *title;

public:
    Teacher(char *title, char *Name, Gender gender, char *ID, struct date *birthday) : Person(Name, gender, ID, birthday)
    {
        this->title = title;
    }
};

class Stu_Tech : public Teacher, public Student
{
public:
    Stu_Tech(char *StuId, float score, char *title, char *Name, Gender gender, char *ID, struct date *birthday) : 
        Student(StuId, score, Name, gender, ID, birthday), Teacher(title, Name, gender, ID, birthday),Person(Name, gender, ID, birthday)
    {
    }
};

int main()
{
    char StuId[5] = "4098";
    char name[4] = "zyu";
    char title[7] = "leader";
    char ID[5] = "0101";
    date birthday = {2004, 01, 01};
    Stu_Tech me(StuId, 100, title, name, male, ID, &birthday);
}

