#include <stdio.h>
/* 
    Reference: https://youtu.be/rf6uf3jNjbo and https://youtu.be/q6RicK1FCUs

    The basic approach to solve this problem is:

        1) If we have only 1 disk, we can move it directly from the source to the destination rod.

        2) If we have more than 1 disks (say n), we have to

            i.   move the top n-1 disks to the auxiliary rod , recursively.
            ii.  move the nth disk to the destination rod.
            iii. finally, move the n-1 disks from auxiliary rod to destination rod, recursively.

 */
void towerOfHanoi(int disks,int source,int aux, int des){
    if(disks<=1){
        printf("Move topmost disk from %d to %d\n",source,des);
        return;
    }
    towerOfHanoi(disks-1,source,des,aux);
    printf("Move topmost disk from %d to %d\n",source,des);
    towerOfHanoi(disks-1,aux,source,des);
}

int main(){
    towerOfHanoi(4,1,2,3);
    return 0;
}