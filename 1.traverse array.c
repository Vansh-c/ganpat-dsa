#include <stdio.h> 
#include <stdlib.h>

int main(){
    int  size;
    printf("enter value of n \n")  ; 
    scanf("%d", &size) ;  
    int *arr = (int *)malloc(sizeof(int)*size) ; 

    printf("enter the elemetns of array \n") ; 

    for(int i=0 ; i<size ; i++){
        printf("enter element %d :", i ) ; 
        scanf("%d" , &arr[i]) ; 
    }

    printf("\n\n") ; 

    for(int i=0 ; i<size ; i++){
        printf("%d " , arr[i]) ; 
    }

    return 0 ;
}