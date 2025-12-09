#include <stdio.h> 

int  binarySearch(int *a , int size , int key){
    int left , right , mid; 
    left = 0 ; 
    right = size-1 ; 

    while(left<=right){
        mid = (left+right)/2 ; 

        if(a[mid]==key){
            return mid ; 
        }

        if(a[mid]>key){
            right = mid ; 
        }

        if(a[mid]<key){
            left = mid ; 
        }
    }


    if(left>=0 && a[left]==key){
        return left ; 
    }

    else{
        return -1;  
    }
}



int main()
{
    int x[] = {-7,-5 ,3,6,12,21,43,65,89 };
    printf("%d is located at %d position " , 6 , binarySearch(x , 9 , 6));

    return 0 ;
}
