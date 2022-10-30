#include <stdio.h>
#include <string.h>


int main(){
    char s1[]="Steve";
    char s2[]="Sayantan";

    puts(strcat(s1,s2)); // SteveSayantan  strcat function concatenates the first string (dest) with the second one(src). 
    puts(s2); // ayantan    The first character of the second string is used to overwrite the Null-character present at the end of the first string(dest). Hence the src string is changed.

    printf("%d",strlen(s2)); //strlen function returns the length of the given string excluding the null character

    puts(strrev(s2)); //strrev function returns the reversed string

    char s3[4];
    // s3="wow"  // Such assignment is invalid
    strcpy(s3,"wow"); // strcpy function copies the given string to the given array. Retains the source string


    printf("%d",strcmp(s1,s2)); //This function compares these two strings according to ASCII value and returns an integer. 
    
    /*  strcmp returns: 

    1. Returns greater than 0 when the first not matching character in leftStr have the greater ASCII value than the corresponding character in rightStr 

    2. Returns less than 0 when the first not matching character in leftStr have lesser ASCII value than the corresponding character in rightStr.

    3. Returns 0 when both strings are found to be identical. That is, That is, All of the characters in both strings are same.
    */ 
}