#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int coe;
	int exp;
	struct node * next;
}tNode,*pNode;

pNode CreatNode(int coe,int exp)
{
	pNode temp = malloc(sizeof(tNode));
	temp->coe = coe;
	temp->exp = exp;
	temp->next = NULL;
	return temp;
}

int main()
{
	int tempC;
	int tempE;
	pNode start;
	pNode temp;
	char end;
	scanf("%d %d",&tempC,&tempE);
	start = CreatNode(tempC,tempE);
	temp = start;
	end = getchar();
	
	while(end!='\n'){
		scanf("%d %d",&tempC,&tempE);
		temp->next = CreatNode(tempC,tempE);
		temp = temp->next;
		end = getchar();
//		printf("%c",end);
	}
	
	temp = start;
	while(temp != NULL)
	{
		temp->coe = temp->coe*temp->exp;
		temp->exp -= 1;
		if(temp->next!=NULL)
		{
			if(temp->next->exp == 0)
			{
				temp->next = NULL;
				break;
			}
			temp = temp->next;
		}
		else
		{
			if(temp->exp == -1)
			{
				temp->coe = 0;
				temp->exp = 0;
			}
			break;
		}
		
	}
//	printf("%d %d\n",start->coe,start->exp);
//	printf("%d %d\n",start->next->coe,start->next->exp);
	
	temp = start;
	while(temp != NULL)
	{
		printf("%d %d",temp->coe,temp->exp);
		if(temp->next!=NULL)
		{
			printf(" ");
			temp= temp->next;
		}
		else
		{
			break;
		}
	}
	return 0;
}
