#include <stdio.h>
#include <stdlib.h>

/* 
    Linked List:

    1. Linked List are similar to arrays (Linear Data Structures)

    2. Arrays elements are stored in contiguous memory locations but linked lists are stored in non-contiguous memory locations
    
    3. Memory and capacity of an array remains fixed but in case of linked lists, we can keep adding or removing elements without any capacity constrains.

    4. Extra space for pointers is required. Random access is not allowed as elements are not stored in contiguous memory location. So we can not access the elements of the linked lists in constant time (using pointer arithmatic) like arrays.


 */

struct Node{
    int data;
    struct Node * next;     // next is a pointer of type struct Node.

    // It is called self-referencing structure.
};

void displayList(struct Node* ptr){ //The address stored in the actual parameter is copied into ptr

    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;      //Updating this ptr to point the next node
    }
}

/* INSERTION TECHNIQUES */

struct Node * insertBeg(struct Node * ptr,int item){       
    struct Node * newNode= (struct Node *)malloc(sizeof(struct Node));
    newNode->data=item;
    newNode->next= ptr;
    return newNode; 
}

void insertAtIndex(struct Node * ptr,int item,int index){       
    int c=0;
    while(c<index-1){   //We have to reach the node at index-1
        ptr=ptr->next;
        c++;
    }
    struct Node * newNode= (struct Node *)malloc(sizeof(struct Node));
    newNode->data=item;
    newNode->next=ptr->next;
    ptr->next= newNode;

}

void insertAtEnd(struct Node * ptr,int item){
     while(ptr->next!=NULL){
       ptr=ptr->next;      //Updating this ptr to point the next node
    }
     struct Node * newNode= (struct Node *)malloc(sizeof(struct Node));
     newNode->data=item;
     newNode->next=NULL; 
     ptr->next=newNode;   
}

/* DELETION TECHNIQUES*/

struct Node * deleteBeg(struct Node * ptr){
    struct Node * temp= ptr->next;
    free(ptr);
    return temp;
}

void deleteFromIndex(struct Node * ptr,int index){
    int c=0;
    while(c<index-1){   //We have to reach the node at index-1
        ptr=ptr->next;
        c++;
    }

    struct Node * temp= ptr->next;
    ptr->next=ptr->next->next;
    free(temp);

}

void deleteEnd(struct Node * ptr){
     while(ptr->next->next!=NULL){ 
       ptr=ptr->next;      
    }
     struct Node * temp= ptr->next;
     ptr->next=NULL;
     free(temp);

}

int main(){
    struct Node * head;     //Head refers to the origin node
    struct Node * second;
    struct Node * third;

    head= (struct Node *)malloc(sizeof(struct Node));   // This returns a pointer which points to a memory of size struct Node in the heap
    second= (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));

    // Linking first and second nodes
    head->data=7;
    head->next= second;

    // Linking second and third nodes
    second->data=8;
    second->next= third;

    // Linking third node with NULL
     third->data=10;
     third->next= NULL; // This marks the end of the linked list


    //Inserting a node at the beginning

    head= insertBeg(head,15);   //We must update the head after inserting at the beginning

    //Insert at a specific index
    insertAtIndex(head,4,2);

    //Inserting at the end
    insertAtEnd(head,9);

    //Deleting the first Node
    head= deleteBeg(head);

    //Deleting Node at a specific index
    deleteFromIndex(head,3);

    //Deleting Node from End
    deleteEnd(head);

    displayList(head);

    return 0;
}