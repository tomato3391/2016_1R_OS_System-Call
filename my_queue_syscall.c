#include <linux/linkage.h>
#include <linux/kernel.h>
int queue[100] = {0, }; // QUEUE
asmlinkage void sys_osta_enqueue(int n);
asmlinkage int sys_osta_dequeue(void);

asmlinkage void sys_osta_enqueue(int n) // n = input that will be enqueued
{
	printk("New System Call Saying %d\n", n);
	printk("ENQUEUE : %d\n", n);
	int i; // iteration
	for(i = 0; i < 100; i++)
	{
		if (queue[i] == 0) // if queue[i] is empty
			break;
		if (queue[i] == n) // if queue[i] is duplicate element comparing to n
		{
			printk("Error : Duplicate element in the queue\n");
			break;
		}
		if (i == 99) // if queue is full (0 ~ 99)
		{
			printk("Error : The queue is full.\n");
			break;
		}
	}
	queue[i] = n; // insert n into queue
	printk("Queue : "); // print queue
	for (i = 0; i < 100; i++)
	{
		if (queue[i] == 0) // if queue[i] is empty
			break;
		else
			printk("%d ", queue[i]);
	}
	printk("\n========\n");
	return;
}

asmlinkage int sys_osta_dequeue(void) // returns int value that has been dequeued
{
	if (queue[0] == 0) // if queue is empty
	{
		printk("Error : The queue is empty.\n");
		return 0;
	}
	int temp = queue[0]; // temp will be returned
	int i;
	for (i = 0; i < 99; i++) // 0 ~ 98 (if queue was full, the value index will be 0 ~ 99-1)
	{
		if (queue[i + 1] == 0) // next value is none
		{
			queue[i] = 0; // current value -> 0
			break;
		}
		queue[i] = queue[i + 1]; // sorting
	}
	queue[i + 1] = 0; // for i = 98 when break;
	printk("DEQUEUE : %d\n", temp);
	printk("Queue : ");
	for (i = 0; i < 100; i++)
	{
		if (queue[i] == 0)
			break;
		else
			printk("%d ", queue[i]);
	}
	printk("\n========\n");
	return temp; // return the first value in queue
}
