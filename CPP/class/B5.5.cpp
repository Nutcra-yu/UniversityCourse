#include <iostream>
#define  CLASS_NUMBER 2
using namespace std;

class Student
{
private:
    char name[10];              //����
    char id[10];                //ѧ��
    double score[CLASS_NUMBER]; //�ɼ�
    double average;             //ƽ����

public:
    Student()
    {
        double sum=0;

        cout<<"������ѧ������:";
        cin>>name;

        cout<<"������ѧ��ѧ��:";
        cin>>id;

        cout<<"����ѧ���ɼ�"<<endl;
        int i;
        for(i=0;i<CLASS_NUMBER;i++)
        {
            cout<<"  ��Ŀ"<<i+1<<":";
            cin>>score[i];

            sum+=score[i];
        }

        average = sum/CLASS_NUMBER;
        cout<<"ƽ���ɼ�"<<average<<endl;

    }

    
};

int main()
{
    Student me = Student();

    system("pause");
}

