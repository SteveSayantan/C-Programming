// Pointer: It is a datatype which stores the address of another variable.

// It can be of different types such as int,char, array, function or any other pointer.

// Its size depends on the architechture e.g. 4 bytes for 32 bits (in case of int pointers)

// Pointers are declared using * 


int main(){
   int a= 45;

   int * ptr= &a; // Creating a int pointer which stores the address of 'a' which is an int.

   printf("%p\n",ptr); //This prints the stored value of ptr i.e. the address of 'a'. %p is the format specifier to print pointer

   printf("%p\n",&ptr); //This prints the address of the 'ptr' pointer.

   printf("%d\n",*ptr); //Adding a * to the prints the value of the variable to which the 'ptr' pointer is pointing. This is known as pointer dereferencing.

   int * ptr2= NULL; //This is a Null pointer which is not assigned any valid memory address yet.

   int *ptr3,*ptr4;  // For declaring two pointers we have to use * in each case, otherwise it will be considered as an int datatype.
}