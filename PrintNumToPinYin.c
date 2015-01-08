#include <stdio.h>
#include <stdlib.h>

void PrintNumToPinYin(int num)
{
	switch(num){
		case (0):{
			printf("ling");
			break;
		}
		case (1):{
			printf("yi");
			break;
		}
		case (2):{
			printf("er");
			break;
		}
		case (3):{
			printf("san");
			break;
		}
		case (4):{
			printf("si");
			break;
		}
		case (5):{
			printf("wu");
			break;
		}
		case (6):{
			printf("liu");
			break;
		}
		case (7):{
			printf("qi");
			break;
		}
		case (8):{
			printf("ba");
			break;
		}
		case (9):{
			printf("jiu");
			break;
		}
		default:
			printf("nono!");
	}
}

int main()
{
	int input;
	int everyBit;
	int BitValue = 100000;
	
	scanf("%d",&input);
	if(input < 0)
	{
		printf("fu ");
		input = 0 - input;
	}
	while(BitValue > 0 && (input/BitValue)<1 )
	{
		BitValue = BitValue/10;
	}
	
	if(BitValue == 0)
	{
		printf("ling");
	}

	
	
	while(BitValue > 0)
	{
		everyBit = input / BitValue;
		input = input%BitValue;
		BitValue = BitValue/10;
		PrintNumToPinYin(everyBit);
		if(BitValue != 0)
		{
			printf(" ");
		}
	}
	return 0;
}
