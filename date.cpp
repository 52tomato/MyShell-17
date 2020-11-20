#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  time_t timeval;
  (void)time(&timeval);
  string timestr = ctime(&timeval);
  cout<<timestr;
  return 0;
}
