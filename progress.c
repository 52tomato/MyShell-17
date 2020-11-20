#include<stdio.h>
#include<string.h>
#include<unistd.h>
void porc()
{
	int rate=0;
	char bar[102];
	memset(bar,'\0',sizeof(bar));
	const char* lable="|/-\\";
	printf("waiting\n");
	while(rate<=100)
	{
		bar[rate]='=';
		printf("[%-101s][%d%%][%c]\r",bar,rate,lable[rate%4]);
		fflush(stdout);
		rate++;
		usleep(100000);
	}
	printf("\n");
	printf("success\n");
}
int main()
{
	porc();
	return 0;
}
