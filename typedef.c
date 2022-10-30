// typedef is used to give alternate names to existing datatypes.

/* 
    syntax of typedef:

    typedef <previous_name> <alias_name>;   

*/

#include <stdio.h>

struct Student{
    int id;
    float marks;
    char fav_char;
    char name[10];
};
typedef struct Student std;     // Now we can use std to create new instances of Student


typedef struct Employee{
    int id;
    float salary;
    char name[10];
} emp;                          // We can use typedef directly too





int main(){
    
    typedef float decimal; // Assigning a new name to the float datatype
    decimal num1=56.45;     // Any of these names can be used to declare variables of float datatype. 


    std john={69,45.5,'e',"Yahoo"}; // Creating instances of Student using alias name 'std'
    printf("The name of john is %s",john.name); 

    emp e1={45,108.69,"Google"};    // Creating instances of Employee using alias name 'emp'



    int * ptr1,*ptr2; // Usual method to declare multiple pointers

    typedef int * intPointer;   // Using typedef makes it easier
    intPointer ptrA,ptrB;   // Now ,intPointer can be used to declare pointers 



}
