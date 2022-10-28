#include<iostream>
#include<Cstring>
using namespace std;

void deleteN(char* a,int N);

int main()
{
	char a[100];
	cin>>a;
	
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='c') {
		deleteN(a,i);
		i--;
		}
	}
	
	cout<<a<<endl;
}

void deleteN(char* a,int N)
{
	for(;N<strlen(a);N++)
		a[N] = a[N+1];
}



