#include<stdio.h>
int main()
{
	printf("sizeof int            :%d\n",sizeof(int));
	printf("sizeof unsigned (int) :%d\n",sizeof(unsigned int));
	printf("sizeof signed (int)   :%d\n",sizeof(signed int));
	printf("sizeof double         :%d\n",sizeof(double));
	printf("\n");
	
	printf("sizeof 1              :%d\n",sizeof 1);
	printf("sizeof +1             :%d\n",sizeof +1);
	printf("sizeof -1             :%d\n",sizeof -1);
	printf("\n");
	
	printf("sizeof (unsigned)-1   :%d\n",sizeof (unsigned)-1);
	printf("sizeof (double)-1     :%d\n",sizeof (double)-1);
	printf("sizeof ((double)-1)   :%d\n",sizeof ((double)-1));
	printf("\n");
	
	int n=0;
	printf("n=0\n");
	printf("sizeof n+2            :%d\n",sizeof n+2);
	printf("sizeof (n+2)          :%d\n",sizeof (n+2));
	printf("sizeof (n+2.0)        :%d\n",sizeof (n+2.0));
	printf("\n");
	
	n=1;
	printf("n=1\n");
	printf("sizeof n+2            :%d\n",sizeof n+2);
	printf("sizeof (n+2)          :%d\n",sizeof (n+2));
	printf("sizeof (n+2.0)        :%d\n",sizeof (n+2.0));
	printf("\n");
	
	int arr[10];
	printf("sizeof(arr)           :%d\n",sizeof(arr));
	printf("sizeof(arr[0])        :%d\n",sizeof(arr[9]));
	printf("sizeof(arr+1)         :%d\n",sizeof(arr+1));
}
