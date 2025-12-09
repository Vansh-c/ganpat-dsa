// b) Implement Circular Queue with following operations:  
// enqueue(), dequeue(), display(), isempty() and isfull() 


#include <stdio.h> 
#include <stdlib.h>


int isFull(int *a , int front , int rear , int size){
    if(front == (rear+1)%size){
        return 1 ; 
    }
    return 0;  
}


int isEmpty(int *a  ,int front , int rear , int size){
    if(front == -1 && rear == -1){
        return 1 ; 
    }
    return 0 ;
}


void enqueue(int *a , int *front , int *rear , int size , int val){
       if(isFull(a , *front , *rear , size)){
        printf("stack overflow \n") ; 
       }
       else{
        if(*front == -1 && *rear == -1){
            *front = *rear = 0 ; 
        }

        else{
            *rear = (*rear + 1)%size ; 
        }

        a[*rear] = val ; 
       }
}


    int dequeue(int *a  , int *front , int *rear , int size ){
        int val = -1 ; 
        if(isEmpty( a, *front , *rear , size)){
            printf("stack underflow \n") ; 
            return -1  ;
        }
        else{ 

               val = a[*front] ;
            if(*front == *rear){
                    *front = *rear = -1 ; 
            }
            else {
                *front = (*front + 1)%size ; 
            }

          
            return val; 
        }
    }



void printArray(int *a , int front, int rear , int size){

   if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", a[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n"); 
}



int main()
{
    int *a = (int *)malloc(sizeof(int)*5) ; 
    int size = 5 ; 
    int front = -1 ; 
    int rear = -1 ; 
    int val ; 
    int choice ; 

   while(1){
    
    printf("enter the choice \n") ; 
    scanf("%d" , &choice) ; 

    printf("enter 1 to enqueue,  2 to dequeue, 3 to printArray \n");
          
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(a, &front, &rear, size, val);
                break;

            case 2:
                val = dequeue(a, &front, &rear, size);
                if(val != -1)
                    printf("Dequeued element: %d\n", val);
                break;

            case 3:
                printArray(a, front, rear, size);
                break;

            case 0:
                free(a);
                return 0;

            default:
                printf("Invalid choice\n");
        } 
    
   }

//     printArray(a , front , rear , size) ;
//     printf("%d \n" , a[2]) ; 


//     printf("dequeued element = %d\n" , dequeue(a , &front , &rear , size)) ;
//     printf("dequeued element = %d\n" , dequeue(a , &front , &rear , size)) ; 
 
//   printArray(a , front , rear , size) ;


    return 0 ; 
}