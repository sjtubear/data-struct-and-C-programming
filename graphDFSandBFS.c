#include <stdio.h>
#include <stdlib.h>
typedef struct newVertex{
	int node;
	struct newVertex * next;
}tNew;


typedef struct queueNode{
	int node;
	struct queueNode * next;
}tQueueNode;

typedef struct vertexQueue{
	tQueueNode *head;
	tQueueNode *tail;
}tQueue;

tQueue* BFSQueue;
void Enqueue(tQueueNode *node, tQueue* Queue)
{
	if(Queue->head == NULL)
	{
		Queue->head = node;
		Queue->tail = node;
		return;
	}
	
	Queue->tail->next = node;
	Queue->tail = node;
	return;
}

tQueueNode* Dequeue(tQueue * Queue)
{
	if(Queue->head == NULL)
	{
		return NULL;
	}
	else 
	{
		tQueueNode* temp = Queue->head;
		if(Queue->head == Queue->tail)
		{
			Queue->head = NULL;
			Queue->tail = NULL;
		}
		else
		{
			Queue->head = Queue->head->next;
		}
		return temp;
	}
}

int IsEmpty(tQueue *Queue)
{
	if(Queue->head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void DFS(tNew *head,tNew list[], int visited[])
{
//	head->head->visited = 1;
	visited[head->node] = 1;
	printf("%d ",head->node);
	while(head->next != NULL)
	{
		head = head->next;
		if(visited[head->node] == 0)
		{
			DFS(&list[head->node],list,visited);
		}
	}
}



void BFS(tNew *head, tNew list[] ,int visited[])
{
	printf("%d ",head->node);
//	head->head->visited = 1;

	visited[head->node] = 1;
	tQueueNode *temp = malloc(sizeof(tQueueNode));
	temp->node = head->node;
	temp->next = NULL;
	Enqueue(temp,BFSQueue);
	while(IsEmpty(BFSQueue)==0)
	{
		tQueueNode *Pop = Dequeue(BFSQueue);
		tNew* thisVertex = &list[Pop->node];
		while(thisVertex != NULL)
		{
			if(visited[thisVertex->node] != 1)
			{
				visited[thisVertex->node] = 1;
				printf("%d ",thisVertex->node);
				temp = malloc(sizeof(tQueueNode));
				temp->node = thisVertex->node;
				temp->next = NULL;
				Enqueue(temp,BFSQueue);
			}
			thisVertex = thisVertex->next;
		}
	}
}

int main()
{
	//Define the count of vertexs and edges
	int vertexNum;
	int edgeNum;
	//the two vertexs for an edge
	int edgeLeft;
	int edgeRight;
	
	scanf("%d %d",&vertexNum, &edgeNum);
	
	//
	tNew VertexList[vertexNum];
	int visited[vertexNum];
	
	int i ;
	//initialize all the vertexList node.
	for(i = 0; i < vertexNum ; i++)
	{
		VertexList[i].node = i;
		VertexList[i].next = NULL;
		visited[i]=0;
	}
	
	
	//Add all edge to the edge list;
	for(i = 0; i<edgeNum ;i++) // Initialized all the edge
	{
		scanf("%d %d",&edgeLeft,&edgeRight);
		//Fool proof, If connect to itself, continue to next edge
		if(edgeLeft == edgeRight)
		{
			continue;
		}
		//Find out the last node for this Link;
		tNew *left = &VertexList[edgeLeft];
		tNew *right = &VertexList[edgeRight];
		//without redandent check;
		while(left->next != NULL)
		{
			if(left->node == edgeRight)
			{
				left = NULL;
				break;
			}
			if((left->next->node) > edgeRight)
			{
				break;
			}
			left = left->next;
		}
		
		while(right->next != NULL)
		{
			if(right->node == edgeLeft)
			{
				right = NULL;
				break;
			}
			if((right->next->node) > edgeLeft)
			{
				break;
			}
			right = right->next;
		}
		// If redaundent , do not add to list again ,break;
		if(right == NULL || left == NULL)
		{
			continue;
		}
		// If new to both vertex, add to the last position;
		tNew *tempNext;
		//Deal with right;
		tNew * tempLeft = malloc(sizeof(tNew));
//		tempLeft->head = VertexList[edgeLeft].head;
		tempLeft->node = edgeLeft;
		tempLeft->next = NULL;
		
		if(right->next == NULL)
		{
			right->next = tempLeft;
		}
		else
		{
			tempNext = right->next;
			right->next = tempLeft;
			tempLeft->next = tempNext;
		}
	

//		Add right node to left;
		tNew * tempRight = malloc(sizeof(tNew));
//		tempRight->head = vertexList[edgeRight].head;
		tempRight->node = edgeRight;
		tempRight->next = NULL;
		if(left->next == NULL)
		{
			left->next = tempRight;
		}
		else
		{
			tempNext = left->next;
			left->next = tempRight;
			tempRight->next = tempNext;
		}
	}
	
	
	for(i=0;i<vertexNum;i++)
	{
		if(visited[i]==0)
		{
			printf("{ ");
			DFS(&VertexList[i],VertexList,visited);
			printf("}\n");
		}
	}
	
	for(i=0;i<vertexNum;i++)
	{
		visited[i]=0;
	}

	BFSQueue = malloc(sizeof(tQueue));
	BFSQueue->head =NULL;
	BFSQueue->tail = NULL;
	
	for(i = 0; i < vertexNum; i++)
	{
		if(visited[i] == 0){
			printf("{ ");
			BFS(&VertexList[i],VertexList,visited);
		    printf("}\n");
		}

	}
	
	
}
