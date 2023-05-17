#include <stdio.h>

void display2D(int (*arr)[4],int N){
   for (int i = 0; i < N; i++)
   {
        for (int j = 0; j < N; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
   }
   
}
void display1D(int * arr,int N){
    for(int * i=arr;i<arr+N;i++){
        printf("%d\t",*i);
    }
}
int main(){
    int arr1D[3]={0};
  
    // int * ptr= arr1D;
    display1D(arr1D,3);
    // printf("%d",*(ptr+2));
    return 0;
}