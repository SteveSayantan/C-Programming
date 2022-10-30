#include <stdio.h>

void MultiplyArray(int r1,int c1,int arr1[][c1],int r2,int c2,int arr2[][c2]);
int main()
{
    int nums1[][3]={{2,3,1},{3,2,1}};
    int  nums2[][2]={{1,2},{2,1},{1,2}};
    
    MultiplyArray(2,3,nums1,3,2, nums2);

    return 0;
}

void MultiplyArray(int r1,int c1,int arr1[][c1],int r2,int c2,int arr2[][c2]){
    if(c1!=r2){
        printf("Invalid Array \n");     //Check if the provided arrays are multiplicable 
        return;
    }
    for (int row = 0; row < r1; row++) {    //The entire process is repeated r1 times

            for (int colArr2 = 0; colArr2 < c2; colArr2++) { //For each row of arr1, we have to run this loop c2 times 
                
                int sum=0;

                for (int numArr2 = 0; numArr2 < r2; numArr2++) {    //Multiplying each element of a row in arr1 with corresponding elements of a particular col in arr2

                   sum+= arr1[row][numArr2]*arr2[numArr2][colArr2]; 
                }
                printf("%3d",sum);
            }
             printf("\n");
        }
}