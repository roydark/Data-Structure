#include <stdio.h>
#include "stack.h"

#if 0
void stack_init(PStr_stack *stack);
int  stack_push(int data);
int  stack_pop();
void stack_destroy(PStr_stack stack);
#endif

int char_match();

PStr_stack stack_1 = NULL;

void main()
{
	char *flag_1 = "[([][])]";
	char *flag_2 = "[([][])])";

	stack_init(&stack_1);
	if(char_match(flag_1))
		printf("%s match success!\n", flag_1);
	else
		printf("%s match failure!\n", flag_1);
	if(char_match(flag_2))
		printf("%s match success!\n", flag_2);
	else
		printf("%s match failure!\n", flag_2);
	stack_destroy(stack_1);
}

int char_match(char *flag)
{
	int err = 0;
	int data = 0;
	
	while(flag[0] && err != 1)
		{
			switch(flag[0])
				{
					case '(':stack_push(stack_1, flag[0]);
					break;
					case ')':if(!stack_pop(stack_1, &data))
						{
							err = 1;
						}
					break;
					case '[':stack_push(stack_1, flag[0]);
					break;
					case ']':if(!stack_pop(stack_1, &data))
						{
							err = 1;
						}
					break;
					default:
					break;
				}
			flag++;
		}
	if(err ==1)
		return 0;
	return 1;
}
