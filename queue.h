#ifndef _QUEUE_
#define _QUEUE_

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

tQueue* CreateQueue();
/*
{
	tQueue* temp = malloc(sizeof(tQueue));
	temp->head = NULL;
	temp->tail = NULL;
	temp->sumOfNode = 0;
	return temp;
}
*/

int PushNodeToQueue(tQueue *queue, tQueueNode *tN);

tQueueNode* PopNodeQueue(tQueue *queue);
#endif
