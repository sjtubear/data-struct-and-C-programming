#include <stdio.h>

int main(){
	int oddCount;
	int evenCount;
	int number;
	
	oddCount = 0;
	evenCount = 0;
	
	//get the number from buffer one by one
	scanf("%d",&number);  
	while(number != -1)
	{
		if((number % 2) == 0)
		{
			evenCount++;
		}
		else if((number % 2) == 1)
		{
			oddCount++;
		}
		scanf("%d",&number);
	}
	printf("%d %d",oddCount,evenCount);
	return 0;
}
