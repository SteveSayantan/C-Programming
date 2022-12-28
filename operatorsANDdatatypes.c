#include <stdio.h> 

int main() { 
    int a,b; //declaration 
    int c=4; //declaration and initialization
   /*
    Basic Data Type: int, char, float, double

    Derived Data Type: array, pointer, structure, union

    Enumeration Data Type: enum

    void Data Type: void

    Checkout https://www.geeksforgeeks.org/data-types-in-c/ for other datatypes

   */ 
   
    printf("%lu",sizeof(int)); //This is known as sizeof operator. sizeof(a) ,where a is an integer,returns **int's** size on that architecture. %lu is used for unsigned long, 
    

    //Logical Operators

    int result;

    result= 23&&45; //1

    result= 23 && 0; //0

    result= 23 || 45; //1

    result =!34; //0

    //Bitwise Operators (Works on each bit)

    result= 2 & 3 ; // 2  This is Bitwise AND. Binary Equivalent of 2 and 3 is 10 and 11. 0 (of 10) & 1 (of 11) gives 0; 1(of 10) & 1 (of 11) gives 1; So the result is 10 which when conveted to Decimal gives 2.

    result= 2|3 ; // 3  This is Bitwise OR. Binary Equivalent of 2 and 3 is 10 and 11. 0 (of 10) | 1 (of 11) gives 1; 1(of 10) | 1 (of 11) gives 1; So the result is 11 which when conveted to Decimal gives 3.

    result = 2^3; // 1  This is Bitwise XOR. Binary Equivalent of 2 and 3 is 10 and 11. 0 (of 10) ^ 1 (of 11) gives 1; 1(of 10) ^ 1 (of 11) gives 0; So the result is 01 which when conveted to Decimal gives 1.

    ~ // Binary ones's complement operator

    << // Binary left shift operator

    >> // Binary right shift operator

    //Miscellaneous Operators

    & //It is addressof operator, this returns the adderss of a variable

    * // Pointer to a variable aka dereference operator

    return 0;
}