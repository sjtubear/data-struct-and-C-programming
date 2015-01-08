#include <stdio.h>
#include <stdlib.h>

typedef struct AVLnode{
	int height;
	struct AVLnode * left;
	struct AVLnode * right;
	int data;
}tAVLnode, *pAVL;

pAVL SingleLeftRotation(pAVL T);

pAVL DoubleLeftRightRotation(pAVL T);

pAVL SingleRightRotation(pAVL T);

pAVL DoubleRightLeftRotation(pAVL T);

pAVL InsertNode(int data, pAVL T);

int GetHeight(pAVL T);

pAVL InsertNode(int data, pAVL T)
{
	if(!T)
	{
		T = (pAVL)malloc(sizeof(tAVLnode));
		T->data = data;
		T->height = 0;
		T->left = NULL;
		T->right = NULL;
	}
	else if(data < T->data)
	{
		T->left = InsertNode(data,T->left);
		if(GetHeight(T->left)-GetHeight(T->right)== 2)
		{
			if(data < T->left->data)
			{
				T=SingleLeftRotation(T);
			}
			else
			{
				T=DoubleLeftRightRotation(T);
			}
		}
	}
	else if(data > T->data)
	{
		T->right = InsertNode(data,T->right);
		if(GetHeight(T->left)-GetHeight(T->right) == -2)
		{
			if(data > T->right->data)
			{
				T=SingleRightRotation(T);
			}
			else
			{
				T=DoubleRightLeftRotation(T);
			}
		}
	}
	T->height = (GetHeight(T->left)>=GetHeight(T->right))?GetHeight(T->left)+1:GetHeight(T->right)+1;
	
	return T;	
}

pAVL SingleLeftRotation(pAVL T)
{
	pAVL B = T->left;
	T->left = B->right;
	B->right = T;
	T->height = (GetHeight(T->left)>=GetHeight(T->right))?GetHeight(T->left)+1:GetHeight(T->right)+1;
	B->height = (GetHeight(B->left)>=GetHeight(B->right))?GetHeight(B->left)+1:GetHeight(B->right)+1;
	return B;
}

pAVL DoubleLeftRightRotation(pAVL T)
{
	T->left = SingleRightRotation(T->left);
	return SingleLeftRotation(T);
}

pAVL SingleRightRotation(pAVL T)
{
	pAVL B = T->right;
	T->right = B->left;
	B->left = T;
	T->height = (GetHeight(T->left)>=GetHeight(T->right))?GetHeight(T->left)+1:GetHeight(T->right)+1;
	B->height = (GetHeight(B->left)>=GetHeight(B->right))?GetHeight(B->left)+1:GetHeight(B->right)+1;
	return B;
}

pAVL DoubleRightLeftRotation(pAVL T)
{
	T->right = SingleLeftRotation(T->right);
	return SingleRightRotation(T);
}

int GetHeight(pAVL T)
{
	if(!T)
	{
		return -1;
	}
	else
	{
		return T->height;
	}
}

int main()
{
	int nodeSum;
	int data;
	int i;
	pAVL Root = NULL;
	
	scanf("%d", &nodeSum);
	
	for(i=0;i<nodeSum;i++)
	{
		scanf("%d",&data);
		Root = InsertNode(data,Root);
	}
	printf("%d",Root->data);
}
