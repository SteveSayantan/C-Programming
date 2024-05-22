#include <stdio.h>

int main() {

    int a=34;
    int* ptrA=&a;

    char c='34';
    char* ptrC= &c;

    printf("%d\n",ptrA); //1637287020
    printf("%d\n",ptrA+1); // 1637287024  Adds 1 size of int i.e. 4 (bytes) to the address, but does not change the address stored in ptrA

    printf("%d\n",ptrC); //711693539
    printf("%d\n",ptrC-2); // 711693537  Subtracts 2 size of char i.e. 2 (bytes) to the address,but does not change the address stored in ptrC
    printf("%d",--ptrC); //711693538 Decreases the address stored in ptrC by 1 size of char i.e. 1 byte, and it updates the address stored in ptrC, ptrC-- will print the previous value and after that update the variable which will not produce expected output.
  


    int arr[]={1,2,3,4,5}; //This 'arr' (the name of an array) itself, without any index subscripting, can be assigned to an integer pointer. The name of an array ('arr' in this case) itself points towards the first element of that array.

    int * ptrArr = arr; // ptrArr now stores address of the first element of arr array. 
  
    printf("%d\n",&arr[0]);
    printf("%d\n",arr);     //Both of these yield the same output i.e. the address of the first element of arr (as arr itself points towards the first element of it)

    printf("%d\n",&arr[3]);
    printf("%d\n",arr+3); //Both of these print the address of element at 3rd index of arr

    printf("%d\n",arr[3]);
    printf("%d\n",*(&arr[3]));
    printf("%d\n",*(arr+3)); //All of these print the value at the 3rd index of the array

    // arr++; // Throws an error. As arr is pointing to the first element of the array, we can not update it. It acts as a constant.
    ptrArr++; // This can be done, as ptrArr is a separate pointer which stores the adderss of arr[0]
    return 0;
}
/* 
    2D arrays and pointers:
    -----------------------

        Resources:
        1)  https://www.youtube.com/live/Hdoy8i0PrFo?feature=share 

        2)  https://youtu.be/tw-qWGG8y5g

        3)  https://stackoverflow.com/questions/7586702/is-2d-array-a-double-pointer

        

    Key Takeaways:

    i)  Arrays, when passed to a function (or used in expressions), always get converted to a pointer to its first element (this element may be an int or an entire array)

    ii) A 2D array can be considered as an array of 1D arrays. When a 2D array is passed to a function, it gets converted to a pointer to its first sub-array (of type int (*) []).

    iii) Now, if the pointer to sub-array is again passed to a function, that also converts to a pointer to its first integer. Thereby, returning the address of the first integer of the 2D array.

        e.g.,

        int arr[][3]={{1,2,3},{4,5,6}};
        
        int (*p)[3]=arr   // Passing 'arr' like this in an expression (or as function arg.) decays it to a pointer to its first sub-array. p copies it and hence, p is a pointer to the first sub-array ( type of p is int (*)[3] )


        Now, if p is passed again to a function, it decays and points to the first integer of the first sub-array.
        
        printf("%p\n",p);   // prints the address of the first integer of the first sub-array  


        *p ( the value stored in p ,i.e. the first-sub array), when passed to a function, decays to a pointer to the first integer of it. Thereby, returning the address of the first integer.

        printf("%p\n",*p);   // prints the address of the first integer of the first sub-array
  

        To get the value at first index, we have to write **p (to dereference the value returned by *p)

        printf("%p\n",**p);   // prints the value of the first integer of the first sub-array


*/