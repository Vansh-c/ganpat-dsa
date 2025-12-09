#include <stdio.h> 
#include <stdlib.h> 

int linearsearch(int *a , int size, int key){

    int left = 0 ; 
    int right = size - 1 ; 

    while(left<=right){
        if(key == a[left]){
            return left ; 
        }

        if(key==a[right]){
            return right ; 
        }

        left++ ; 
        right-- ; 
    }

    return -1; 
}


int main()
{

    int a[] = {1,2,3,4,5,90,23,44,56}  ; 

    printf("element 23 is at index %d" , linearsearch(a , sizeof(a)/sizeof(int) , 5)) ; 




    return 0 ;
}