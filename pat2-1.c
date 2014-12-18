#include <stdio.h>
#include <stdlib.h>

typedef struct DataNode {
	int address;
	int pos;
	int next;
	struct DataNode *nextNode;
}tDataNode;

//
//typedef struct{
//	tDataNode *node;
//	tDataNode *next;
//}tDataStruct;

typedef struct{
	tDataNode *firstNode;
	tDataNode *rearNode;
}tDataList;

//Creat listNode
tDataList *CreateList()
{
	tDataList *temp = malloc(sizeof(tDataList));
	temp->firstNode = NULL; 
	temp->rearNode = NULL;
//	temp->nextNode = NULL;
	return temp;
}

//Add node to list, if list is empty, assign first and rear pointer, or add node to the end of the list
int AddNode(tDataList *dataList, int addressT, int posT,int nextT)
{
	tDataNode *temp = malloc(sizeof(tDataNode));
//	tDataStruct *tempS = malloc(sizeof(tDataStruct));
	
	temp->address = addressT;
	temp->next = nextT;
	temp->pos = posT;
	temp->nextNode = NULL;
	
	if(dataList->rearNode == NULL)
	{
		dataList->firstNode = temp;
		dataList->rearNode = temp;
	}
	else
	{
		dataList->rearNode->nextNode = temp;
		dataList->rearNode = temp;
	}
	return 1;
}

//Find the node with pos = posT, or return NULL
tDataNode *FindNode(int posT, tDataList *listT)
{
	tDataNode *temp = listT->firstNode;
	while(temp != NULL)
	{
		if(temp->pos == posT)
		{
			return temp;
		}
		if(temp->nextNode == NULL)
			return temp;
		temp = temp->nextNode;
	}
}

int main()
{
	tDataList *mainList = CreateList();
	int firstAdd;
	int reversePos;
	int listLength;
	int tempAdd;
	int tempPos;
	int tempNext;
	tDataNode *reverseHead;
	tDataNode *reverseTail;
	tDataNode *tempNode;
	int i=0;
	
	scanf("%d %d %d",&firstAdd,&listLength,&reversePos);
//	printf("Data is : \n");
//	printf("%05d %d %d\n",firstAdd,listLength,reversePos);
	for(;i<listLength;i++)
	{
		scanf("%d %d %d",&tempAdd,&tempPos,&tempNext);
		AddNode(mainList,tempAdd,tempPos,tempNext);
	}
//	tempNode = mainList->firstNode;
//	for(i=0;i<listLength;i++)
//	{
//		printf("%05d %d %05d\n",tempNode->address,tempNode->pos,tempNode->next);
//		tempNode = tempNode->nextNode;
//		AddNode(mainList,tempAdd,tempPos,tempNext);
//	}
	
	reverseTail = FindNode(1,mainList);
	reverseHead = FindNode(reversePos,mainList);
	
	reverseTail->next = reverseHead->next;
	for(i=reversePos;i>1;i--)
	{
		reverseTail = FindNode(i-1,mainList);
		reverseHead->next = reverseTail->address;
		if(reverseHead->next != -1)
		{
			printf("%05d %d %05d\n",reverseHead->address,reverseHead->pos,reverseHead->next);
		}
		else
		{
			printf("%05d %d -1\n",reverseHead->address,reverseHead->pos);
		}
		reverseHead = reverseTail;
		if(i==2)
		{
			if(reverseHead->next != -1)
			{
				printf("%05d %d %05d\n",reverseHead->address,reverseHead->pos,reverseHead->next);
			}
			else
			{
				printf("%05d %d -1\n",reverseHead->address,reverseHead->pos);
			}
			
		}
	}
	
	for(i=reversePos+1;i<=listLength;i++)
	{
		tempNode = FindNode(i,mainList);
		if(tempNode->next != -1)
			{
		
				printf("%05d %d %05d\n",tempNode->address,tempNode->pos,tempNode->next);
			}
			else
			{
				printf("%05d %d -1\n",tempNode->address,tempNode->pos);
			}
	}
	
	return 0;
}

