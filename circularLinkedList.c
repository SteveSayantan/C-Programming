#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void displayList(struct Node * ptr){
    struct Node * start=ptr;
    do{
        printf("%3d",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=start);
}

struct Node * insertAtFirst(struct Node * ptr, int item){ // This basically adds a node before the given node (ptr)
    struct Node * start=ptr->next;
    while(start->next!=ptr){
        start= start->next;
    }

    struct Node * newNode= (struct Node *)malloc(sizeof(struct Node)); 
    newNode->data=item;
    
    start->next=newNode;
    newNode->next=ptr;
    return newNode;
}

int main(){

    struct Node * head= (struct Node *)malloc(sizeof(struct Node));
    struct Node * second= (struct Node *)malloc(sizeof(struct Node));
    struct Node * third= (struct Node *)malloc(sizeof(struct Node));

    // Linking first and second nodes
    head->data=7;
    head->next= second;

    // Linking second and third nodes
    second->data=8;
    second->next= third;

    // Linking third node with the first node(head) again
     third->data=10;
     third->next= head; 

    //Inserting element at first
    head=insertAtFirst(head,3);

    displayList(head);
    return 0;
}