#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  int start, status, pid;

  if (argc < 2) {
    fprintf(2, "usage: time1 command [args...]\n");
    exit(1);
  }

  start = uptime();
  pid = fork();

  if (pid < 0) {
    fprintf(2, "time1: fork failed\n");
    exit(1);
  }

  if (pid == 0) {
    exec(argv[1], &argv[1]);
    fprintf(2, "time1: cannot execute %s\n", argv[1]);
    exit(1);
  }

  if (wait(&status) < 0) {
    fprintf(2, "time1: wait failed\n");
    exit(1);
  }

  printf("elapsed time: %d ticks\n", uptime() - start);
  exit(status);
}
