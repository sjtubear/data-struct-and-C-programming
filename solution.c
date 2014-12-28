#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double multiNomiResult(double index3,double index2,double index1,double index0,double x)
{
	double result = 0;
	result += index3*pow(x,3);
	result += index2*pow(x,2);
	result += index1*x;
	result += index0;
	return result;
}

int main()
{
	//initial parameters
    double index3;
    double index2;
    double index1;
    double index0;
    
    double upperLimit;
    double downLimit;
    double middle;
    
    double upperResult;
    double downResult;
    double middleResult;
    
    //get parameter from stdin
    scanf("%lf %lf %lf %lf",&index3,&index2,&index1,&index0);
    scanf("%lf %lf",&downLimit,&upperLimit);
    
    while((upperLimit-downLimit)>0.001)
    {
    	middle = (downLimit + upperLimit)/2;
    	upperResult = multiNomiResult(index3,index2,index1,index0,upperLimit);
    	downResult = multiNomiResult(index3,index2,index1,index0,downLimit);
    	middleResult = multiNomiResult(index3,index2,index1,index0,middle);
    	
//    	printf("%lf %lf %lf\n",upperResult,middleResult,downResult);
    	
    	if(fabs(upperResult)<1e-14)
    	{
    		printf("%.2lf",upperLimit);
    		return 0;
		}
		
		if(fabs(downResult)<1e-14)
    	{
    		printf("%.2lf",downLimit);
    		return 0;
		}
    	
    	if((upperResult*downResult)<0)
    	{
    		if(fabs(middleResult) <= 1e-14)
    		{
    			printf("%.2lf",middle);
    			return 0;
			}
			
			if(middleResult*downResult<0)
			{
				upperLimit = middle;
			}
			else
			{
				downLimit = middle;
			}
		}
//		printf("%.2lf",downLimit);
		
	}
    printf("%.2lf",downLimit);
//    double xtri = multiNomiResult(index3,index2,index1,index0,2);
//    printf("%lf",xtri);
//    printf("%lf %lf %lf %lf",index3,index2,index1,index0);
	return 0;
}
