#include<iostream>
#include<Cstring>
using namespace std;

int main()
{
	char s1[100],s2[100];
	
	cin>>s2;
	
	for(int i=0;s2[i]!='\0';i++)
	 s1[i] = s2[i];
	 
	cout<<"s1:"<<s1<<endl;
	cout<<"s2:"<<s2<<endl;
}



