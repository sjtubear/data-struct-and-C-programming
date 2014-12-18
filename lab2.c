#include <stdio.h>

void main(){
	int UTC;
	int BJT;
	scanf("%d",&UTC);
	BJT = UTC - 800;
	if(BJT<0)
	{
		BJT += 2400;
	}
	printf("%d",BJT);
}
