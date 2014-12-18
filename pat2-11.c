#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int data[100000];
	int next[100000];
	int size;
	int reverse;
	int firstAdd;
	int address;
	int circle;
	int rest;
	int count;
	
	scanf("%d %d %d",&firstAdd,&size,&reverse);
	int tempAdd;
	int i = 0;
	for(;i<size;i++)
	{
		scanf("%d",&address);
		scanf("%d %d",&data[address],&next[address]);
	}
	
	count = 1;
	tempAdd = firstAdd;
	
	while(next[tempAdd]!=-1)
	{
		count++;
		tempAdd = next[tempAdd];
	}
	
	
	circle = count / reverse;
	rest = count % reverse;
	int nextAdd;

	int thisAdd;
	int firstNode;
	int lastCircleAdd;
//	int tempD[reverse];
//	int tempN[reverse];
	
	int j=0;
	firstNode = firstAdd;
	thisAdd = firstAdd;
	nextAdd = next[thisAdd];
	
	
	for(;j<circle;j++)
	{
		for(i=0;i<reverse-1;i++)
		{
			tempAdd = next[nextAdd];
			next[nextAdd]=thisAdd;
			thisAdd = nextAdd;
			nextAdd = tempAdd;
		}
		if(j==0)
		{
			next[firstAdd] = nextAdd;
			lastCircleAdd = firstAdd;
			firstAdd = thisAdd;
			firstNode = nextAdd;
			thisAdd = firstNode;
			nextAdd = next[thisAdd];
		}
		else
		{
			next[firstNode] = nextAdd;
			next[lastCircleAdd] = thisAdd;
			lastCircleAdd = firstNode;
			firstNode = nextAdd;
			thisAdd = firstNode;
			nextAdd = next[thisAdd];
		}	
	}
	
	if(rest!=0 && circle!=0)
	{
		next[lastCircleAdd] = thisAdd;
	}
	
	tempAdd = firstAdd;
	for(i=0;i<count;i++)
	{
		printf("%05d ",tempAdd);
		printf("%d ",data[tempAdd]);
		if(next[tempAdd]!= -1)
			printf("%05d\n",next[tempAdd]);
		else
			printf("-1\n");
		tempAdd = next[tempAdd];
	}
	
	return 0;	
	
}
