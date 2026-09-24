#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int start = uptime();
  while (uptime() - start < 20) {
  }
  exit(0);
}
