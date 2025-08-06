#include <stdio.h> 

int main()
{

    int arr[5] = {-8,-7,-6} ; 

    int *base = &arr[0] ; 

    int size = sizeof(arr) / sizeof(int) ; 

    for(int i = 0 ; i<size ; i++){
        printf("calculated adress arr[%d] = %p \n" , i , (void*)((char*)base + i*sizeof(int))) ; 
    }

    return 0 ;
}

// %p is used to print address, so it expects void* to do same . 
// here explicit pointer convertion  is allowed hence , even if base  is int* , than also we can type (char*)base.