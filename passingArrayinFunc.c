#include <stdio.h>

// Checkout https://www.geeksforgeeks.org/how-arrays-are-passed-to-functions-in-cc/


//Though we have used [], arr is considered as a pointer by this function (call by reference).
void func1(int arr[]){  // At this point, arr decays into a pointer and starts pointing to the first element in the array

    arr[2]=69;  //This change will get reflected in the original array
    for(int i=0;i<4;i++){
        printf("%3d",arr[i]);
    }

    // since arr has become a pointer to an int, the following will give the size of an int pointer (i.e. 8 bytes)
    printf("The size of arr is %lu",sizeof arr); // 8
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

    // since, we are within the scope of the nums array, here nums points to the entire array (so, its size is equal to that of the array itself)
    printf("The length of the array is %lu",sizeof nums/sizeof nums[0]); // 4
}
