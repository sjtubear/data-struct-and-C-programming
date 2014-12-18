#include <stdio.h>

int main()
{
	int A;
	scanf("%d",&A);
	int Di1,Di2,Di3;
	int reverse;
	Di1=A%10;
	Di2=(A/10)%10;
	Di3=(A/100)%10;
	reverse=Di1*100+Di2*10+Di3;
	printf("%d",reverse); 
}


