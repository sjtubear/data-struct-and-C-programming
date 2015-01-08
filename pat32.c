#include <stdio.h>
#include <malloc.h>

typedef struct queueNode{
	struct queueNode *next;
	struct queueNode *last;
}tQueueNode;

typedef struct queue{
	tQueueNode *head;
	tQueueNode *tail;
	int sumOfNode;
}tQueue;

tQueue* CreateQueue()
{
	tQueue* temp = malloc(sizeof(tQueue));
	temp->head = NULL;
	temp->tail = NULL;
	temp->sumOfNode = 0;
	return temp;
}

int PushNodeToQueue(tQueue *queue, tQueueNode *tN)
{
	queue->sumOfNode++;
	//If queue is empty, add and return
	if(queue->head == NULL)
	{
		queue->head = tN;
		queue->tail = tN;
		return 0;
	}
	
	//other condition;
	tN->next = queue->tail;
	queue->tail->last = tN;
	queue->tail = tN;
	return 0;
}

tQueueNode* PopNodeQueue(tQueue *queue)
{
	tQueueNode *temp = queue->head;
	if(temp == NULL)
	{
		return NULL;
	}
	
	if(queue->head == queue->tail)
	{
		queue->head = NULL;
		queue->tail = NULL;
		queue->sumOfNode--;
		return temp;
	}
	
	queue->head->last->next = NULL;
	queue->head = queue->head->last;
	queue->sumOfNode--;
	return temp;
}

typedef struct TreeNode
{
	int index;
	struct TreeNode* left;
	struct TreeNode* right; 
}tTreeNode;


typedef struct TreeQueueNode
{
	tQueueNode *next;
	tQueueNode *last;
	tTreeNode *node;
//	int index;
//	struct TreeNode* left;
//	struct TreeNode* right; 
}tTreeQueueNode;

int main(int argc, char *argv[]) {
	
	int num;
	int sum;
	char *leftIndex = malloc(sizeof(char)*3);
	char *rightIndex = malloc(sizeof(char)*3);
	tTreeNode *root = NULL;
	tQueue *treeQueue = CreateQueue();
	tTreeQueueNode *tempNode = malloc(sizeof(tTreeQueueNode));
	
	scanf("%d",&num);
	tTreeNode nodeArray[num];
	int i = 0;
	for(;i<num;i++)
	{
		sum+=i;
	}
	i=0;
	for(;i<num;i++)
	{
		//read left and right node
		scanf("%s %s",leftIndex,rightIndex);
//		printf("%s %s",leftIndex,rightIndex);
		nodeArray[i].index = i;
		if(strcmp(leftIndex,"-")==0)
		{
			nodeArray[i].left = NULL;
		}
		else if(atoi(leftIndex)<num)
		{
			nodeArray[i].left = &nodeArray[atoi(leftIndex)];
			sum-=atoi(leftIndex);
		}
		
		if(strcmp(rightIndex,"-")==0)
		{
			nodeArray[i].right = NULL;
		}
		else if(atoi(rightIndex)<num)
		{
			nodeArray[i].right = &nodeArray[atoi(rightIndex)];
			sum-=atoi(rightIndex);
		}
	}
//	nodeArray[1].left = &nodeArray[0];
//Begin pop and push
	root = &nodeArray[sum];
	tempNode->node = root;
	PushNodeToQueue(treeQueue,(tQueueNode *)tempNode);
	while(treeQueue->sumOfNode != 0)
	{
//		printf("%d ",tempNode->node->index);
		tempNode = (tTreeQueueNode*)PopNodeQueue(treeQueue);
		if(tempNode->node->left != NULL)
		{
			tTreeQueueNode *leftT = malloc(sizeof(tTreeQueueNode));
			leftT->node = tempNode->node->left;
//			printf("%d ",leftT->node->index);
			PushNodeToQueue(treeQueue,(tQueueNode *)leftT);
		}
		if(tempNode->node->right != NULL)
		{
			tTreeQueueNode *rightT = malloc(sizeof(tTreeQueueNode));
			rightT->node = tempNode->node->right;
//			printf("%d ",rightT->node->index);
			PushNodeToQueue(treeQueue,(tQueueNode *)rightT);
			
		}
		if(tempNode->node->left==NULL && tempNode->node->right ==NULL)
		{
			printf("%d",tempNode->node->index);
			if(treeQueue->sumOfNode !=0)
			{
				printf(" ");
			}
		}
	}
	return 0;
}
