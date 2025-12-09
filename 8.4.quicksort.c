#include <stdio.h> 

int partition(int *a , int low , int high){
    int pivot = a[low] ; 
    int i = low+1; 
    int j = high ; 

   do{
        while(  i<=high  && a[i]<=pivot){
        i++ ; 
    }

    while(j>low && a[j]>pivot){
        j-- ; 
    }

    // when i<j than swap 

    if(i<j){
        int t =  a[i] ; 
        a[i] = a[j] ; 
        a[j] = t ; 
    }
   }while(i<j) ; 

   //swap a[low] and a[j] 

   int tmp = a[low] ;  
   a[low] = a[j] ; 
   a[j] = tmp ; 

   return j ;
}

void quickSort(int *a , int low , int high){
     if(low < high){  
         int partitionIndex ; // index of pivot after partition . 
         partitionIndex = partition(a , low , high) ; 
         quickSort(a , low,  partitionIndex-1) ; // solving left subarray of partition 
         quickSort(a , partitionIndex+1 , high) ; // solve right subarray of partition . 
     }
}

int main()
{

    int a[] = {2,1,3,9,4,4,8,7,5,6} ; 
    int n = sizeof(a)/sizeof(int) ; 

    quickSort(a, 0 , n-1) ; 

    for(int i = 0 ; i<n ; i++){
        printf("%d " , a[i]) ; 
    }

    
    return 0 ; 
}
