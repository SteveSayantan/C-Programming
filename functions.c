//Basic Syntax of a C function:

/* 

    return_type function_name(data_type arg1, data_type arg2...){
        
        //Function Body
    }

*/ 

//Types of Function:

//  1. Library Function - Functions included in C header file

// 2. User defined Functions - Functions separately created by the user



// If a function is called **before its definition/initialization** , the compiler throws a warning. To avoid this, we should declare the function before main.


#include <stdio.h>

int sum1(int a,int b); //Declaring the function prior to call

int main() {
    int a=10,b=9;
    printf("The sum is %d",sum1(a,b));

    return 0;
}

int sum1(int num1, int num2){
    return num1+num2;
}