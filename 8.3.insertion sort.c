#include <stdio.h> 
#include <stdlib.h> 

void insertionsort(int *a , int size){
    for(int i = 1 ; i < size ; i++){
        int key = a[i] ; 
        int j = i-1;  
        while(j>=0 && a[j]>key){
            a[j+1] = a[j] ; 
            j-- ; 
        }

        a[j+1] = key ; 
    }
}



int main()
{

    int a[] = {3,4,6,2,1} ; 
    int s = sizeof(a)/sizeof(int) ; 

    insertionsort(a,  s) ; 

    for(int i = 0 ; i<s ; i++){
        printf("%d "  , a[i]) ; 
    }


    return 0 ;  
}