#include <stdio.h>
#define MAX 5

int front=-1,rear=-1,qArr[MAX];

int isEmpty(){
    if(rear==-1&&front==-1){
        return 1;
    }
    return 0;
}
int isFull(){
     if((rear+1)%MAX==front){
        return 1;
    }
    return 0;
}


void enQueue(int item){
    if(isFull()){
        printf("Queue is Full\n");
        return;
    }
    if(rear==-1){
        front++;
    }
    rear=(rear+1)%MAX;
    qArr[rear]=item;
}

int deQueue(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return -1;
    }
    int temp= qArr[front];
    if(rear==front){
        // printf("Deleted %d\n",qArr[front]);
        rear=front=-1;
    }
    else{
        // printf("Deleted %d\n",qArr[front]);
        front=(front+1)%MAX;
    }
    return temp;
}
void display(){

  if(isEmpty()){
    printf("Queue is Empty\n");
  }
  else if(front<=rear){
    for (int i = front; i<=rear; i++)
    {
        printf("%d\t",qArr[i]);
    }
    printf("\n");
  }
 else{              //front>rear
   
     int ptr=front;
    do{
        printf("%d\t",qArr[ptr]);
        ptr=(ptr+1)%MAX;
    }
    while (ptr!=rear+1);
    
    printf("\n");
   
    }
}


