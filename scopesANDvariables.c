/* 
    1. Variables which are accessed inside a function or a block are called local variables. They can only be accessed by the function they are declared in.
    
    2. Variables defined outside the main (or any) function is called Global Variables. Global variables can be accessed throughout the entire program.

    3. If Global and local variable have the same name, the local variable will preside. 

    4. Static Variables have a property to preserve their values from the previous scope and are not initialized again.

        a. Static variable remains in memory throughout the span of the program.

        b. If static variables are not initialized explicitly, they are automatically initialized to 0.

        c. In C, static variables can only be declared using constant literals. Checkout line 41 for details.

        d. Syntax to initialize static variable as follows:
            static data_type name= value;
 */

#include <stdio.h>

float globalFloat; //This is a global variable


int func1(){
   static int myVar=45; //It is initialized only once and stays in the memory throughout the span of the program. Hence, if the program is called more than once, this variable retains the value from previous call and increments the previous value. 
    myVar++;
    return myVar;
}

int getNum(){
    return 108;
}

int main(){
    int a2; // a2 can only be accessed inside main function, hence it is a local variable.

    printf("%d\n",func1()); // 46
    printf("%d\n",func1()); //47

    static int val1= getNum(); // This gives an error as the memory allocation of static variables occur before runtime, hence it can not get the value returned by func1 while allocating the memory. 
    return 0;
}