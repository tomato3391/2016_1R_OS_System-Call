#include <unistd.h>
#define enqueue 326
#define dequeue 327

void main(void)
{	
	printf("Enqueue 10\n"); // 10 enqueue
	syscall(enqueue, 10); 
	printf("Enqueue 20\n"); // 20 enqueue
	syscall(enqueue, 20);
	printf("Enqueue 10\n"); // 10 enqueue (duplicate)
	syscall(enqueue, 10);
	int r = syscall(dequeue); // return value of syscall(dequeue)
	while (r != 0) // dequeue until the queue is empty
	{
		printf("Dequeue %d\n", r);
		r = syscall(dequeue);
	}
	printf("Dequeue nothing\n");
	return;
}
