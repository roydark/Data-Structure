#ifndef _STACK_H_
#define _STACK_H_

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

void stack_init(PStr_stack *stack);
int  stack_push(PStr_stack stack, int data);
int  stack_pop(PStr_stack stack, int *data);
int  stack_exit(PStr_stack stack);
void stack_top_place(PStr_stack stack);
int  stack_empty(PStr_stack stack);
int  stack_full(PStr_stack stack);
void stack_clear(PStr_stack stack);
void stack_destroy(PStr_stack stack);


#endif
