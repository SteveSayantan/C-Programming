// We do not have 'string' data type in C. We express strings using an array of characters terminated by a null character ('\0') which tells the compiler that the string ends here.

// To store a string of length n, we need a character array of minimum length n+1. This extra space is used to store the null character. 



#include <stdio.h>

void printStr(char Str[]);

int main(){

    // **In case of string, we can not declare a char array and assign it to a string separately. It gives error.**

    char str1[]={'S','t','e','v','e','\0'}; // Without the null character it is not considered as a valid string

    char str2[]="Steve"; // If we use double quotes, the compiler automatically adds a null character at the end of the string (if space is available) 

    char str3[10]="Hello"; // In this case, the first 6 element of str3 is being used, the rest of them store garbage value. 

    char invalidStr[5]="Shyam"; //Invalid String    The character array declared can hold 5 elements and the string is made of 5 characters, as a result there is no space for adding the null character 

    char invalidStr2[]={'S','t','e','v','e'}; // Invalid String as no null character at the end of the string


    // Taking string as user input 

    char ipStr[7];
    gets(ipStr); // It takes the string input (Length 6) from the user and stores it in ipStr array with null character added at its end.

    // We can not take input of white space characters using scanf, that's why use of gets is recommended in case of String input (checkout https://www.geeksforgeeks.org/difference-between-scanf-and-gets-in-c , https://www.geeksforgeeks.org/problem-with-using-fgets-gets-scanf-after-scanf-in-c/ ,  also look for other articles in GFG)

    // Printing a String 

    puts(ipStr); //Prints the ipStr char array (String) . checkout https://www.geeksforgeeks.org/puts-vs-printf-for-printing-a-string/ 

}

void printStr(char str[]){
    int i=0;
    while(str[i]!='\0'){
        printf("%c",str[i]);
        i++;
    }
}

int num1,num2;
    printf("Enter the length of two names separated by a space\n");
    scanf("%d%d",&num1,&num2);
    
    char str1[num1+1],str2[num2+1];
    str1[num1]='\0';
    str2[num2]='\0';
    
   printf("Enter the first name:\n");
   
    for(int i=0;i<num1;i++){
        scanf("%c",&str1[i]);
    }
  
   printf("Enter the second name:\n");
   
    for(int i=0;i<num2;i++){
        scanf("%c",&str2[i]);
    }
    
    
    printf("%s is a friend of %s",str1,str2);


