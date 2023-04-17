#include <stdio.h>
/* 
    Functions For File I/O :
    -----------------------

    To work with files first we need to declare a pointer of type FILE, which should be initialized with NULL.

    For any doubt, feel free to check out GFG articles and the lecture linked below.
*/
    
/* 
    fopen() and fclose():
    --------------------
    1. stdio.h contains a function fopen() for opening files in C.

    2. It takes two arguments, the file path (string) and mode (string) and returns a FILE pointer. For details https://youtu.be/qg69AXmHhx8

    3. Now, to read string, we use fgets() function, which takes 3 args. For details https://www.geeksforgeeks.org/fgets-gets-c-language/

        char *  --> to store the output.
        int     --> number of characters to be read (including '\0')
        FILE *  --> file to be read

    4. To read character, we shall use fgetc() function which takes a pointer of type FILE and returns the ASCII code of the character. https://www.geeksforgeeks.org/fgetc-fputc-c/

    5. After using the file, we need to close it using fclose() which takes a pointer of type FILE
 */

int main(){
    FILE * ptr= NULL;
    char ipStr[15],c;
    ptr= fopen("test.txt","r");     // "w" for write mode

    
    // Reading a String:
    // fgets(ipStr,13,ptr);
    // puts(ipStr); 
   

    // Reading a Character:
    // c=fgetc(ptr);
    // putc(c,stdout);          // for details on putc https://www.geeksforgeeks.org/c-library-function-putc/     



    // For the rest of the modes, checkout the lecture linked above.

    fclose(ptr);
    return 0;
}