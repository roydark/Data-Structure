/*
 *
 *数制转换：
 *十进制数(N)与其他进制数(d)进行转换
 *N = (N div d) * d + N mod d
 * （1348）10 = （2504）8
 *  N		N div 8		N mod 8
 *  1348	168			4
 *  168		21			0
 *  21		2			5
 *  2		0			2
 */

#include <stdio.h>
#include "stack.h"

#if 0
void stack_init(PStr_stack *stack);
int  stack_push(PStr_stack *stack, int data);
int  stack_pop(PStr_stack *stack, int data);
void stack_destroy(PStr_stack stack);
#endif 

PStr_stack stack_1 = NULL;

void conversion(int N, int d)
{
	int data = 0;
	do{
		stack_push(stack_1, N%d);
		N = N / d;
		}while(N);
		
	while(stack_pop(stack_1, &data));
}
int main()
{
	stack_init(&stack_1);
	conversion(1348,8);
	stack_destroy(stack_1);
	
	return 0;
}