#include <stdio.h> 
#include <stdlib.h> 

struct Node{
    int val ; 
    struct Node *left ; 
    struct Node *right ; 
};


struct Node *createNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)) ; 
    newNode->val = val ;
    newNode->left = NULL ; 
    newNode->right = NULL  ; 
    return newNode ; 
}
// INSERTION IN  BST . note: insertion happens at leaf nodes. 

struct Node *insertion(  struct Node *root ,int val){
             if(root == NULL){
                return createNode(val) ; 
             }

             if(val<root->val){
                root->left = insertion(root->left  , val) ; 
             }
             
             if(val > root->val){
                root->right  = insertion(root->right , val) ; 
             }

             return root ; 
}



// deletion in node. 

// Function to find the minimum value node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}


// Function to delete a node
struct Node* deleteNode(struct Node* root, int val) {
    if (root == NULL) 
        return root;

    // Traverse the tree
    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node found

        // Case 1: No child or only right child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        // Case 2: Only left child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node* temp = findMin(root->right);
        root->val = temp->val; // Copy inorder successor's value
        root->right = deleteNode(root->right, temp->val); // Delete successor
    }

    return root;
}

    

  


void inorderTraversal(struct Node *head){
    if(head!=NULL){
        inorderTraversal(head->left);
        printf("%d " , head->val) ;
         inorderTraversal(head->right) ; 
    }
}



int main()
{

    struct Node *first  =createNode(10) ; 
    struct Node *second = createNode(7) ; 
    struct Node *third = createNode(2) ; 
    struct Node *fourth = createNode(8) ; 

    struct Node *eleventh = createNode(11) ; 

    first->left = second ; 
    second->left = third ; 
    second->right = fourth   ; 

    first->right = eleventh ; 

    inorderTraversal(first) ;

    first = insertion(first , 5) ; 
    printf("\n") ; 
    inorderTraversal(first) ;

    deleteNode(first, 7 ) ;
    
    printf("\n") ; 
    inorderTraversal(first) ;


    return 0 ;
}