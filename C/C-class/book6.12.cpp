#include<stdio.h>
int main()
{
	int i;
	for(i=0;i<=3;i++)
	{
		char thisman ='A' + i;
		int sum = (thisman != 'A')+(thisman == 'C')+(thisman == 'D')+(thisman != 'D');
		
		if(sum==3) printf("%c",thisman);
	}
}
