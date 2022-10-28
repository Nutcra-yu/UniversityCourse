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
	
	//将D连接到S后面 
	for(int i=0;i<=lenD;i++)
	{ 
		SStr[lenS+i] = DStr[i];
	}
	
	cout<<SStr;
}




