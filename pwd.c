#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include<stdlib.h>
 
#define BUF_SIZ    2048
int main()
{
    char buf[BUF_SIZ];   
   
    if ( getcwd(buf, BUF_SIZ) )
        printf("%s \r\n", buf);
    else
        fprintf(stderr, "error occured : %s", strerror(errno));
    exit(0);
}
