/*	Author: Parker Mathewson
 *	Date: 3/23/12
 *	Comment: This is a program to learn stacks and queues.
 *			We will create pop and push functions.
 *			We will also use a stack of 30 elements.
 */

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 30

int print_statement(int answer)
{
	printf("Press 1 for PUSH\n");
	printf("Press 2 for POP\n");
	printf("Press 3 for EXIT\n");
	printf("Enter a command: ");

	fflush(stdin);
	scanf("%d", &answer);
	return answer;
}

int* push(int *stack, int *top, int element)
{
	printf("Enter a number to push on the stack: ");
	fflush(stdin);
	scanf("%d", &element);

	if(top == stack+STACK_SIZE)
	{
		printf("The Stack is full.\n");
		return top;
	}
	else
	{
		*top = element;
		printf("%d was pushed onto the stack\n", element);
		return ++top;
	}
}

int *pop(int *stack, int *top)
{
	if(top == stack)
	{
		printf("The stack is empty.\n");
		return top;
	}
	else
	{
		printf("%d popped from the stack.\n", *stack);
		return --top;
	}
}

void print_stack(int *stack, int *top)
{
	int *i=top;

	printf("Stack elements: ");
	for(i=top-1; i>=stack; i--)
	{
		printf("%d ", *i);
	}
	printf("\n");
}

int main(void)
{
	int stack[30];
	int element=0, ans=0, i=0;

	int *top = &stack[0];

	while(ans != 3)
	{
		ans=print_statement(ans);

		if(ans == 2)
		{
			top = pop(stack, top);
		}
		if(ans == 1)
		{
			top = push(stack, top, element);
			printf("%d\n", stack[0]);
		}
	}

	print_stack(stack, top);

	return(0);
}
