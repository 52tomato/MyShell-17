#include<stdio.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[])
{
  FILE *fstream = NULL;
  char buff[1024];
  memset(buff, 0, sizeof(buff));
  if(NULL == (fstream=popen("uname -a", "r")))
  {
    fprintf(stderr, "execute command failed: %s", strerror(errno));
    return -1;
  }
  if(NULL!=fgets(buff, sizeof(buff), fstream))
  {
    printf("=>%s", buff);
  }
  else
  {
    pclose(fstream);
    return -1;
  }
  pclose(fstream);
  return 0;
}
