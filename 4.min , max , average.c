#include <stdio.h> 
#include <stdlib.h>



int main()
{
    int arr[] = {33,5,66,87,23,65} ; 

    int size = sizeof(arr) / sizeof(int) ; 

    int max = arr[0]; 
    int min = arr[0] ; 
    int sum = 0 ; 

    for(int i = 0 ; i<size ; i++){
        sum = sum + arr[i] ; 
        if(arr[i]>max){
            max = arr[i] ; 
        }

        if(arr[i]<min){
            min  = arr[i] ; 
        }
    }


    printf("max = %d , min = %d , average = %f" , max , min , (float)sum/size) ; 




    return 0 ; 
}