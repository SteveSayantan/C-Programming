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