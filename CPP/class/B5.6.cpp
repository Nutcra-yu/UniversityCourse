#include <iostream>
#include<string.h>
using namespace std;

#define KEY_LEN 8

class User
{
private:
    char id[8];
    char key[KEY_LEN];

public:
    User()
    {
        cout << "请注册账号id:";
        cin >> id;

        do{
        cout << "请输入密码(" << KEY_LEN << "位):";
        cin >> key;
        }while (strlen(key)<8);
    }

    bool checkKey(char *Pass)
    {
        bool flag = true;

        int i;
        for (i = 0; i <= KEY_LEN; i++)
            if (*(Pass + i) != this->key[i])
                flag = false;

        return flag;
    }
};

int main()
{
    User mUser = User();
    
    cout<<"\\\\test//"<<endl;
    
    char test[KEY_LEN];
    do{
    cout<<"请输入密码:";
    cin>>test;
    }while (strlen(test)<8);

    if (mUser.checkKey(test))
        cout<<"welcome"<<endl;
    else
        cout<<"wrong"<<endl;
    
    
    system("pause");
}

