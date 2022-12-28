#include <stdio.h> 
int main() { 
    int a,b; //declaration 
    int c=4; //declaration and initialization

    float num= 23.0f;   // We need to use f for float, otherwise it would be considered as a double
    double num2= 45.90;


   /*
    Basic Data Type: int, char, float, double,short
    Derived Data Type: array, pointer, structure, union
    Enumeration Data Type: enum
    void Data Type: void
   */ 
   
    printf("%lu",sizeof(int)); // %lu is used for unsigned long, this command prints the space taken by int in bytes
    
        return 0;
}