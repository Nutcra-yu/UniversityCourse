#include<stdio.h>
int main()
{
 int row,i,j;
 int firstday[13] = {0};
 int year;
 int month;
 int Month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  
 
 printf("��ݣ�"); 
 scanf("%d",&year);
 
 if(year%4 == 0)  Month[1] = 29;
 
 for(month = 1;month <= 12; month += 3)
 {
  /* i �� month ������ڼ���*/
  
  //��ͷ 
  for(i=0;i<3;i++) printf("\t   %d��  \t",month+i); putchar('\n');
  for(i=0;i<3;i++) printf("�� һ �� �� �� �� ��  "); putchar('\n');
  
  
  for(i=0;i<3;i++) 
  {
   //����ÿ���µĵ�һ�������ڼ� 
   if(month+i == 1||month+i == 2)
    firstday[month+i] = (1 + 2*(month+i+12)+ 3*(month+i+13)/5 + (year-1) + (year-1)/4 - (year-1)/100 + (year-1)/400) % 7 ;
   else
    firstday[month+i] = (1 + 2*(month+i) + 3*(month+i+1)/5 + year + year/4 - year/100 + year/400) % 7 ;
  }
   
  int ordinal ;
  /*
  �� һ �� �� �� �� �� 
  6  0  1  2  3  4  5  
  (+1)
  7  1  2  3  4  5  6
  (%7)
  0  1  2  3  4  5  6   ordinal 
  */
  
  //ÿ�е������� de ��һ�� 
  for(i=0;i<3;i++)
  {
   ordinal = (firstday[month+i]+1)%7;
   //1��ǰ�Ŀո� 
   for(j=0;j<ordinal;j++) printf("   ");
   
   //ÿ���µĵ�һ�� 
   for(j=1;j<=7-ordinal;j++) printf("%-3d",j); printf(" ");
  }
  printf("\n");
  
  //ÿ�е������� de ������ 
  for(row=1;row<=4;row++)
  {
   for(i=0;i<3;i++)
   {
    ordinal = (firstday[month+i]+1)%7;
    int cnt = 1;
    for(j=7*row+1-ordinal;cnt<=7;j++)
    {
     if(j > Month[month+i-1])
      printf("   ");
     else 
      printf("%-3d",j);
     cnt++;
    }
    printf(" ");
   }
   printf("\n");
  }
  
  
  
  printf("\n\n");
 }
}
