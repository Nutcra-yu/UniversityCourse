#include<stdio.h> 		/*���Բ���*/

#define NUMBER 5


int search( int n , int a[] , int x) 	//Ѱ��n�Ƿ������a[x]�У�����Ϊ1��������Ϊ0 
{
	int i=1;
	
	while(1)
	{
		if(n == a[i-1]) 	return i;	//i>=1 
		if(i == x) return 0;
		i++;
	}
}


int main()
{
	int a[NUMBER];
	int i,n;
	
	for(i=0;i<NUMBER;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	
	puts("����������Ѱ�ҵ���");
	scanf("%d",&n); 
	
	int sear = search( n , a , NUMBER);
	 
	if(sear == 0) 	printf("%d����a[]����Ŷ"); 
	else 				printf("%d��a[%d]",n,sear-1);
	
	return 0;
	
}

/*�ð�
�Ҹ�����û����ѧ���������ڻ�ʱ������
TMDܳ
����ô����ѽ
���а����а�
rnm rnm rnm rnm */
