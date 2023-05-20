// hw2_3.c
// Test case #3 for Round Robin Scheduling

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
  int child;
  int parent;

  setnice(1, 0);
  setnice(getpid(), 10);

  testgetnice(1, 0);
  testgetnice(getpid(), 10);

  parent = getpid();
  child = fork();

  if(child == 0){
	printf(1, "##### Step 2 #####\n");
	setnice(parent, 2);
	testgetnice(parent, 2);
	printf(1, "##### Step 4 #####\n");
  }
  else{
	printf(1, "##### Step 1 #####\n");
	setnice(child, 5);
	testgetnice(child, 5);
	printf(1, "##### Step 3 #####\n");
  }

  printf(1, "PID %d exited\n", getpid());

  exit();
}
