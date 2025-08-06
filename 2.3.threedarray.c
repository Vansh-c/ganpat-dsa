#include <stdio.h>
#define m 2
#define n 2
#define l 2 


int main()
{
    int mat[m][n][l] ; 

    printf("enter the elements  of the array \n") ; 

    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            for(int k = 0 ; k<l ; k++){
                printf("maat[%d][%d][%d]",i,j,k) ; 
                scanf("%d" , &mat[i][j][k]) ; 

            }
        }
    }

    printf("\nthe matrix is : \n\n") ; 

        for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            for(int k = 0 ; k<l ; k++){
               
                printf("%d " , mat[i][j][k]) ; 

            }
            printf("\n");
        }
        printf("\n") ; 
    }


    return 0 ;
}