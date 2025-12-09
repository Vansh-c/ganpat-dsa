#include <stdio.h> 

void swap(int *a  ,int *b){
    int t = *a ; 
    *a = *b ; 
    *b = t ; 
}


/* max-heapify at index i for heap size `n`
   Assumes the subtrees rooted at left and right are already heaps.
   This implementation uses 0-based indexing:
     left  = 2*i + 1
     right = 2*i + 2
*/

void maxHeapify(int *a , int n , int i){
    int largest = i ; 
    int left= 2*i+1 ; 
    int right = 2*i + 2 ; 

    if(left<n && a[left]>a[largest]){
        largest = left ;
    }

    if(right<n && a[right]>a[largest]){
        largest = right  ;
    }

    if(largest!=i){
        swap(&a[i] , &a[largest]) ; 
        maxHeapify(a , n , largest) ; 
    }
}


void buildMaxHeap(int *a  , int n){
    for(int i = (n/2) ; i>=0 ; i--){
        maxHeapify(a , n , i) ; 
    }
}


void heapSort(int *a , int n){
    buildMaxHeap(a , n) ; 

    // one my one extract max value and reduce heap size . 

    for(int i = n-1 ; i>0 ; i--){
        // move current max to  the end. 
          swap(&a[0] , &a[i]) ; 
          // heapify reduced heap . 
          maxHeapify(a , i , 0)  ; // size = i . 
    }
}


int main(){

    int arr[] = {15, 5, 20, 1, 17, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n) ; 

    for(int i = 0 ; i<n ; i++){
        printf("%d " , arr[i]) ; 
    }

    return 0 ; 
}