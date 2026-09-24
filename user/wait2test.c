#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(void)
{
  int status = -1;
  struct rusage usage = {0};
  int pid = fork();

  if (pid < 0)
    exit(1);
  if (pid == 0){
   int start = uptime();
   while (uptime() - start < 5)
    ;
    exit(7);
  }

  int child = wait2(&status, &usage);
  printf("pid=%d status=%d cputime=%d\n", child, status, usage.cputime);
  exit(child == pid && status == 7 ? 0 : 1);
}
