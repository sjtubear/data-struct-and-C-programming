#define NONE -1
#define DISK 100000

#include <stdio.h>
#include <stdlib.h>



static int jumped[101][101];

void InitialJumped()
{
	int i;
	int j;
	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;j++)
		{
			jumped[i][j]=NONE;
		}
	}
}

int IsJumped(int x,int y)
{
	if(jumped[x+50][y+50] != NONE)
	{
		return 1;
	}
	else
	{
		return NONE;
	}
}

void JumpOn(int x,int y,int jumpNum)
{
	jumped[x+50][y+50]= jumpNum;
}

int GetJump(int x,int y)
{
	return jumped[x+50][y+50];
}

/////////End of Visited /////////////

//////////Begin of Croc//////////////

typedef struct Croc{
	//location of this Croc
	int x;
	int y;
	int dis;
}tCroc;


void SetDis(tCroc* C)
{
	C->dis = (C->x)*(C->x) + (C->y)*(C->y);
}

int GetDis(tCroc* C)
{
	return C->dis;
}

//If bond could reach from ori to des.
int Reachable(tCroc* ori,tCroc* des,int step)
{
	int oriX;
	int oriY;
	int desX;
	int desY;
	int distanceSquare;
	int stepSquare;
	
	oriX = ori->x;
	oriY = ori->y;
	
	desX = des->x;
	desY = des->y;
	
	distanceSquare = (oriX-desX)*(oriX-desX)+(oriY-desY)*(oriY-desY);
	stepSquare = step*step;
	
	if(stepSquare >= distanceSquare)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int GetOut(tCroc *ori,int step)
{
	if(ori->x + step >= 50)
	{
		return 1;
	}
	if(ori->x - step <= -50)
	{
		return 1;
	}
	if(ori->y + step >= 50)
	{
		return 1;
	}
	if(ori->y - step <= -50)
	{
		return 1;
	}
	return 0;
}

//////////End of Croc////////////////

/////////DFS of Croc/////////////////

int DFSofCroc(tCroc *ori,tCroc list[],int numOfCroc,int step)
{
	int i;
	int localStep;
	
	JumpOn(ori->x,ori->y,1);
	
	if((ori->x == 0)&& (ori->y == 0))
	{
		localStep = step+8;
	}
	else
	{
		localStep = step;
	}
	
	
	if(GetOut(ori,localStep)==1)
	{
		return 1;
	}
	
	for(i = 0;i<numOfCroc;i++)
	{
		if(Reachable(ori,&list[i],localStep)==1)
		{
			if(IsJumped(list[i].x,list[i].y)==NONE)
			{
				int result;
				result =  DFSofCroc(&list[i],list,numOfCroc,step);
				if(result == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
//////////////////End of DFS Croc without COUNT/////////////////

/////////////////Begin of queue//////////////

typedef struct queueNode{
	tCroc * thisCroc;
	struct queueNode * nextCroc;
}QNode;

typedef struct CrocQueue{
	QNode *head;
	QNode *tail;
}tCrocQueue;

tCrocQueue* InitialQueue()
{
	tCrocQueue* temp = malloc(sizeof(tCrocQueue));
	temp->head = NULL;
	temp->tail = NULL;
	return temp;
}

void EnQueue(QNode *node,tCrocQueue *Q)
{
	if(Q->head == NULL)
	{
		Q->head = node;
		Q->tail = node;
		return ;
	}
	else
	{
		Q->tail->nextCroc = node;
		Q->tail = node;
		return;
	}
}

QNode * DeQueue(tCrocQueue *Q)
{
	if(Q->head == NULL)
	{
		return NULL;
	}
	else
	{
		QNode *temp = Q->head;
		if(Q->head == Q->tail)
		{
			Q->head = NULL;
			Q->tail = NULL;
		}
		else
		{
			Q->head = Q->head->nextCroc;
		}
		return temp;
	}
}

int IsQueueEmpty(tCrocQueue *Q)
{
	if(Q->head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
////////////////End of queue /////////////////

////////////////Begin of BFS/////////////////

int BFS(tCroc *ori, tCroc list[], int Sum, int step, tCrocQueue *Q, int father[])
{
	int count;
	int myfather;
	myfather = DISK;
	count = 0;
	JumpOn(ori->x,ori->y,count);
	QNode * thisNode = malloc(sizeof(QNode));
	thisNode->thisCroc = ori;
	EnQueue(thisNode,Q);
	while(IsQueueEmpty(Q)==0)
	{
		int i ;
		int localStep;
		QNode* temp = DeQueue(Q);
		
		count = GetJump(temp->thisCroc->x,temp->thisCroc->y);

		if((temp->thisCroc->x == 0)&&(temp->thisCroc->y==0))
		{
			localStep = step + 8;
			myfather = DISK;
		}
		else
		{
			localStep = step;
			for(i = 0; i < Sum ; i++)
			{
				if((temp->thisCroc->x == list[i].x)&&(temp->thisCroc->y== list[i].y))
			    {
			    	myfather = i;
			    	break;
				}
			}
		}
		
		
		for(i = 0; i < Sum ;i++)
		{
			if(Reachable(temp->thisCroc,&list[i],localStep)==1)
			{
				if(IsJumped(list[i].x,list[i].y)==NONE)
				{
					JumpOn(list[i].x,list[i].y,(count+1));
					father[i] = myfather;
					
					if(GetOut(&list[i],step)==1)
				    {
				    	return i;
					}
					thisNode = malloc(sizeof(QNode));
					thisNode->thisCroc = &list[i];
					EnQueue(thisNode,Q);
				}
			}
		}
	}
	
	return NONE;
}





////////////////End of BFS///////////////////
////////////////Begin Stack//////////////////
typedef struct stackNode{
	tCroc *thisNode;
	struct stackNode * next;
}tStackNode;

typedef struct CrocStack{
	tStackNode* Top;
	tStackNode* Bottom;
}tCrocStack;

tCrocStack* InitialStack()
{
	tCrocStack * temp = malloc(sizeof(tCrocStack));
	temp->Top = NULL;
	temp->Bottom = NULL;
	return temp;
}

void Push(tStackNode *node,tCrocStack * S)
{
	if(S->Top == NULL)
	{
		S->Top = node;
		S->Bottom = node;
	}
	else
	{
		node->next = S->Top;
		S->Top = node;
	}
}

tStackNode *Pop(tCrocStack *S)
{
	if(S->Top == NULL)
	{
		return NULL;
	}
	else
	{
		tStackNode * temp = S->Top;
		if(S->Top == S->Bottom)
		{
			S->Bottom = NULL;
			S->Top = NULL;
		}
		else
		{
			S->Top = S->Top->next;
		}
		return temp;
	}
}

int IsStackEmpty(tCrocStack *S)
{
	if(S->Top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/////////////////End of Stack////////////////





int main()
{
	int numOfCrocs;
	int step;
	int i;
	
	InitialJumped();
	scanf("%d %d",&numOfCrocs,&step);
	
	tCroc crocs[numOfCrocs];
	int preCro[numOfCrocs];
	
	
	//Put all the cordinates X,Y into array
	for(i=0;i<numOfCrocs;i++)
	{
		int j;
		int tempX;
		int tempY;
		scanf("%d %d",&tempX,&tempY);
		crocs[i].x = tempX;
		crocs[i].y = tempY;
		SetDis(&crocs[i]);
		
		for(j=i;j>0;j--)
		{
			if(GetDis(&crocs[j])<GetDis(&crocs[j-1]))
			{
				tCroc temp = crocs[j-1];
				crocs[j-1]=crocs[j];
				crocs[j]=temp;
			}
			else
			{
				break;
			}
		}
		preCro[i] = NONE;
	}
	
//	printf("---------------\n");
//	for(i=0;i<numOfCrocs;i++)
//	{
//		printf("%d %d %d\n",crocs[i].x,crocs[i].y,crocs[i].dis);
//	}
//	printf("---------------\n");
		
	tCroc *Zero = malloc(sizeof(tCroc));
	Zero->x = 0;
	Zero->y = 0;
	
	tCrocQueue * MyQueue = InitialQueue();
	
	int result;
	
	result = BFS(Zero,crocs,numOfCrocs,step,MyQueue,preCro);
	
	if(result == NONE)
	{
		printf("0");
		return 0;
	}
	else
	{
		int Dis = GetJump(crocs[result].x,crocs[result].y);
		printf("%d\n",Dis+1);
	}
	
	tCrocStack * MyStack = InitialStack();
	while(result != DISK)
	{
		tStackNode *temp = malloc(sizeof(tStackNode));
		temp->thisNode = &crocs[result];
		Push(temp,MyStack);
		result = preCro[result];
	}
	
	while(IsStackEmpty(MyStack)==0)
	{
		int printX;
		int printY;
		tStackNode *temp = Pop(MyStack);
		
		printX = temp->thisNode->x;
		printY = temp->thisNode->y;
		printf("%d %d\n",printX,printY);
	}
	
//	result = DFSofCroc(Zero,crocs,numOfCrocs,step);
	
//	if(result == 1)
//	{
//		printf("Yes");
//	}
//	else
//	{
//		printf("No");
//	}
	
	return 0;
}
