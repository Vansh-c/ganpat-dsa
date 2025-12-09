// c) Implement DEqueue with following operations: 
// • InsertionAtRear() • InsertionAtFront() 
// • DeletionAtRear() • DeletionAtFront() 
// • isempty() • isfull() 


#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 5 

// below is queue 

int queue[SIZE]  ; 
int rear = -1 ;
int front = -1 ; 

int isFull(){
    if((front == 0  && rear==SIZE -1) || (front == rear +1)){   // the short condition is if((rear+1)%size== front) 
        return 1 ; 
    }
    return 0 ; 
}

int isEmpty(){
    if(rear == -1  && front == -1){
        return 1 ; 
    }
    return 0 ; 
}


void insertAtRear(int val){
    if(isFull()){    // condition of isfull 
        printf("QUEUE OVERFLOW!") ; 
        return   ;
    }

    if(isEmpty()){
        front  = rear = 0 ; 
    }
    else if(rear == SIZE - 1){
        rear = 0 ; 
    }
    else{
        rear++ ; 
    }

    queue[rear] = val ; 
    
}

void insertAtFront(int val){
    if(isFull()){
        printf("stack overflow") ; 
    }
    else{
        if(isEmpty()){
            front = rear = 0 ;
        }
        else if(front ==0){
            front = SIZE - 1 ; 
        }
        else{
            front-- ;  ; 
        }

        queue[front] = val ; 
    }
}


int  deleteFromRear(){
    int t = -1;  
    if(isEmpty()){
        printf("queue is empty\n") ; 

    }
    else{
        t = queue[rear] ; 
        if(rear == front){
            front = rear = -1 ; 
        }
        else if(rear == 0){
            rear = SIZE - 1 ; 
        }
        else{
            rear-- ; 
        }

        return t ;
    }

    return t ;
}


int deleteFromFront(){
    int t = -1;  
    if(isEmpty()){
        printf("queue is empty") ; 
    }
    else{
        t = queue[front] ; 
        if(front == rear){
            front = rear = -1 ; 
        }
        else if(front == SIZE - 1){
            front = 0 ;
        }
        else{
            front++ ; 
        }

        return t ; 
    }

    return t ; 
}





void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}



int main() {
    // Insert at rear
    insertAtRear(10);
    insertAtRear(20);
    insertAtRear(30);
    display();

    // Insert at front
    insertAtFront(5);
    insertAtFront(1);
    display();

    // Attempt overflow
    insertAtRear(40); // should show overflow

    // Delete from front
    deleteFromFront();
    deleteFromFront();
    display();

    // Delete from rear
    deleteFromRear();
    display();

    // More insertions to test wrap-around
    insertAtRear(25);
    insertAtFront(0);
    display();

    return 0;
}