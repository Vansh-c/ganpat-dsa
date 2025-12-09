// doubly linkedlist. 

#include <stdio.h> 
#include <stdlib.h> 


struct Node{
    int data ; 
    struct Node *left ; 
    struct Node *right ; 
} ; 


struct Node *createNode(int val){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node)) ; 
    node->data  =val ; 
    node->left = NULL ; 
    node->right = NULL ; 

    return node ; 

}
 

struct Node *insertAtFirst(struct Node *head , int val){
       struct Node *p = (struct Node *)malloc(sizeof(struct Node)) ; 
       p->data = val ; 
       p->left = NULL ; 
       p->right = head ; 

       if(head!=NULL){
        head->left = p ;
       }

       return p ;
}

// code to insert at end . 

struct Node *insertAtEnd(struct Node *head,  int val){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node)) ;
    
    struct Node *ptr = head ; 

    while(ptr->right!=NULL){
        ptr = ptr->right ; 
    }

    p->data = val ; 

    ptr->right = p ; 
    p->left = ptr ; 

    return head ; 

}

// insert at specific index 

    struct Node *insertAtIndex(struct Node *head , int val , int index){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)) ; 
        struct Node *ptr = head ; 


        int i = 0 ; 
        while(i!=index-1 && ptr->right!=NULL){
            ptr = ptr->right ; 
            i++ ; 
        }

        newNode->data = val ; 
        newNode->right = ptr->right ;
        ptr->right->left = newNode ;
        ptr->right = newNode ; 
        newNode->left = ptr ;

        return head ;  
    }


struct Node *deleteAtFirst(struct Node *head){
    struct Node *temp = head ;  

    head = head->right ; 
    head->left = NULL ; 
    free(temp) ; 

    if(temp!=NULL){
        temp->left = NULL ; 
    }

    return head ; 

}


struct Node *deleteAtLast(struct Node *head){
    struct Node *ptr = head ; 
    struct Node *p = head->right ; 

    while(p->right!=NULL){
           ptr = ptr->right ; 
           p = p->right ; 
    }

    struct Node *temp = p ; 
    ptr->right = p->right ; 
    // p->left = ptr ; 

    free(temp) ; 
    return head ; 
}

struct Node *deleteAtSpecificNode(struct Node *head , struct Node *node){
    struct Node *ptr = head ; 
    struct Node *p = head->right ; 

    while(p != node){
        p = p->right ; 
        ptr = ptr->right;   
    }
    
    struct Node *  temp = p ; 
    ptr->right = p->right ; 
    p->right->left = ptr ; 
    free(temp) ;
    
    return head ;

}


void traverse(struct Node *head){
    while(head!=NULL){
        printf("%d " , head->data) ; 
        head = head->right ;
    }

    printf("\n") ; 
}


int main()
{
    struct Node *head = createNode(45) ; 
    struct Node *second = createNode(88) ; 
    struct Node *third = createNode(78) ; 
    struct Node *fourth = createNode(67) ; 

    head->right = second ; 
    head->left = NULL ; 

    second->right = third ; 
    second->left = head ; 

    third->right = fourth ; 
    third->left = second ; 
    
    fourth->left = third ; 
    fourth->right = NULL ; 

    traverse(head) ; 

    printf("\n===>INSERTION CODE \n"); 

    head = insertAtFirst(head, 56) ; 
    traverse(head) ; 
    head = insertAtEnd(head , 13) ; 
    traverse(head) ; 

    head = insertAtIndex(head , 34 , 2   ) ; 
    traverse(head) ; 

    printf("\n===>below  are code for deletion:\n") ; 
    head = deleteAtFirst(head) ; 

    traverse(head) ;
    head = deleteAtLast(head) ; 
    traverse(head) ; 

    head = deleteAtSpecificNode(head,  second) ; 
    traverse(head) ; 



    return 0 ;
}


