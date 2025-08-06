#include <stdio.h> 

int main()
{
    int n = 6 ; 
    int first = 0 ;
    int second = 1 ; 
    int  total = 0  ;

    printf("%d %d" , first , second) ; 

    for(int i = 0  ; i<n ; i++){
        total = first + second ; 
        first = second ; 
        second = total ; 

        printf(" %d" , total) ; 
    }


    return 0 ;
}