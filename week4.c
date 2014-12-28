#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

#define true 1
#define false 0

int IsPrime(int num);

int main()
{
	//Lower and Upper bounde
	int lower;
	int higher;
	//Result to output
	int result;
	//Count the prime number 
	int count;
	//The number 
	int number;
	
	
	//initialize 
	count = 0;
	number = 1;
	
	//Read Lower and upper bound
	scanf("%d %d",&lower,&higher);
	
	//Circle to add the result;
	while(count < higher)
	{
		if(IsPrime(number) != 0)
		{
//			printf("%d\n",number);
			count ++;
			if(count >= lower)
			{
				result += number;
			}
		}
		number ++;
	}
	printf("%d\n",result);
	return 0;
}


int IsPrime(int num)
{
	if(num == 1)
	{
		return false;
	}
	if(num == 2)
	{
		return true;
	}
	int i = 2;
//	int sqrtR = sqrt(num);
	for(;i < num ; i++)
	{
		if(num%i==0)
			return false;
	}
	return true;
}
