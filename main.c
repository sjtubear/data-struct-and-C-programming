#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
		else
		{
			nodeArray[i].left = &nodeArray[atoi(leftIndex)];
			sum-=atoi(leftIndex);
		}
		
		if(strcmp(rightIndex,"-")==0)
		{
			nodeArray[i].right = NULL;
		}
		else
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
