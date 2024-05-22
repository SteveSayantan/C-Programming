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

void passByValue(struct Student c)  // a separate copy of 'puja' is being passed to c
{
    c.id = 69;
}

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

    // This is how to pass a struct as call by value

    printf("puja.id before passByValue() = %d\n", puja.id);

    passByValue(puja);

    printf("puja.id after passByValue() = %d\n",puja.id);
    printf("As you can see the value of puja did not change\n");    // and the Student c inside the function has been destroyed i.e. no longer in memory 
    

}



