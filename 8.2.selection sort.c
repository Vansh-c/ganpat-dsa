#include <stdio.h> 
#include <stdlib.h> 


int selectionsort(int *a  , int size){
    int indexmin ; 

    for(int i = 0 ; i<size ; i++){
        indexmin = i ; 
        for(int j= i+1 ; j<size ; j++){
            if(a[j]<a[indexmin]){
                indexmin = j ; 
            }
        }

        int t = a[i] ; 
        a[i] = a[indexmin] ; 
        a[indexmin] = t;  
    }
}

int main()
{

    int a[] = {3,4,1,7,9,0} ; 

    int size= sizeof(a)/sizeof(int) ;

    selectionsort(a , size);

    for(int i = 0 ; i<size ; i++){
           printf("%d " , a[i]) ; 
    }



    return 0 ;
}