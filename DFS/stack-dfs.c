#include <stdio.h>

#define MAX 10

int Stack[MAX],top=-1;

int isEmpty(){
    if (top==-1)
    {   
        return 1;
    }
    return 0;    
}

void push(int item){
     if (top==MAX-1)
    {   
        printf("Stack is Full\n");
        return;       
    }
    top++;
    Stack[top]=item;
}

int pop(){
     if (top==-1)
    {   
        printf("Stack is Empty\n");
        return -111;       
    }
    return Stack[top--];
}