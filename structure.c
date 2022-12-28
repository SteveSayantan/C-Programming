// Structures are user defined data types in C. It allows use to combine data of different types together.

/* 
   Syntax of a structure

   struct <struct_name>{

       data_type var1;
       data_type var2;
       data_type var3;

   } variable_names;  


*/

//The dot operator (.) used to access structure members is known as structure member operator

#include <stdio.h>
#include <string.h>

struct Student{
    int id;
    float marks;
    char fav_char;
    char name[10];
} steve,harry;      //Declared steve and harry variables (as global variables)


int main(){
    struct Student ravi;    //we can also declare variables separately (Here ravi is only accessible in main function)

    //Updating the members of the structures
    steve.marks=56.0;
    harry.fav_char='o';
    ravi.marks=108.69;
    strcpy(harry.name,"Yahoo");

    printf("%0.3f\n",steve.marks);
    printf("%0.3f\n",ravi.marks);
    printf("%c",harry.fav_char);
    printf("%s",harry.name);


    struct Student puja={2,45,'t',"Hello"}; // Declaration and initialization in the same line
    printf("%s",puja.name);
}