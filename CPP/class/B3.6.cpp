#include<iostream>
#include<Cstring>
using namespace std;

int main()
{
	char DStr[100];
	char SStr[100];
	
	cout<<"input SStr:";
	cin>>SStr;
	cout<<"input DStr:";
	cin>>DStr;
	
	int lenD = strlen(DStr);
	int lenS = strlen(SStr);
	
	//��D���ӵ�S���� 
	for(int i=0;i<=lenD;i++)
	{ 
		SStr[lenS+i] = DStr[i];
	}
	
	cout<<SStr;
}




