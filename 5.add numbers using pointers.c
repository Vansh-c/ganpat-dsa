#include <stdio.h> 
void addtwonumbers(int num , int num2 , int *add_result){

      *add_result = num + num2 ; 
}



int main()
{
     int num1 =0 , num2 = 0  , result = 0 ; 
     printf("enter number 1 \n") ; 
     scanf("%d" , &num1) ; 
     printf("enter number 2 \n") ; 
     scanf("%d" , &num2) ; 


     addtwonumbers(num1 , num2 , &result);

     printf("num1 + num2 = %d" , result) ;
    return 0 ;
}
 

