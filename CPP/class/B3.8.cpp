#include<iostream>
#include<Cstring>
using namespace std;

int main()
{
	int flag =1;
	char s[100];
	
	cin>>s;
	
	int i=0,len=strlen(s);
	if( s[i] == s[len-1-i] )
		i++;
	else 
		flag = 0;
		
	if( flag == 1 ) cout<<"是";
	else cout<<"不是"; 
	
	cout<<"回文数"; 
}



