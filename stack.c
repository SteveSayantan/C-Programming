/* 
                ------ -- STACK DATA STRUCTURE -- -------

    1. Stack is a linear data structure. It works in LIFO manner i.e. items can be inserted or removed from one end only

    2. Application of Stack:

        i. Used in function calls.
       ii. Infix to postfix conversion and other similar conversions
      iii. Parenthesis matching and more
    
    3. It is implemented as an ADT with the help of an array or linkedlist. It has following items:

        i. A pointer 'top' which points to the topmost element.

       ii. Push () --> pushes an element into the stack

      iii. Pop () --> removes an element from the stack

       iv. peek () --> returns the value at a given position

        v. isEmpty () & isFull() --> Determine whether the stack is empty or full

    4. All operations on stack take O(1) time
 */

#include <stdio.h>

#define MAX 5

int Stack[MAX],top=-1;

void isEmpty(){
    if (top==-1)
    {   
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack is not Empty\n");
    
}

void isFull(){
    if (top==MAX-1)
    {   
        printf("Stack is Full\n");       
    }
    else{
    printf("Stack is not Full\n");
    }
    
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
void pop(){
     if (top==-1)
    {   
        printf("Stack is Empty\n");
        return;       
    }
    printf("Removed %d from stack\n",Stack[top]);
    top--;
}
void display(){
     if (top==-1)
    {   
        printf("Stack is Empty\n");
        return;       
    }
    int temp=top;
    while(temp>=0){

        printf("%d\n",Stack[temp]);
        temp--;

    }
}
void peek(int pos){
    if(pos>MAX || pos<1){
        printf("Invalid Position\n");
    }
    else if(pos>top+1){
        printf("Given Position is Empty\n");
    }
    else{
        printf("Element at position %d is %d\n",pos,Stack[top-pos+1]);
    }
}
int main(){

    push(34);
    push(45);
    push(56);
    push(67);
    push(89);
    display();

    pop();
    pop();
    pop();

    peek(3);


    return 0;
    
}




