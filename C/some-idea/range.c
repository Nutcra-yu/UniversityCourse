/*
	��ʾ�ַ��ͺ������������͵ı�ʾ��Χ
*/

#include <stdio.h>
#include <limits.h>
#include <stddef.h>

int main(void)
{
	printf("CAHR_BIT       :%d\n",CHAR_BIT);
	printf("sizeof char    :%d\n",sizeof(char));
//	printf("INT_BIT        :%d\n",INT_BIT);
	printf("sizeof int     :%d\n",sizeof(int));
	printf("sizeof unsigned:%d\n",sizeof(unsigned int));
	printf("sizeof long    :%d\n",sizeof(long));
	printf("sizeof short   :%d\n",sizeof(short));
	
	
	puts("\n�û����¸��ַ��͡�������ֵ�ķ�Χ");
	printf("char           : %d~%d\n",   CHAR_MIN , CHAR_MAX);
	printf("signed char    : %d~%d\n",   SCHAR_MIN, SCHAR_MAX);
	printf("unsignd char   : %d~%d\n",   0        , UCHAR_MAX);

	printf("short          : %d~%d\n",   SHRT_MIN , SHRT_MAX);
	printf("int            : %d~%d\n",   INT_MIN  , INT_MAX);
	printf("long           : %ld~%ld\n", LONG_MIN , LONG_MAX);

	printf("unsigned short : %u~%u\n",   0        , USHRT_MAX);
	printf("unsigned       : %u~%u\n",   0        , UINT_MAX);
	printf("unsigned long  : %lu~%lu\n", 0        , ULONG_MAX);
	
	
	
	
	return 0;
}
