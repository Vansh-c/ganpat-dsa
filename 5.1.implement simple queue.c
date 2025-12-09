#include <stdio.h> 
#include <stdlib.h> 

int isFull(int *a  , int front , int rear , int size){
       if(rear == size-1 && front==0 ){
        return 1 ; 
       }
       return 0 ; 
}


int isempty(int *a , int front , int rear , int size){
    if(front == -1 && rear == -1){
        return 1 ; 
    }
    return 0 ; 
}


int enqueue(int *a , int *front , int *rear , int size , int val){
    if(isFull(a , *front , *rear , size)){
        printf("stack overflow\n") ; 
    }
    else{
            if(*front==-1 && *rear==-1){
                *front  = *rear = 0 ;  
            }
            else{  
                ++(*rear) ; 
            }

            a[(*rear)] = val ; 
    }
}



int dequeue(int *a  , int *front , int *rear,  int size){
             if(isempty(a , *front , *rear , size)){
                printf("queue is empty\n") ; 
                return -1;       
             }
             else{

                int val = a[*front]  ; 
                if(*front == *rear){
                    (*front) = (*rear) =-1 ;  
                    return val ;                    
                  }
                  else{

                (*front)++ ;    
                
                return val ;
                  }
                
             }
}




void printElements(int *a , int front , int rear){
    
    for(int i = front ; i<=rear ; i++){
        printf("%d " , a[i]) ; 
    }

    printf("\n") ; 
}

int main()
{
    int size = 5 ; 
    int *a = (int *)malloc(size*sizeof(int)); 
    int front = -1 ; 
    int rear = -1 ; 

    enqueue(a , &front , &rear , size , 45) ; 
    enqueue(a , &front , &rear , size , 76) ; 
    enqueue(a , &front , &rear , size , 90) ; 
    enqueue( a , &front , &rear , size , 13) ; 
    printElements(a , front , rear) ; 

    printf("dequeue = %d\n" , dequeue(a , &front , &rear , size)) ; 
    printf("dequeue = %d\n" , dequeue(a , &front , &rear , size)) ; 


    printElements(a , front , rear) ; 


    printf("dequeue = %d\n" , dequeue(a , &front , &rear , size)) ; 

    printf("dequeue = %d\n" , dequeue(a , &front , &rear , size)) ;
    printf("%d %d \n" , front , rear) ; 
    printf("dequeue = %d\n" , dequeue(a , &front , &rear , size)) ; 
 


    return 0 ;
}