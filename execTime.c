#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);

	printf("Press ENTER to stop...\n");
	getc(stdin);

	clock_gettime(CLOCK_MONOTONIC_RAW, &end);

	if(end.tv_nsec < start.tv_nsec){
		end.tv_nsec += 1000000000;
		end.tv_sec--;
	}

	printf("Delta time: [%ld.%09ld]s\n", (long)(end.tv_sec - start.tv_sec), (end.tv_nsec - start.tv_nsec));

	return(0);
}
