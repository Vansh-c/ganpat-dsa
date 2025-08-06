#include <stdio.h> 
#define m 3
#define n  3


int main()
{
    // int  m = 3 , n = 3  ; 

    printf("enter value of m and n\n") ;  
    int matrix[m][n] ; 


    
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
                  printf("a[%d][%d] = ", i , j ) ; 
                  scanf("%d"  , &matrix[i][j]) ; 
        }
    }


    int count = 0 ; 
    printf("\nthe matrix is below printed \n") ; 

    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            printf("%d " , matrix[i][j]) ;
            if(matrix[i][j] == 0){
                count++ ; 
            } 
        }
        printf("\n") ; 
    }

    if(count>(m*n)/2){
        printf("matrix is sparse matrix\n") ; 
    }
    else{
        printf("matrix is not a sparse matrix \n") ; 
    }
    


    return 0 ;
}