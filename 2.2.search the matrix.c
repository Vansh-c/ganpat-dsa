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

    printf("\nthe matrix is below printed \n") ; 

    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            printf("%d " , matrix[i][j]) ; 
        }
        printf("\n") ; 
    }

    printf("\n\n") ; 
    printf("enter value of x and y to search for the array\n") ; 
    int x = 0 ; int y = 0  ;
    scanf("%d" , &x) ; 
    scanf("%d" , &y) ; 

    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n; j++){
                if(matrix[x-1][y-1] == matrix[i][j]){
                    printf("matrix[%d][%d] = %d ",x,y , matrix[i][j]) ; 
                    return 0 ;
                }
        }
        printf("\n") ; 
    }



    return 0 ;
}