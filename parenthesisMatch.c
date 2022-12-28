#include <stdio.h>
#include <stdlib.h>


struct Stack{
    char * arr;
    int top,max;
};

/* 
    Algorithm:

    1. If ( is encountered, push it in stack.

    2. If ) is encountered, pop the content of stack.

    3. If stack underflow occurs, expression is unbalanced.

    4. After evaluation of the whole expression, if the stack is not empty, expression is unbalanced.

    5. Otherwise, expression is balanced.


 */
struct Stack * createStack(int len){
    struct Stack * new= (struct Stack *)malloc(sizeof(struct Stack));
    new->top=-1;
    new->arr= (char *)malloc(len*sizeof(char));
    new->max=len;
    return new;
}


void push(struct Stack * ptr,char a){

    if(ptr->top==ptr->max-1){
        printf("Stack Full");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top]=a;

}
int pop(struct Stack * ptr){

    if(ptr->top==-1){
        return 0;
    }
    ptr->top--;
    return 1;
}

int isEmpty(struct Stack * ptr){

    if(ptr->top==-1){
         return 1;
    }
   return 0;
}


int main(){
    char str[]="(((())";
    struct Stack * stackPointer= createStack(7);
    int i=0;
    while (str[i]!='\0')
    {
        if(str[i]=='('){
            push(stackPointer,'(');
        }
        else if(str[i]==')'){
            if(!pop(stackPointer)){
                printf("Expression Unbalanced\n");
                goto end;
            }
        }
        i++;
    }
    
    if(!isEmpty(stackPointer)){
        printf("Expression Unbalanced, Stack Uncleared\n");
    }
    else{
        printf("Expression Balanced\n");

    }
 
// For checking the contents of stack


/*   
    int j=stackPointer->top;
    while (j>=0)
    {
        printf("%c",stackPointer->arr[j]);
        j--;
    }

*/
   end: 

    return 0;
}
