//����һ�����ڣ������������Ǹ���ĵڼ��졣
//���������ж��飬ÿ��ռһ�У����ݸ�ʽΪYYYY/MM/DD���
//����0��������
 
#include<stdio.h>
int main()
{
	printf("����һ�����ڣ������������Ǹ���ĵڼ���\n"
	"���������ж��飬ÿ��ռһ�У����ݸ�ʽΪYYYY/MM/DD���\n"	
	"����0��������\n\n");
	
	
	/*��Ҫ�ı���*/
	
	//i ������� 
		//year[i]�����
		//month[i]�����
		//day[i]�����
	int i;
	//3������  ��������� 
	int  year[100] = {0};
	int month[100] = {0};
	int   day[100] = {0};
	//monthdata ���ÿ���µ�����
	int monthdata[12]={31,28,31,30,31,30,31,31,30,31,30,31} ;
	//cnt ��¼���ݸ��� 
	int cnt = 0 ;
	//sum�������
	int sum = 0 ; 
	
	
	 
	//�洢���� 
	for(i=0;;i++)
	{
		scanf("%d/%d/%d",&year[i],&month[i],&day[i]);
		if(year[i] == 0) 	break;
		cnt ++;
	}
	
	printf("\n");
	
	//��������
	for(i=0;i<cnt;i++)
	{
		int m;
		for(m=1;m<month[i];m++)
		{
			sum += monthdata[m-1];
		}
		
		sum += day[i];
		
		if(year[i]%4 == 0 && month[i]>2 )
			sum += 1;
		
		printf("%d/%d/%d�ǵ���ĵ� %d ��\n",year[i],month[i],day[i],sum);
	} 
}





