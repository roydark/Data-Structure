#include <stdio.h>
#include <stdlib.h>

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

PStr_stack stack_1 = NULL;

void stack_init();
int  stack_push(int data);
int  stack_pop(int *data);
int  stack_exit(PStr_stack_data stack);
int  stack_empty();
int  stack_full();
void stack_clear();
void stack_destory(PStr_stack stack);

int main()
{
	int data[5] = {1, 2, 3, 4, 5, };
	int i = 0;
	int temp = 0;
	stack_init();
	
	for(i=0;i<5;i++)
	{
		stack_push(data[i]);
	}
	for(i=0;i<5;i++)
	{
		stack_pop(&temp);
		printf("stack pop temp:%d!\n", temp);
	}

	stack_destory(stack_1);
	
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

int stack_exit(PStr_stack_data stack)
{
	if(!stack_1->base)
	{
		return 1;
	}
	
	return 0;
}

int stack_empty()
{
	if(stack_1->base == stack_1->top && stack_exit(stack_1->base))
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
	stack_1->top = stack_1->base;
}

int stack_push(int data)
{
	PStr_stack_data temp = NULL;
	int offset = 0;
	
	if(!stack_full())
	{
		stack_1->top->data = data;
		//stack_1->top->next->pre = stack_1->top;
		//stack_1->top->next = stack_1->top;
		stack_1->top++;
		printf("push %d success!\n", data);
		return 1;
	}
	else
		{
			offset = stack_1->top - stack_1->base;
			temp = stack_1->base;
			
			stack_1->base = (PStr_stack_data)realloc(stack_1->base, (stack_1->total_size + STACK_ADD)*sizeof(Str_stack_data));
			if(!stack_1->base)
			{
				stack_1->base = temp;
				printf("space not enouph! realloc failure! \npush failure, rollback!\n");
				return 0;
			}
			stack_1->top = stack_1->base + stack_1->total_size;
			
			stack_1->total_size += STACK_ADD;
			stack_1->top->data = data;
			stack_1->top++;
			printf("space is not enouph, add success!\n");
			printf("push %d success!\n", data);
			return 1;
		}
	
	return 0;
}

int stack_pop(int *data)
{
	if(!stack_empty())
	{
		*data = (stack_1->top-1)->data;
		stack_1->top--;//是否需要销毁数据
		return 1;
	}
	return 0;
}

void stack_destory(PStr_stack stack)
{
	free(stack);
	printf("space destory!\n");
}