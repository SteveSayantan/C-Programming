#include <stdio.h>

// Checkout https://www.geeksforgeeks.org/parameter-passing-techniques-in-c-cpp/ for reference

int main(){

// Actual Parameters: When a function is called, the values (expressions) that are passed in the call are called the arguments or actual parameters.
int a=45,b=67; // a and b have scope inside the main function
sum1(a,b); // Here a and b are actual parameters



int num1=56,num2=78;
//Call by Reference:

changeValue(&a); // Passing the address of the variable a
printf("%d",a); // 456

swap(num1,num2);
printf("%d %d",num1,num2);

}


//Formal Parameters: These are local variables which are assigned values from the arguments when the function is executed. These variables take precedence over global variables.
int sum1(int num1, int num2){ //Here, num1 and num2 are Formal Parameters as when the function is executed, a copy of the value of each argument is stored in each of these.

    return num1+num2; // num1 and num2 have scope inside sum1 only 

}

/* 

In C, we can call a function in two different ways on the basis of specifying the arguments:

1. Call by Value
2. Call by Reference

*/

// 1. Call by Value: The values of the actual parameters are copied into the formal parameters of the function. The original values remain unchanged but the parameters inside the function change. Ex. stated above

//2. Call by Reference: The address of the actual parameters are copied into the formal parameters.


void changeValue(int * address){ // This function takes one pointer as formal argument

    *address=456; // Updating the value pointed by address pointer
}

void swap(int * x, int * y){ //This function takes two pointers x and y as formal args
    int temp;

    temp= *x; // storing the value at address x
    *x=*y; // store the value at address y to address x
    *y=temp;
}