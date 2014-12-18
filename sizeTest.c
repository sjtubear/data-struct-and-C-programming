#include <stdio.h>
#include <stdlib.h>


int main(){
	int size;
	int address;
	int pos;
	int next;
	int reversePos;
	int i = 0;
	int circle;
	int j = 0;
	int rest;
	int tempK;
	int tempS;
	
	scanf("%d %d %d",&address,&size,&reversePos);
	int arr[size];
	circle = size/reversePos;
	rest = size%reversePos;
	
//	printf("%d %d\n",circle,rest);
	//Got the array[address R,address R-1,.....address 1,address R+1...Last]
//	for(;j<circle;j++)
//	{
//		for(;i<reversePos;i++)
//		{
//			
//		}
//	}
//	
	
	for(;i<size;i++)
	{
		scanf("%d %d %d",&address,&pos,&next);
		tempK = (pos-1)/reversePos;
		tempS = (pos-1)%reversePos;
//		printf("%d %d \n",tempK,tempS);
		if(rest ==0 || tempK<circle)
		{
			arr[tempK*reversePos + (reversePos - tempS-1)] = address;
		}
		else
		{
			arr[pos-1]=address;
		}
//		if(pos>reversePos)
//		{
//			arr[pos-1]=address;
//		}
//		else
//		{
//			arr[reversePos-pos]=address;
//		}
	}
		
	i=0;
	
	for(;i<size;i++)
	{
		tempK = i/reversePos;
		tempS = i%reversePos;
		if(rest ==0 || tempK<circle)
		{
			if(i==(size-1))
				printf("%05d %d -1\n", arr[i],(reversePos-tempS)+tempK*reversePos);
			else
				printf("%05d %d %05d\n", arr[i],(reversePos-tempS)+tempK*reversePos,arr[i+1]);
//			arr[tempK*reversePos + (reversePos - tempS)] = address;
		}
		else
		{
			if(i==(size-1))
				printf("%05d %d -1\n", arr[i],i+1);
			else
				printf("%05d %d %05d\n", arr[i],i+1,arr[i+1]);
		}
	}
	
	
	
//	for(;i<size;i++)
//	{
//		if(i<reversePos){
//			int temp = reversePos - i;
//			if(i==(size - 1))
//			{
//				printf("%05d %d -1\n",arr[i],temp);
//			}
//			else
//			{
//				printf("%05d %d %05d\n",arr[i],temp,arr[i+1]);
//			}
//		}
//		else
//		{
//			if(i==(size - 1))
//			{
//				printf("%05d %d -1\n",arr[i],i+1);
//			}
//			else
//			{
//				printf("%05d %d %05d\n",arr[i],i+1,arr[i+1]);
//			}
//		}
//	}
	
	return 0;
}
