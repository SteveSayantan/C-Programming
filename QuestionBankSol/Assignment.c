#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * head= NULL;


void addEnd(struct Node * ptr, int item){
    while(ptr!=NULL && ptr->next!=NULL){
        ptr=ptr->next;
    }
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next =NULL;
    newNode->data= item;
    if(head==NULL){
        head=newNode;
        return;
    }
    ptr->next=newNode;
}

void addBeg(struct Node * ptr, int item){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next =ptr;
    newNode->data= item;
    head= newNode;
}

void delEnd(struct Node * ptr){
    if(ptr==NULL){
        printf("List is Empty\n");
        return;
    }
    if(ptr->next==NULL){
        head=NULL;
        free(ptr);
        return;
    }
    while(ptr->next->next!=NULL){
        ptr= ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
}

void delBeg(struct Node * ptr){
    if(ptr==NULL){
        printf("List is Empty\n");
        return;
    }
    if(ptr->next==NULL){
        head=NULL;
    }
    else{
        head= ptr->next;
    }
    free(ptr);
}

void display(struct Node * ptr){ 
    if(ptr==NULL){
        printf("List is Empty\n");
        return;
    }
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void search(struct Node *ptr, int item){
    if(ptr==NULL){
        printf("List is Empty\n");
        return;
    }
     while(ptr!=NULL){
        if(ptr->data==item){
            printf("Item Found\n");
            return;
        }
        ptr=ptr->next;
    }
    printf("Item not Found\n");
}

void reverse(struct Node * ptr){
   if(ptr==NULL){
       return;
   }
   reverse(ptr->next);
   printf("%d\t",ptr->data);
}



int main(){
    int data, choice;
    while(1){
        printf("1 Insert at Beginning\n2 Insert at End\n3 Delete from Beginning\n4 Delete from End\n5 Display\n6 Search\n7 Reverse\n8 Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter the number: ");
                     scanf("%d",&data);
                     addBeg(head,data);
                     break;
            case 2 : printf("Enter the number: ");
                     scanf("%d",&data);
                     addEnd(head,data);
                     break;
            case 3 : delBeg(head);
                     break;
            case 4 : delEnd(head);
                     break;
            case 5 : display(head);
                     break;
            case 6 : printf("Enter the number: ");
                     scanf("%d",&data);
                     search(head,data);
                     break;
            case 7 : reverse(head);
                     printf("\n");
                     break;
            case 8 : exit(0);
            default: printf("Invalid Input\n");
        }
    }
}
