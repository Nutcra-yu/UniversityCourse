#include<stdio.h>

#define NUMBER 100

int search (int n , int a[] , int key ) 	//��n��Ԫ�ص�����a��Ѱ��key 
{
	int i=0;
	a[n] = key;
	while(1)
	{
		if( a[i] == key ) 	return i;
		i++;
	}
}

int main()
{ 	//�ڱ�����
	int n;
	int i;
	int a[ NUMBER ];
	int key;
	
	printf("�������뼸������");
	scanf("%d",&n);
	putchar('\n');
	 
	for(i=0;i<n;i++)
	{
		printf("a[%d]�ǣ�",i);
		scanf("%d",&a[i] );
	}
	
	putchar('\n');
	printf("�����ҵ����ǣ�");
	scanf("%d",&key);
	putchar('\n');
	
	int result = search( n , a ,key);
	if(result == n) 	puts("����ʧ��");
	else 	printf("��Ҫ�ҵ���a[%d]",result);
	
	return 0; 
}
