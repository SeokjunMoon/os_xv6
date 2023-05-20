// hw2_2.c
// Test case #2 for Round Robin Scheduling

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
		for (int i = 0; i < 10; i++) {
			printf(1, "##### Step %d #####\n", (i * 3) + 2);
			yield();
		}
  }
  else {
		child2 = fork();

		if (child2 == 0) {
			for (int j = 0; j < 10; j++) {
				printf(1, "##### Step %d #####\n", (j * 3) + 3);
				yield();
			}
		}
		else {
			for (int k = 0; k < 10; k++) {
				printf(1, "##### Step %d #####\n", (k * 3) + 1);
				yield();
			}
		}
  }

  printf(1, "PID %d exited\n", getpid());

  exit();
}
