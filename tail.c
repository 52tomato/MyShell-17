#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define BUFFERSIZE 512
int main(int argc,char **argv)
{
	char c;
	int line=10;
	int count=0;
	char buffer[BUFFERSIZE][BUFFERSIZE];
	while((c=getopt(argc,argv,"n:"))!=-1)
	{
		int x=atoi(optarg);
		line=x;
	}
	char *path=argv[optind];
	FILE *fp;
	int index=0;
	if((fp=fopen(path,"r"))==NULL)
	{
		printf("File doesn't exit!\n");
		return -1;
	}
	while(!feof(fp))
	{
		count++;
		fgets(buffer[index],BUFFERSIZE,fp);
		if(index+1>=line)
			index=0;
		else
			index++;
	}
	fclose(fp);
	int i;
	if(count<line)
		line=count;
	if(index!=0)
		index--;
	for(i=0;i<line;i++)
	{
		printf("%s",buffer[index++]);
		if(index>=line)
			index=0;
	}
}
