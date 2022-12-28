/* 
                ------ -- QUEUE DATA STRUCTURE -- -------
    
    Queue is a linear data structure. It works in FIFO manner i.e. items are to be inserted or removed from two separate ends.

    Application of Queue:

    1) Serving requests on a single shared resource, like a printer, CPU task scheduling, disk scheduling etc.

    2) Handling of interrupts in real-time systems.

    3) When data is transferred asynchronously between two processes. Examples include IO Buffers, pipes, file IO etc.

    4) Breadth First Search (BFS)

 */

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
     if(rear==MAX-1){
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
    rear++;
    qArr[rear]=item;
}

void deQueue(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    if(rear==front){
        printf("Deleted %d\n",qArr[front]);
        rear=front=-1;
    }
    else{
        printf("Deleted %d\n",qArr[front]);
        front++;
    }
}
void insertAt(int item,int pos){
    if(isFull()||front>pos-1){
        printf("Invalid Operation\n");
        return;
    }
    for (int i = rear++; i >=pos-1; i--)
    {
        qArr[i+1]=qArr[i];
    }
    qArr[pos-1]=item;
    if(front==-1) front++;
    
}
void display(){
  if(isEmpty()){
    printf("Queue is Empty\n");
  }
  else{
    for (int i =front; i <=rear; i++)
    {
        printf("%d\t",qArr[i]);
    }
     printf("\n");
  }
}



int main(){
    display();
    enQueue(20);
    enQueue(21);
    enQueue(22);
    enQueue(23);
    enQueue(24);
    display();
    deQueue();
    deQueue();
    display();
    return 0;
}