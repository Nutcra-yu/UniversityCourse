#include <iostream>
#define  CLASS_NUMBER 2
using namespace std;

class Student
{
private:
    char name[10];              //名字
    char id[10];                //学号
    double score[CLASS_NUMBER]; //成绩
    double average;             //平均分

public:
    Student()
    {
        double sum=0;

        cout<<"请输入学生姓名:";
        cin>>name;

        cout<<"请输入学生学号:";
        cin>>id;

        cout<<"输入学生成绩"<<endl;
        int i;
        for(i=0;i<CLASS_NUMBER;i++)
        {
            cout<<"  科目"<<i+1<<":";
            cin>>score[i];

            sum+=score[i];
        }

        average = sum/CLASS_NUMBER;
        cout<<"平均成绩"<<average<<endl;

    }

    
};

int main()
{
    Student me = Student();

    system("pause");
}

