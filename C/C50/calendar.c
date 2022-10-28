#include<stdio.h>
int main()
{
 int row,i,j;
 int firstday[13] = {0};
 int year;
 int month;
 int Month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  
 
 printf("年份："); 
 scanf("%d",&year);
 
 if(year%4 == 0)  Month[1] = 29;
 
 for(month = 1;month <= 12; month += 3)
 {
  /* i 与 month 结合用于记月*/
  
  //标头 
  for(i=0;i<3;i++) printf("\t   %d月  \t",month+i); putchar('\n');
  for(i=0;i<3;i++) printf("日 一 二 三 四 五 六  "); putchar('\n');
  
  
  for(i=0;i<3;i++) 
  {
   //计算每个月的第一天是星期几 
   if(month+i == 1||month+i == 2)
    firstday[month+i] = (1 + 2*(month+i+12)+ 3*(month+i+13)/5 + (year-1) + (year-1)/4 - (year-1)/100 + (year-1)/400) % 7 ;
   else
    firstday[month+i] = (1 + 2*(month+i) + 3*(month+i+1)/5 + year + year/4 - year/100 + year/400) % 7 ;
  }
   
  int ordinal ;
  /*
  日 一 二 三 四 五 六 
  6  0  1  2  3  4  5  
  (+1)
  7  1  2  3  4  5  6
  (%7)
  0  1  2  3  4  5  6   ordinal 
  */
  
  //每行的三个月 de 第一行 
  for(i=0;i<3;i++)
  {
   ordinal = (firstday[month+i]+1)%7;
   //1号前的空格 
   for(j=0;j<ordinal;j++) printf("   ");
   
   //每个月的第一行 
   for(j=1;j<=7-ordinal;j++) printf("%-3d",j); printf(" ");
  }
  printf("\n");
  
  //每行的三个月 de 后四行 
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
