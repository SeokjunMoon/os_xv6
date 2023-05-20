// hw2_1.c
// Test case #1 for Round Robin Scheduling

#include "types.h"
#include "stat.h"
#include "user.h"

void testgetnice(int pid, int nice)
{
  if(getnice(pid) != nice) {
    printf(1, "bad implementation of syscall getnice\n");
    exit();
  }
}

int main(int argc, char** argv)
{
  int child1;
  int child2;

  setnice(1, 0);
  setnice(getpid(), 2);

  testgetnice(1, 0);
  testgetnice(getpid(), 2);

  child1 = fork();

  if (child1 == 0) {
    printf(1, "##### Step 4 #####\n");
  }
  else {
    setnice(child1, 10);
    testgetnice(child1, 10);
    printf(1, "##### Step 1 #####\n");

    child2 = fork();

    if (child2 == 0) {
      printf(1, "##### Step 3 #####\n");
    }
    else {
      setnice(child2, 5);
      testgetnice(child2, 5);
      printf(1, "##### Step 2 #####\n");
    }
  }

  printf(1, "PID %d exited\n", getpid());

  exit();
}
