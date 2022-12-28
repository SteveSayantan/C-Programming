#include <stdio.h>
#define MAX 5
typedef struct priorityQueueStruct{
    int p;
    char val;
} pQueueEle;

pQueueEle pQueue[MAX];

int front=-1,rear=-1;

int isEmpty(){
    if(rear==-1&&front==-1){
        return 1;
    }
    return 0;
}
int isFull(){
     if(rear==MAX-1){
        return 1;
    }
    return 0;
}

void insertEle(pQueueEle item ){
    if(isFull()){
        printf("Queue is Full\n");
        return;
    }
    if(front==-1&& rear==-1){
        pQueue[++rear]=item;
        front++;
        return;
    }
    int temp=front;
    while(temp<=rear){
        if(pQueue[temp].p<item.p){
            break;
        }
        temp++;
    }
    if(temp<=rear){
        
        for (int i = rear; i >=temp; i--)
        {
            pQueue[i+1]=pQueue[i];
        }
    }
    pQueue[temp]=item;
    rear++;
}
void deQueue(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    if(rear==front){
        printf("Deleted %c\n",pQueue[front].val);
        rear=front=-1;
    }
    else{
        printf("Deleted %c\n",pQueue[front].val);
        front++;
    }
}
void display(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    for (int i = front; i <=rear; i++)
    {
        printf("%c\t",pQueue[i].val);
    }
    printf("\n");
}
int main(){
    pQueueEle first={10,'a'};
    pQueueEle second={11,'b'};
    pQueueEle third={9,'c'};
    pQueueEle fourth={9,'d'};
    pQueueEle fifth={8,'e'};
    pQueueEle sixth={34,'g'};

    insertEle(first);
    insertEle(second);
    insertEle(third);
    insertEle(fifth);
    insertEle(fourth);
    insertEle(sixth);
    display();

    deQueue();
    deQueue();
    deQueue();
    display();
    // printf("%d %d",front,rear);
    return 0;
}