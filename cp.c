/*
C语言实现linux cp命令
*/
 
#include <sys/stat.h>	//open()所需头文件
#include <sys/types.h>  //lseek()所需头文件
#include <fcntl.h>		
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  //write read 所需头文件
 
int main(int argc,char *argv[])
{
	if(argc<3)
	{
		printf("传入的参数少了，应该输入 ./main filename destname\n");
		return -1;
	}
	int fd;
	int buf_fd;
	int buf_size;
 
	char buf_addr[100]={0};
	buf_fd=open(argv[1],O_RDWR);       //打开源文件
	buf_size=lseek(buf_fd,0,SEEK_END); //将文件指针偏移到文件末尾
	printf("buf_size is:%d\n",buf_size);
	lseek(buf_fd,-buf_size,SEEK_CUR);  //将文件指针向前移动buf_size个字节，否则无法读到文件内容
	
	read(buf_fd,buf_addr,buf_size);    //读出源文件的内容到buf_addr缓冲器
	printf("buf_addr is:%s\n",buf_addr);
 
	//打开目标文件，不存在则创建，存在则清空，可读可写
	fd=open(argv[2],O_CREAT|O_RDWR|O_TRUNC);	
	if(fd==-1)
	{
		perror("failed");
		return -1;
	}else{
		//将buf_addr缓冲器内容写入目标文件中
		write(fd,buf_addr,buf_size);
		printf("复制%s中的内容到%s成功\n",argv[1],argv[2]);
	}
	close(fd);
	close(buf_fd);
	return 0;
}
 
 
