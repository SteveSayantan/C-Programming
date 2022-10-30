/* 
    Abstract Data Type: It is used to create custom data type with some values and functions. 

    In C, we use struct to define ADT

*/

// Implementing Array as an ADT: Making a custom data-type which works like array but might have some extra features

#include <stdio.h>
#include <stdlib.h>

struct myArray{
    int total_size,used_size,*ptr;

};

void createArray(struct myArray * a,int tSize,int uSize){   //  'a' pointer which stores the address of an instance of data-type 'struct myArray' . Just like we write int * ptr 

    (*a).total_size=tSize;      // Dereferencing the pointer (which gives the instance of struct myArray datatype ) and setting the value of the member

    a->used_size=uSize;         //We can do the same like this. 'a->' is used to dereference the 'a' pointer and that gives us the instance of struct myArray datatype. Its used_size property is being updated.

    a->ptr= (int*)malloc(tSize*sizeof(int));

}

void display(struct myArray *a){
    printf("Entered numbers are: ");
    for(int i=0;i<a->used_size;i++){    // i should be less than the value of used_size member of the instance of struct myArray, which 'a' is pointing to

        printf("%3d",(a->ptr)[i]);      // Or, we could have done *(a->ptr+i)
    }
    printf("\n");
}

void insertEleAtInd(struct myArray * a, int ele,int ind){

    if(a->total_size==a->used_size){
        printf("Insertion Failed\n");
        return;
    }
    for(int i=a->used_size-1;i>=ind;i--){

       (a->ptr)[i+1]=(a->ptr)[i]; 
    }
    (a->ptr)[ind]=ele;
    a->used_size++;

}

int main(){
    
    struct myArray arr;
    createArray(&arr,5,3);  //Passing the arguments
    
    printf("Enter numbers: ");
    for(int i=0;i<arr.used_size;i++){
        scanf("%d",arr.ptr+i);
    }

    display(&arr);

    insertEleAtInd(&arr,45,0);
    
    display(&arr);
    
    printf("The updated size of the array is %d",arr.used_size);

}

