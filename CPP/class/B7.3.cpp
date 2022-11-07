#include <iostream>
using namespace std;
class Set
{
private:
    int *pa; //指向数组的指针
    int a;   //集合成员个数
public:
    bool use;              //控制析构函数析构
    Set();                 //构造函数
    ~Set();                //析构函数
    Set(Set &Sn);          //拷贝构造
    bool isin(int c);      //判断元素c是否在集合内
    void showset();        //显示集合内元素
    Set operator+=(int b); //重载操作符为成员函数
    Set operator-=(int b);
    void operator<=(Set A);
    Set operator|(Set A);
    Set operator&(Set A);
    Set operator-(Set A);
};

int num; //判断元素是否在集合内时，计算元素所在位置
Set::Set()
{
    use = false; //在程序结束赋值为true使析构函数被调用
    pa = NULL;
    a = 0;
}
Set::~Set()
{
    if (pa != NULL && use == true)
    {                //析构函数限制，防止运行过程中析构造成错误
        delete[] pa; //因为程序中使用new创建了动态数组
        pa = NULL;
        a = 0;
    }
}
Set::Set(Set &Sn)
{
    a = Sn.a;
    if (a != 0)
    {
        pa = new int[a + 1]; // so 析构函数中需要delete
        for (int i = 1; i <= a; i++)
        {
            pa[i] = Sn.pa[i];
        }
    }
}
bool Set::isin(int c)
{
    num = 0;
    for (int i = 1; i <= a; i++)
    {
        if (pa[i] == c)
        {
            num = i;
            return true;
        } // num为c所在位置
    }
    return false;
}
void Set::showset()
{
    cout << "[";
    for (int i = 1; i <= a; i++)
        cout << pa[i] << ",";
    cout << "]";
    cout << endl;
}
Set Set::operator+=(int b)
{
    if (isin(b)) // b已经在集合内时不继续添加
        return *this;
    Set Tpa;                     //建立新的Set对象将集合原本的元素复制进去，并清除指针，以增加数组长度
    for (int i = 1; i <= a; i++) // i=1（j=1）时进入循环，使i=0时可以添加第一个元素
        Tpa += pa[i];
    a++;
    if (pa != NULL)
        delete[] pa;
    pa = new int[a + 1]; //建立新的数组，长度加一
    for (int j = 1; j < a; j++)
        pa[j] = Tpa.pa[j];
    pa[a] = b;
    return *this;
}
Set Set::operator-=(int b)
{
    if (!isin(b))
    {
        cout << "该元素不在集合内";
        return *this;
    }
    a--;
    for (int i = num; i <= a; i++)
    {
        pa[i] = pa[i + 1]; // b后的元素都向前移动一位
    }
    return *this;
}
void Set::operator<=(Set A)
{
    int num1; //控制包含与否的判断
    if (a > A.a)
        cout << "不包含于";
    else
    {
        for (int i = 1; i <= a; i++)
        {
            if (!A.isin(pa[i]))
                num1++;
        }
        if (num1 = a)
            cout << "包含于";
        else
            cout << "不包含于";
    }
}
Set Set::operator|(Set A)
{
    Set AS;
    for (int i = 1; i <= a; i++)
    {
        AS += pa[i];
    }
    for (int i = 1; i <= A.a; i++)
    {
        if (!isin(A.pa[i]))
            AS += A.pa[i];
    }
    return AS;
}
Set Set::operator&(Set A)
{
    Set BS;
    for (int i = 1; i <= a; i++)
    {
        BS += pa[i];
    }
    for (int i = 1; i <= a; i++)
    {
        if (!A.isin(pa[i]))
            BS -= pa[i];
    }
    return BS;
}
Set Set::operator-(Set A)
{
    Set CS;
    for (int i = 1; i <= a; i++)
    {
        CS += pa[i];
    }
    for (int i = 1; i <= a; i++)
    {
        if (A.isin(pa[i]))
            CS -= pa[i];
    }
    return CS;
}

int main()
{
    cout << endl
         << "+=增加元素测试--" << endl;
    Set S1, S2, S3, S4;
    S1 += 1, S1 += 3, S1 += 5, S1 += 10, S1 += 2, S1 += 8, S1 += 1;
    cout << "增加元素   S1=";
    S1.showset();

    cout << endl
         << "-=删除元素测试--" << endl;
    S1 -= 5;
    cout << "删除元素‘5’   S1=";
    S1.showset();

    cout << endl
         << "<=包含于测试" << endl;
    S2 += 1, S2 += 3, S2 += 5, S2 += 10, S2 += 2, S2 += 8, S2 += 13, S2 += 6;
    cout << "S2=";
    S2.showset();
    cout << "S1";
    S1 <= S2;
    cout << "S2" << endl;
    cout << "S2";
    S2 <= S1;
    cout << "S1" << endl;

    cout << endl
         << "|并测试" << endl;
    S3 += 9, S3 += 23, S3 += 2;
    cout << "S3=";
    S3.showset();
    S4 = S2 | S3;
    cout << "S2与S3的并=";
    S4.showset();

    cout << endl
         << "&交测试" << endl;
    cout << "S2与S3的交=";
    S4 = S2 & S3;
    S4.showset();

    cout << endl
         << "-减测试" << endl;
    cout << "S2减S3";
    S4 = S2 - S3;
    S4.showset();

    S1.use = true;
    S2.use = true;
    S3.use = true;
    S4.use = true;

    

    system("pause");
}