#include<stdio.h>
#include<fcntl.h>
#include<time.h>
#include<unistd.h>
#include<utmp.h>

void show_time(long timeval){
  char *cp;
  cp = ctime(&timeval);
  printf("%12.12s", cp+4);
}

void show_info(struct utmp *utbufp){
  if(utbufp->ut_type != USER_PROCESS)
    return ;
  printf("%-8.8s", utbufp->ut_name);
  printf(" ");
  printf("%-8.8s", utbufp->ut_line);
  printf(" ");
  show_time(utbufp->ut_time);
  printf(" ");
  printf("(%s)", utbufp->ut_host);
  printf("\n");
}

int main(){
  struct utmp current_record;
  int utmp_fd;
  int reclen = sizeof(current_record);

  utmp_fd = open(UTMP_FILE, O_RDONLY);
  if(utmp_fd == -1)
    return -1;
  
  while(read(utmp_fd, &current_record, reclen) == reclen)
    show_info(&current_record);
  
  close(utmp_fd);
  return 0;
}

