#include<stdio.h>
#include<string.h>

int main() {
	
	/*
	FILE *fp = fopen("demo","");
	if( fp ) {

	} else {
		printf("�޷����ļ�\n");
	}
	*/
	
	int t=0;
	while(printf("*"))
	{
		t++;
		if(t>3) break;
	}
	return 0;
	
}
