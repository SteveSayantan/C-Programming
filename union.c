/* 
    Union:
    1. Union is a user defined data type (very similar to structures)

    2. The difference between structures and unions is that, each member in a structure has its own storage location , whereas member of a union uses a single shared memory location.

    3. This single shared memory location is equal to the size of its largest data member.

 */

#include <stdio.h>

union Employee{     // Declaration and initialization are similar to that of struct except we have to use union in this case.

    int id;         // 4 bytes
    char name[10];  // 10 bytes

// In union, these members share a single memory location which is equal to the size of its largest data member i.e. 10 bytes. In case of struct, it would have taken total 14 bytes of memory.

// Only one member can be used at once.
}

int main(){
    union Employee e1;

    // Only one member can be used. If more than one members are used, the last used member prevails.
    e1.id=56;
    strcpy(e1.name,"Yota"); 

    printf("%d",e1.id); //This returns garbage value


}