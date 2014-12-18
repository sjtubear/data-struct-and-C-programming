#include <stdio.h>

int main()
{
	//Get the inte and circle to module 2 to specify whether each bit is odd or not
	//If is the same odd-even with this bit, then plus the binary value of this bit.
	int originNumber;
	int moduleLeft;
	int bitCount;
	int bitValue;
	int binaryValue;
	
	//set initial value to all variable
	scanf("%d",&originNumber);
	bitCount = 1;
	bitValue = 1;
	binaryValue = 0;
	
	while(originNumber != 0)
	{
		// originNumbe % 10 to get the last dec bit.
		moduleLeft = originNumber % 10;
		if(((moduleLeft + bitCount) % 2) == 0)
		{
			binaryValue += bitValue;
		}
		
		//prepare for next circle
		bitCount++;
		bitValue = bitValue * 2;
		originNumber = originNumber / 10;
	}
	printf("%d",binaryValue);
	return 0;
}
