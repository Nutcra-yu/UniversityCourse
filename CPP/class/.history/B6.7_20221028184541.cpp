#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class String
{
private:
    string a;

public:
    String()
    {
        
    }
};

int main()
{
    String S1("hello");

    S1.Show();

    cout << endl;
    system("pause");
}