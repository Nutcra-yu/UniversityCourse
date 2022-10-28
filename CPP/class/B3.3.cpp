#include<iostream>
#include<Cstring>
using namespace std;

int main()
{
	char a[100];
	cin>>a;
	
	int len=strlen(a);
	char b[len];
	for(int i=0;i<=len;i++)
	{
		b[i] = a[len-1-i];
	}
	
	cout<<b<<endl;

	system("pause");
}




