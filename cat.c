#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	if(argc==2)
	{
		FILE *fp;
		if(!(fp=fopen(argv[1],"r")))
		{
			fprintf(stderr,"cannot open file %s.",argv[1]);
			exit(-1);
		}
		int c;
		while((c=fgetc(fp))!=EOF)
			fputc(c,stdout);
		fclose(fp);
	}
	else if(argc==3)
	{
		FILE *src;
		FILE *dest;
		if(!(src=fopen(argv[1],"r")))
		{
			fprintf(stderr,"%s:cannot open file %s\n",argv[0],argv[1]);
			exit(-1);
		}
		if(!(dest=fopen(argv[2],"w+")))
		{
			fprintf(stderr,"%s:cnnot open file %s\n",argv[0],argv[1]);
			exit(-1);
		}
		int c;
		while((c=fgetc(src))!=EOF)
			fputc(c,dest);
		fclose(src);
		fclose(dest);
	}
	return 0;
}
