#include <stdio.h>

// Checkout https://www.geeksforgeeks.org/how-arrays-are-passed-to-functions-in-cc/

void func1(int arr[]){ //Though we have used [], arr is considered as a pointer by this function (call by reference)

    arr[2]=69;  //This change will get reflected in the original array
    for(int i=0;i<4;i++){
        printf("%3d",arr[i]);
    }

}


void func2(int * arrPtr){ // func2 takes a pointer (explicitly)

    *(arrPtr+3)=45; //Changes the element at 3rd index of the array

    for(int i=0;i<4;i++){
        printf("%3d",*(arrPtr+i)); // arrPtr[i] will work too
    }
    
}

void main(){

    // In C, for derived datatypes such as arrays, we use call by reference. Two ways to call an array by reference are:

    int nums[]={1,2,3,4};

    //Passing an array to the function by declaring the array as a parameter 
    func1(nums); // 1,2,69,4


    //Passing an array to the function by declaring a pointer in the function to hold the base address of the array 
    func2(nums); 
}
