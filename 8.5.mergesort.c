#include <stdio.h> 

void merge(int *a , int low , int mid , int high){
    int i = low ; 
    int j = mid + 1 ; 
    int k = low ; 
    int b[100] ; 

    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k] = a[i] ; 
            i++;
            k++ ; 
        }


        else if(a[j]<=a[i]){
            b[k] = a[j] ; 
            j++ ; 
            k++ ; 
        }
    }


    while(i<=mid){
        b[k] = a[i] ; 
        i++ ; 
        k++ ; 
    }


    while(j<=high){
        b[k] = a[j] ; 
        k++ ; 
        j++ ;      
    }

    // copying a from b 

    for(int i = low ; i<=high ; i++){
        a[i] = b[i] ; 
    }
}


void mergeSort(int*a , int low , int high){
    if(low<high){
        int mid = (low+high)/2 ; 
        mergeSort(a,low , mid) ; 
        mergeSort(a , mid+1 , high) ; 
        merge(a , low , mid, high) ; 
    }
}


int main()
{

   int a[] = {9,14,4,8,7,5,6} ; 
   int n = sizeof(a)/sizeof(int) ; 

   mergeSort(a , 0 , n-1) ; 


   for(int i = 0 ; i<n ; i++){
    printf("%d " , a[i]) ; 
   }

    return 0 ; 
}