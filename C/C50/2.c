#include<stdio.h>
int main()
{
	int a,b; 	//���ſεĳɼ� 
	
	puts("���������ſεĳɼ�");
	printf("��һ�ſεĳɼ��ǣ�");
		scanf("%d",&a); 
	printf("�ڶ��ſεĳɼ��ǣ�");
		scanf("%d",&b); 
	
	int m;
	if(a>=60 && b>=60) m=1;
	if( a<60 || b<60 ) m=2;
	if(a<0 || b<0 || a>100 || b>100) 	m=3;
	
	switch(m)
	{
		case 1 :puts("it is pass.");		break;
		case 2 :puts("it is not pass.");	break;
		case 3 :puts("it is error.");		break;
	}
	
	return 0;
			
}
