#include <stdio.h> 
#include <stdlib.h>

struct Node{
    int data; 
    struct Node *next ; 
}; 


struct Node *createNode(int val){
   struct Node  *p = (struct Node *)malloc(sizeof(struct Node)) ; 
   p->data = val ; 
   p->next = NULL ;

   return p ; 

} 


struct Node *insertAtLast(struct Node *head,int val){
    struct Node *p = createNode(val) ;
    struct Node *ptr = head ; 

    while(ptr->next!=NULL){
        ptr = ptr->next ; 
    } 

    ptr->next = p ; 
 
    return head ; 


}

// below is code for insert at specific node . 

struct Node *insertAtSpecificNode(struct Node *head , struct Node *n ,  int val){
    struct Node *ptr = createNode(val) ; 
    struct Node *p = head ; 

    while(p->next  != n){
        p = p->next ; 
    }

   ptr->next = p->next ;  
   p->next = ptr ; 

   return head ; 


}


void traverse(struct Node* head){
    if(head == NULL){
       printf("there is no linkedList\n") ; 
    }

    while(head!=NULL){
        printf("%d " , head->data) ;
        head = head->next ; 
    }

    printf("\n") ; 
}


struct Node *insertAtFirst(struct Node *head , int val){
    struct Node *ptr = createNode(val) ; 

    if(head == NULL){
        return head ; 
    }

    ptr->next = head ; 
    return ptr ; 
}


struct Node *deletionAtFirst(struct Node *head){
    struct Node *p = head ; 
    head = head->next ; 

    free(p) ; 
    return head ; 
}


struct Node *deletionAtLast(struct Node *head){

    struct Node *p = head ; 
    struct Node *ptr = head->next ; 

    while(ptr->next!=NULL){
        ptr=  ptr->next;  
        p = p->next ;
    }

    p->next = ptr->next ; 
    free(ptr) ; 

    return head ; 
}


struct Node *deletionAtspecificNode(struct Node *head , struct Node *n){
    struct Node *p = head ; 
    struct Node *ptr = head->next ; 

    while(ptr->next !=n){
        p = p->next ; 
        ptr = ptr->next ; 
    }

    p->next = ptr->next ;
    free(ptr) ; 

    return head ; 
}


int main()
{
    struct Node *head = createNode(34) ; 
    struct Node *second = createNode(78) ; 
    struct Node *third=  createNode(33) ; 
    struct Node *fourth = createNode(13) ; 

    head->next = second ; 
    second->next = third ; 
    third->next = fourth ; 
    fourth->next = NULL ; 
    

    printf("===> BELOW ARE INSERTION CODES \n") ; 
    traverse(head) ; 
    printf("--> insertion at first \n") ;
    head = insertAtFirst(head , 65) ; 
    traverse(head) ; 
    printf("--> insertion at last \n" );
    head = insertAtLast(head , 990) ; 
    traverse(head) ; 
    printf("--> insertion at specific Node \n") ; 
    head = insertAtSpecificNode(head , third , 53) ; 
    traverse(head) ; 


    printf("\n==>BELOW ARE DELETION CODES \n") ; 
    printf("-->deletion at first\n") ; 
    head= deletionAtFirst(head) ; 
    traverse(head) ; 
    printf("-->deletion at last \n") ; 
    head = deletionAtLast(head) ; 
    traverse(head) ; 
    printf("-->deletion at specific node \n") ; 
    head = deletionAtspecificNode(head , third) ; 
    traverse(head) ; 



    return 0 ;
}