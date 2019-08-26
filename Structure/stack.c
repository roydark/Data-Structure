#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define STACK_ADD  10

typedef struct _str_stack_data{
	int data;//char *data;
	struct _str_stack *next;
}Str_stack_data, *PStr_stack_data;

typedef struct _str_stack{
	PStr_stack_data base;
	PStr_stack_data top;
	int total_size;
}Str_stack, *PStr_stack;

PStr_stack stack_1 = NULL;

void stack_init();
void stack_push();
void stack_pop();
int  stack_empty();
int  stack_full();
void stack_clear();
void stack_destory();

int main()
{
	stack_init();
	printf("execute success!\n");
	system("pause");
	return 0;
}

void stack_init()
{
	stack_1 = (PStr_stack)calloc(sizeof(Str_stack), 1);
	if(!stack_1)
	{
		printf("stack_init failure!\n");
		exit(1);
	}
	stack_1->base = (PStr_stack_data)calloc(sizeof(Str_stack_data), STACK_SIZE);
	stack_1->top = stack_1->base;
	if(!stack_1->base)
	{
		printf("stack_init failure!\n");
		exit(1);
	}
	stack_1->total_size = STACK_SIZE;

	printf("stack_init OK!\n");
}

int stack_empty()
{
	if(stack_1->base == stack_1->top && stack_1->base != NULL)
	{
		return 1;
	}
	return 0;
}

int stack_full()
{
	if(stack_1->top - stack_1->base == stack_1->total_size 
		|| stack_1->base - stack_1->top == stack_1->total_size)
		{
			return 1;
		}
	return 0;
}
void stack_clear()
{
	
}