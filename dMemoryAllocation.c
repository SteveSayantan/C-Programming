#include <stdio.h>
#include <stdlib.h>

/* 
    1. Dynamic Memory Allocation is a way in which the size of a data structure can be changed (allocated or freed) during the runtime.

    2. Memory Allocation is done during the programs execution. Reuse of memory is possible and increases efficiency.

    3. Memory Allocation in C program can be broken down into four segments:

        a. Code --> aka text segement, is used to save the code

        b. Static/Global variables --> It is divided into two parts as data segment (to store initialized vars) and bss segment (to store uninitialized vars)

        c. Stack --> Uses LIFO  

        d. Heap
    
 */

/*  malloc() -->

    1. malloc() stands for memory allocation. It reserves a block of memory with the given amount of bytes.

    2. The return value is a void pointer to the allocated space. So, the void pointer needs to be casted to the appropriate type as per requirements.

    3. If the space is insufficient, allocation of memory fails and it returns a NULL pointer.

    4. All the values at allocated memory are initialized to **garbage values**.

    Syntax: 

    ptr= (ptr_type*) malloc (size_in_bytes);

*/

/* calloc() -->

    1. calloc() stands for contiguous allocation. It reserves n blocks of memory with the given amount of bytes.

    2. All the values at allocated memory are **initialized to 0**

    3. The rest is similar to malloc()

    Syntax:

    ptr= (ptr_type*) calloc(n,size_in_bytes);       // n blocks of given size

 */


 /*  realloc() -->

    1. realloc stands for reallocation.

    2. We can change the size of previously allocated memory using realloc() function.

    Syntax:
    ptr= (ptr_type* ) realloc (prev_ptr, new_size_in_bytes);
 
  */

int main(){


    //Use of malloc:

    int * ptr1;  //This ptr will store the pointer returned by malloc

    ptr1= (int *) malloc (3*sizeof(int));    // We need to typecast the pointer as malloc returns a void pointer. This pointer points to the allocated space equivalent to 3*4 i.e. 12 bytes. Using the sizeof operator as the size of int varies in diff. architectures.

    for(int i=0;i<3;i++){
        scanf("%d",ptr+i);      // Storing values in the spaces using pointer. 
    }

    for(int i=0;i<3;i++){
        printf("%3d",ptr[i]);      // Displaying the values.
    }


    //Use of calloc:

    int * ptr2= (int *) malloc (3,sizeof(int));     // This allocates 3 blocks of size int i.e. 12 bytes generally.

    /* The rest is same as malloc */


    //Use of realloc

    ptr2= (int*) realloc (ptr2,4*sizeof(int));  //This returns a pointer which points towards the newly allocated space i.e. ptr2 now points to 16 bytes of memory


    //Use of free()

    free(ptr2); //Frees up the memory
    free(ptr1);
}


