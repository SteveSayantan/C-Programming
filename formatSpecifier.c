#include <stdio.h>
#define PI 3.14   // Don't put ; after this

int globalVar=34; //This is a global variable which can be accessed from anywhere in this program
int main() {
    
   
   int a=4; //These are only accessible inside main
   float b=34.456;
   
   printf("%d is an int, %f is a float",a,b);  // 45 is an int, 34.456001 is a float

   /* 
        %c is used to print character
        %d is used to print int
        %f is used to print float
        %l is used to print long
        %lf is used to print double
        %Lf is used to print long double
        %s is used to print String
    */

    //Numeric String Modifiers

    printf("The value of b upto 3 decimal point is %0.3f",b); //The value of b upto 3 decimal point is 34.456

    // For %nd it will always print n int digits; If the input has less than n digits, it will print a space instead of the remaining digits before or after printing the int

    printf("The value of a with 3 offset is%3d",a); //The value of a is  4 (Prints two spaces and one int, total three elements)

    printf("The value of a with 3 offset is%3d",45); //The value of a is 45 (Prints one space and two int, total three elements)

    printf("The value of a with 3 offset is%3d",453); //The value of a is453 (Prints zero space and three int, total three elements)

    printf("The value of a is %-4dthis",453); //The value of a is 453 this (Prints three int digits and one space after 453, total four elements)

    printf("The value of b is%5.1f",45.23); //The value of b is 45.2 (First, it will try to print the input with one decimal i.e. 45.2; As it was supposed to print total 5 digits and it has printed 4 digits including the dot, the remaining one digit adds as a space before the int)
    printf("The value of b is %-5.1fthis",45.23); //The value of b is 45.2 this (First, it will try to print the input with one decimal i.e. 45.2; As it was supposed to print total 5 digits and it has printed 4 digits including the dot, the remaining one digit adds as a space after the int)

    printf("The value of b is%2.1f",45.23); //The value of b is 45.2 (First, it will try to print the input with one decimal i.e. 45.2; In this case, it is not possible to print all these within 2 digits, so this condition is ignored)




    //Defining Constants (Use const keyword or use #define preprocessor)

    const int num= 45; //Can not modify the value of num

    printf("%f",PI); //3.14 (Here PI is a constant)


    //Escape Sequence Characters
    printf("This creates a \n new line"); // \n gives a new line

    printf("This is how we use \" inside a string"); // Use \' to escape single quotes and \\ to escape \.

    printf("It is used as\ttab"); // \t gives a tab, \v gives vertical tab

    printf("Hello Geeks\b\bF"); // Hello GeeFs  \b transfers the cursor one character back with or without deleting on different compilers.


    return 0;
}