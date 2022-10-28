#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class String
{
private:
    string s;

public:
    String()
    {
        s= "";
    }
};

int main()
{
    String S1("hello");

    S1.Show();

    cout << endl;
    system("pause");
}