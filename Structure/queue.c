#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 6
//#define QUEUE_ADD  2

typedef struct _str_queue{
	int head;
	int tail;
	//int cap;//可以设置最大容量
	int size;
	int *data;
}Str_queue, *PStr_queue;

PStr_queue queue_1 = NULL;

void queue_init();
int queue_push_tail(int data);
int queue_pop_head();
//int queue_add();
int queue_empty();
int queue_full();
int queue_destroy();

void main()
{
	int data[5] = {1, 2, 3, 4, 5, };
	int i = 0;
	
	queue_init();
	for(i=0;i<5;i++)
	{
		printf("queue push %d \n", data[i]);
		queue_push_tail(data[i]);
	}

	for(i=0;i<5;i++)
	{
		printf("queue pop %d \n", queue_pop_head());
	}
	
	queue_destroy();
	
}

void queue_init()
{
	queue_1 = (PStr_queue)calloc(sizeof(Str_queue), 1);
	if(!queue_1)
	{
		printf("queue PTR calloc failure!\n");
		exit(-1);
	}
	
	queue_1->data = (int*)calloc(sizeof(int), QUEUE_SIZE);
	if(!queue_1->data)
	{
		printf("queue PTR calloc failure!\n");
		exit(-1);
	}
	queue_1->size = QUEUE_SIZE;
	printf("queue init success!\n");
	//queue_1->cap  = QUEUE_SIZE;
}

int queue_push_tail(int data)
{
	if(!queue_full())
		{
			queue_1->data[queue_1->tail] = data;
			queue_1->tail++;
		}
	else
		{
			queue_1->data[queue_1->tail%queue_1->size] = data;
			queue_1->tail = queue_1->head;
			queue_1->head++;
		}
}
int queue_pop_head()
{
	int temp = 0;
	if(!queue_empty())
	{
		temp = queue_1->data[queue_1->head];
		queue_1->head++;
		return temp;
	}
}
int queue_empty()
{
	if(queue_1->head == queue_1->tail)
		return 1;
	return 0;
}
int queue_full()
{
	if(queue_1->head == (queue_1->tail+1)%queue_1->size)
	{
		return 1;
	}
	return 0;
}

int queue_clear()
{
	queue_1->tail = queue_1->head;
	printf("queue clear success!\n");
	return 1;
}

int queue_destroy()
{
	if(queue_1)
	{
		if(queue_1->data)
		{
			free(queue_1->data);
		}
		free(queue_1);
		printf("queue destroy success!\n");
		return 1;
	}
	return 0;
}