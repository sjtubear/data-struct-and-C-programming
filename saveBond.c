#include <stdio.h>
#include <stdlib.h>

static int jumped[101][101];

void InitialJumped()
{
	int i;
	int j;
	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;i++)
		{
			jumped[i][j]=0;
		}
	}
}

int IsJumped(int x,int y)
{
	if(jumped[x+50][y+50]==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void JumpOn(int x,int y)
{
	jumped[x+50][y+50]=1;
}

typedef struct Croc{
	//location of this Croc
	int x;
	int y;
}tCroc;

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

int DFSofCroc(tCroc *ori,tCroc list[],int numOfCroc,int step)
{
	int i;
	int localStep;
	
	JumpOn(ori->x,ori->y);
	
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
			if(IsJumped(list[i].x,list[i].y)==0)
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


int main()
{
	int numOfCrocs;
	int step;
	
	scanf("%d %d",&numOfCrocs,&step);
	
	tCroc crocs[numOfCrocs];
	
	//Put all the cordinates X,Y into array
	int i;
	for(i=0;i<numOfCrocs;i++)
	{
		int tempX;
		int tempY;
		scanf("%d %d",&tempX,&tempY);
		crocs[i].x = tempX;
		crocs[i].y = tempY;
	}
	
	tCroc *Zero = malloc(sizeof(tCroc));
	Zero->x = 0;
	Zero->y = 0;
	
	int result;
	result = DFSofCroc(Zero,crocs,numOfCrocs,step);
	
	if(result == 1)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	
	return 0;
}
