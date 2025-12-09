#include <stdio.h> 
#include <stdlib.h> 


#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE]; 

// hash function 

int hash(int key){
    return key%TABLE_SIZE ; 
}

// insert function 
void insert(int key){
    int index = hash(key) ; 
    int startIndex = index ; 

    while(hashTable[index]!=EMPTY && hashTable[index]!= DELETED){
        index = (index+1)%TABLE_SIZE  ; 


        if(index== startIndex){
            printf("Table is full \n") ; 
            return ; 
        }
    }

    hashTable[index] = key ; 
}

// search function 
int search(int key){
    int index = hash(key) ; 
    int startIndex = index ; 

    while(hashTable[index]!= EMPTY){
        if(hashTable[index] == key){
            return index ; 
        }

        index = (index + 1)% TABLE_SIZE ; 

        if(index == startIndex){
            return -1;  
        }
    }

    return -1 ; 
}

void deletekey(int key){
    int index = search(key) ; 


    if(index == -1){
        printf("key %d not found \n" , key) ; 
    }

    hashTable[index] = DELETED ; 
}




int main()
{



    for(int i = 0 ; i<TABLE_SIZE;  i++){
        hashTable[i] = EMPTY ; 
    }

    insert(12) ; 
    insert(22) ; 
    insert(32) ; 
    insert(42) ; 

    printf("index of 22 is %d \n" , search(22)) ; 
    printf("index of 99 is %d \n" , search(99)) ; 

    deletekey(22) ; 

    printf("searching 22 after deletion -> %d \n" , search(22) ) ;


    return 0 ; 
}

