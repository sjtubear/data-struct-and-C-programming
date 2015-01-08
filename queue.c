#include "queue.h"

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
