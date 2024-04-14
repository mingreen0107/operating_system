#include <stdio.h>
#include <pthread.h>
#include <pthread_exception.h>

void* main1(), * main2();

int total = 0;

main(int ac, char* av[])
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, main1, (void*)10000000);
	pthread_create(&thread2, NULL, main2, (void*)10000000);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("total(1~100) = %d\n", total);
}

void* main1(void* ap)
{
	int s;

	s = sum(1, 50);
	total = total + s;

	pthread_exit((void*)NULL);
}

void* main2(void* ap)
{
	int s;

	s = sum(51, 100);
	total = total + s;

	pthread_exit((void*)NULL);
}

int sum(int f, int t)
{
	int s;
	for (s = 0; f <= t; f++)
		s = s + f;
	return(s);
}

int do_something()
{
	return (1);
}