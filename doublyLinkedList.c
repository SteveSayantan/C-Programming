#include<stdio.h>
#include<stdlib.h>

struct Node{    //In doubly linked list, we have two pointers, one points to the next node while the other points towards the previous node
    int data;
    struct Node * prev;
    struct Node * next;
};

void displayListInBothDir(struct Node * ptr){
   
    while(ptr!=NULL){
        printf("%3d",ptr->data);
        if(ptr->next!=NULL){
            ptr=ptr->next;
        }
        else{
            break;
        }
    }
    printf("\n");
    while(ptr!=NULL){
        printf("%3d",ptr->data);
        if(ptr->prev!=NULL){
            ptr=ptr->prev;
        }
        else{
            break;
        }
    }


}

int main(){
    struct Node * head;     
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head= (struct Node *)malloc(sizeof(struct Node));   
    second= (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));
    fourth= (struct Node *)malloc(sizeof(struct Node));

    // Linking first and second nodes
    head->data=7;
    head->prev=NULL;
    head->next= second;

    // Linking second and third nodes
    second->data=8;
    second->prev=head;
    second->next= third;

    // Linking third node with fourth node
     third->data=9;
     third->prev=second;
     third->next= fourth; 

    // Linking fourth node with NULL
    fourth->data=10;
    fourth->prev=third;
    fourth->next= NULL;

    displayListInBothDir(head);
    return 0;
}

