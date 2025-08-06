#include <stdio.h>
#include <stdlib.h> 


int main()
{

   int num ; 
   printf("enter the value of num \n") ; 
   scanf("%d" , &num) ; 

   int *ptr = &num ; 
   printf("the address of num = %d" , ptr) ; 


    return 0 ;
}