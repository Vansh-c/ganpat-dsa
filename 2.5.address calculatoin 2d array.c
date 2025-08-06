#include <stdio.h> 
#define n 3
#define  m 3


int main()
{

    int a[n][m] ; 

    printf("enter the elements of an array \n") ; 
    for(int  i = 0 ; i<n; i++){
        for(int j = 0 ; j<m ; j++){
            scanf("%d" , &a[i][j]);
        }

    }

    printf("\nanswer is below \n") ; 

    int *base = &a[0][0] ;

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            printf("adress of arr[%d][%d] = %p\n" , i,j, (void *)((char*)base + (i*m + j)*sizeof(int))) ; 
        }
    }



    return 0 ;
}