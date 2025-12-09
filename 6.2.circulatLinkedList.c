// circular linkedlist
#include <stdio.h> 
#include <stdlib.h> 


struct Node{
    int data ; 
    struct Node *next; 
} ; 

struct Node *createNode(int val){
    struct Node *p =  (struct Node *)malloc(sizeof(struct Node)) ;
    p->data = val ; 
    p->next=  NULL ;

    return p; 
}


void traverse(struct Node *head){
    struct Node *p = head ; 

    while(p->next!=head){
        printf("%d " , p->data) ;
        p  = p->next ; 
    }

    printf("%d \n" , p->data) ; 
}


struct Node *insertionAtFirst(struct Node *head , int val){
       struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)) ; 
       struct Node *p = head ; 

       while(p->next!=head){
        p = p->next ; 
       }

       ptr->data = val ; 
       ptr->next = head ; 
       p->next = ptr ; 

       return ptr ; 
}

// below is code for insertion at last . 

struct Node *insertionAtLast(struct Node *head , int val){
       struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)) ; 
       struct Node *p = head ; 

       while(p->next!=head){
        p = p->next ; 
       }

       ptr->data = val ; 
       ptr->next = head ; 
       p->next = ptr ; 

       return head ; 
}

// code for insertion at specific val . 

struct Node *insertAtSpecificIndex(struct Node *head , int val , int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)) ; 
    struct Node *p = head ; 

    int i = 0 ; 

    while(i<index - 1){
        p = p->next ; 
        i++  ; 
    }

    ptr->data = val ; 
    ptr->next = p->next ; 
    p->next = ptr ; 

    return head ; 
}

// delete at first . 

struct Node *deleteAtFirst(struct Node *head){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)) ; 
    struct Node *p = head ; 
    ptr=  head ; 

    while(p->next!=head){
        p = p->next ;
    }

    p->next= head->next ;
    free(ptr) ; 
    p = p->next ; 

    return p ; 
}

struct Node *deleteAtLast(struct Node *head){
    struct Node *ptr = head ; 
    struct Node *p = head->next  ;

    while(p->next!=head){
        ptr = ptr->next ; 
        p = p->next ; 
    }

    ptr->next = p->next ; 
    free(p) ; 
    

    return head ;
}


// deletion at specific index 

struct Node *deleteAtIndex(struct Node *head , int index){
    struct Node *ptr = head ; 
    struct Node *p = head->next ; 

    int i = 0 ; 
    while(i<index -1){
        ptr = ptr->next  ; 
        p = p->next ; 
        i++ ; 
    }

    ptr->next = p->next ; 
    free(p) ; 

    return head ; 
}




int main()
{
   struct Node *head = createNode(33) ; 
   struct Node *second = createNode(90) ;
   struct Node *third = createNode(23) ;
   struct Node *fourth = createNode(43) ; 

   head->next = second ; 
   second->next=  third ;
   third->next= fourth ;
   fourth->next = head ; 

   traverse(head) ; 
   printf("===> CODES FOR INSERTION \n") ; 
   printf("--> below is code for insertion at first \n") ; 
   head = insertionAtFirst(head , 45) ; 
   traverse(head) ; 
   printf("-->code for insertion at last \n") ; 
   head = insertionAtLast(head , 13) ; 
   traverse(head) ;
   
   printf("--> code for insertion at specific index \n") ; 
   head = insertAtSpecificIndex(head , 67 , 3) ; 
   traverse(head) ; 


   // below are code for deletion . 

   printf("\n===>CODE FOR DELETION \n") ; 
   printf("--> deletion at first \n" ) ; 
   head = deleteAtFirst(head) ; 
   traverse(head) ; 

   printf("--> deletion at last \n") ; 
   head = deleteAtLast(head) ; 
   traverse(head);

   printf("--> deletion at specific index \n") ; 
   head = deleteAtIndex(head , 2) ; 
   traverse(head); 

   


    return 0 ; 
}


