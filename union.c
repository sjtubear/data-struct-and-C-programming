#include <stdio.h>

int MaximumSize;

typedef struct setNode{
//	int data;
	int parent;
}tSet;

int FindSet(tSet a[] , int x)
{
	// i is the index of x;
	int i = x - 1;
	if(x > MaximumSize)
	{
		return -1;
	}
	for(;(a[i].parent)>=0;i=a[i].parent)
	{
		if(i>=MaximumSize)
			return -1;
	}
	return i;
}

int UnionSet(tSet a[], int x, int y)
{
	int px = FindSet(a,x);
	int py = FindSet(a,y);
	if(px==-1 || py ==-1)
	{
		return -1;
	}//if any of the xy is not in the set;
	if(px!=py)
	{
		if(a[px].parent < a[py].parent)
		{
			a[px].parent = a[px].parent + a[py].parent;
			a[py].parent = px;
		}
		else
		{
			a[py].parent = a[px].parent + a[py].parent;
			a[px].parent = py;
		}
//		a[px].parent = py;
	}
	return 0;
}

int SetNum(tSet a[])
{
	int count = 0;
	int i = 0;
	for(;i<MaximumSize;i++)
	{
		if(a[i].parent < 0)
		{
			count++;
		}
	}
	return count;
}

//tSet* SetInitial()
//{
//	tSet *a = malloc(sizeof(tSet)*MaximumSize);
//	int i=0;
//	for(;i<MaximumSize;i++)
//	{
//		a[i].parent = -1;
//	}
//	return a;
//}

int main()
{

	int x;
	int y;
	char ch;
	int count;
	int i = 0;
	scanf("%d",&MaximumSize);
	tSet a[MaximumSize];
	for(;i<MaximumSize;i++)
	{
		a[i].parent = -1;
	}
	
	
	while(1)
	{
	
	    scanf("%c",&ch);
	    if(ch=='C')
	    {
	    	scanf("%d %d",&x,&y);
	    	if((FindSet(a,x)==FindSet(a,y))&&(FindSet(a,x)>=0))
	    	{
	    		printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
		else if(ch == 'I')
		{
			scanf("%d %d",&x,&y);
			UnionSet(a,x,y);
		}
		else if(ch == 'S')
		{
			break;
		}
	}
	count = SetNum(a);
	if(count > 1)
	{
		printf("There are %d components.\n",count);
	}
	else
	{
		printf("The network is connected.");
	}
}
