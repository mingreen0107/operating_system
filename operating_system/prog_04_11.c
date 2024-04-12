#include <stdio.h>
#include <stdlib.h>

void main(int ac, char* av[])
{
	if (fork() == 0) {
		execl("./prog_04_10", NULL);
		exit(0);
	}
	else {
		wait(NULL);

		printf("Finishing parent...\n");
		exit(0);
	}
}