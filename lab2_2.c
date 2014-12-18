#include <stdio.h>
#include <string.h>

int main()
{
	char readi;
	char streng;
	char strs[128];
	char redi[128];
	
	scanf("%c",&readi);
	scanf("%c",&streng);
	
	switch(readi){
		case('1'):{
			strcpy(strs,"unreadable");
			break;
		}
		case('2'):{
			strcpy(strs,"barely readable, occasional words distinguishable");
			break;
		}
		case('3'):{
			strcpy(strs,"readable with considerable difficulty");
			break;
		}
		case('4'):{
			strcpy(strs,"readable with practically no difficulty");
			break;
		}
		case('5'):{
			strcpy(strs,"perfectly readable");
			break;
		}
		default:break;
	} 
		switch(streng){
		case('1'):{
			strcpy(redi,"Faint signals, barely perceptible");
			break;
		}
		case('2'):{
			strcpy(redi,"Very weak signals");
			break;
		}
		case('3'):{
			strcpy(redi,"Weak signals");
			break;
		}
		case('4'):{
			strcpy(redi,"Fair signals");
			break;
		}
		case('5'):{
			strcpy(redi,"Fairly good signals");
			break;
		}
		case('6'):{
			strcpy(redi,"Good signals");
			break;
		}
		case('7'):{
			strcpy(redi,"Moderately strong signals");
			break;
		}
		case('8'):{
			strcpy(redi,"Strong signals");
			break;
		}
		case('9'):{
			strcpy(redi,"Extremely strong signals");
			break;
		}		
		default:break;
	} 
	printf("%s, %s.",redi,strs);
	return 0;
}
