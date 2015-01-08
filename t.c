#include <stdio.h>

void swap( int *pa, int *pb ) 
{
    int pt;
    pt = *pa, *pa = *pb, *pb = *pa;
}
int main(void)
{    int k;
  for (k=1; k; k++) ;
  printf("%d",k); 
  //  printf ("%d\n ", k);
}
