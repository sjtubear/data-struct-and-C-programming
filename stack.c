#include <stdio.h>

#define MAXSIZE 100

typedef struct{
	int Data[MAXSIZE];
	int top;
}Stack;

void push(Stack *staP, int element)
{
	if(staP->top > MAXSIZE -1)
	{
		printf("FULL\n");
		return;
	}
	else
	{
		staP->top = staP->top + 1;
		staP->Data[staP->top]=element;

	}
	return;
}

int pop(Stack *staP)
{
	if(staP->top==0)
	{
		return -1;
	}
	else
	{

		return staP->Data[staP->top];
				staP->top--;
	}
}

