/* 
    Data Structure: https://www.geeksforgeeks.org/data-structures/

    Application of Data Structure: https://www.geeksforgeeks.org/what-is-data-structure-types-classifications-and-applications/
    
*/
#include <stdio.h> //preprocessor command

int main() { //The execution of the program starts here
    int a,b;
    printf("Enter number a: \n");
    scanf("%d",&a);
    
    printf("Enter number b: \n");
    scanf("%d",&b);
    
    printf("The sum of entered numbers is %d\n",a+b);
/*
    Steps to execute a program in C:
    
    1. Pre-Processing: In this step, comments are removed, Macros are expanded and the content of the included files are added (including our code) in the .i file which originates at this step.
    
    2. Compilation : In this step, all the .i file is converted to assembly level language and the file created at this step has an extension of .s
    
    3. Assembly: In this step, the .s file containing assembly language is converted into machine language (binary). This type of file has .o extension.
    
    4. Linking: Linker joins all the .o files to make the executable file(.exe)
*/
    return 0;
}