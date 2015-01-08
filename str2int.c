#include <stdio.h>
#include <string.h>

int main()
{
	
	char *st = malloc(sizeof(char)*32);
	scanf("%s",st);
	printf("%d",atoi(st));
}
