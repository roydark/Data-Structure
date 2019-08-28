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


void stack_init();
int  stack_push(int data);
int  stack_pop();

void conversion(int N, int d)
{
	do{
		stack_push(N%d);
		N = N / d;
		}while(N);
		
	while(stack_pop());
}
int main()
{
	stack_init();
	conversion(1348,8);
	


	return 0;
}