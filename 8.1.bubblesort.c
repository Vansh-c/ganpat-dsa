#include <stdio.h> 
#include <stdlib.h> 

void bubblesort(int *a , int size){
    for(int i = 0  ; i<size ; i++){
        for(int j = 0 ; j<size-i-1 ; j++){
            if(a[i]>a[j] && i!=j){
                 if(a[j]<a[j+1]){
                    int t = a[j] ; 
                    a[j] = a[j+1] ; 
                    a[j+1] = t ; 
                 } 
            }
        }
    }
}

int main()
{

    int a[] ={3,4,1,2,6} ; 

    bubblesort(a , sizeof(a)/sizeof(int)) ; 

    for(int i = 0 ; i<sizeof(a)/sizeof(int) ; i++){
        printf("%d " , a[i]) ; 
    }

    return 0  ; 
} 