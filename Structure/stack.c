#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#if 0
#define STACK_SIZE 4
#define STACK_ADD  2

typedef struct _str_stack_data{
	int data;//char *data;
	//struct _str_stack_data *pre;
	//struct _str_stack_data *next;
}Str_stack_data, *PStr_stack_data;

typedef struct _str_stack{
	PStr_stack_data base;
	PStr_stack_data top;
	int total_size;
}Str_stack, *PStr_stack;
#endif

#ifdef STACK

PStr_stack stack_1 = NULL;

int main()
{
	int data[5] = {1, 2, 3, 4, 5, };
	int i = 0;
	int temp = 0;
	stack_init(&stack_1);
	
	for(i=0;i<5;i++)
	{
		stack_push(stack_1, data[i]);
	}
	for(i=0;i<5;i++)
	{
		stack_pop(stack_1, &temp);
		printf("stack pop temp:%d!\n", temp);
	}

	stack_destroy(stack_1);
	
	printf("execute success!\n");
	system("pause");
	return 0;
}
#endif
void stack_init(PStr_stack *stack)
{
	*stack = (PStr_stack)calloc(sizeof(Str_stack), 1);
	if(!(*stack))
	{
		printf("stack_init failure!\n");
		exit(1);
	}
	(*stack)->base = (PStr_stack_data)calloc(sizeof(Str_stack_data), STACK_SIZE);
	(*stack)->top = (*stack)->base;
	if(!(*stack)->base)
	{
		printf("stack_init failure!\n");
		exit(1);
	}
	(*stack)->total_size = STACK_SIZE;
	stack_top_place((*stack));
	printf("stack_init OK!\n");
}

int stack_exit(PStr_stack stack)
{
	if(stack->base)
	{
		return 1;
	}
	
	return 0;
}

void stack_top_place(PStr_stack stack)
{
	printf("top place:%d\n", stack->top);
}

int stack_empty(PStr_stack stack)
{
	if(stack->base == stack->top && stack_exit(stack))
	{
		return 1;
	}
	return 0;
}

int stack_full(PStr_stack stack)
{
	if(stack->top - stack->base == stack->total_size 
		|| stack->base - stack->top == stack->total_size)
		{
			return 1;
		}
	return 0;
}
void stack_clear(PStr_stack stack)
{
	stack->top = stack->base;
}

int stack_push(PStr_stack stack, int data)
{
	PStr_stack_data temp = NULL;
	int offset = 0;
	
	if(!stack_full(stack))
	{
		stack->top->data = data;
		//stack_1->top->next->pre = stack_1->top;
		//stack_1->top->next = stack_1->top;
		stack->top++;
		//stack_top_place(stack);
		printf("push %d success!\n", data);
		return 1;
	}
	else
		{
			offset = stack->top - stack->base;
			temp = stack->base;
			
			stack->base = (PStr_stack_data)realloc(stack->base, (stack->total_size + STACK_ADD)*sizeof(Str_stack_data));
			if(!stack->base)
			{
				stack->base = temp;
				printf("space not enouph! realloc failure! \npush failure, rollback!\n");
				return 0;
			}
			stack->top = stack->base + stack->total_size;
			
			stack->total_size += STACK_ADD;
			stack->top->data = data;
			stack->top++;
			//stack_top_place(stack);
			printf("space is not enouph, add success!\n");
			printf("push %d success!\n", data);
			return 1;
		}
	
	return 0;
}

int stack_pop(PStr_stack stack, int *data)
{
	//int data = 0;
	if(!stack_empty(stack))
	{
		*data = (stack->top-1)->data;
		stack->top--;//是否需要销毁数据
		//stack_top_place(stack);
		printf("stack pop:%d\n", *data);
		return 1;
	}
	return 0;
}

void stack_destroy(PStr_stack stack)
{
	free(stack);
	printf("space destory!\n");
}
