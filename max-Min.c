#include <stdio.h>
/*  Reference: https://youtu.be/Pt7OyYSxEmo

Approach:
---------
    Here, to store the max and min value at every recursive call, we pass addresses of two variables (MAX and MIN) . They are declared inside main() function.

    1. If only one element is there, store it in both MAX and MIN.

    2. If two elements are there, compare and store the maximum in MAX and minimum in MIN.

    3. Otherwise, divide the elements in two parts. 

        i. Recursively call the function on the first partition. It will get us the maximum and minimum value in that partition in MAX and MIN respectively.

        ii. Now, store those values in two local variables.

        iii. Recursively call the function on the second partition. It will get us the maximum and minimum value in that partition in MAX and MIN respectively.

        iv. If the current value of MAX is less than the previous value, restore the previous value in MAX. If the current value of MIN is greater than the previous value, restore the previous value in MIN.


    The recurrence relation is T(N)= 2T(N/2)+2 i.e. O(N)
 */
void maxMin(int start,int end,int arr[],int * max,int * min){

    if(start==end){
        *max=*min=arr[start];
    }

    else if(end-start==1){
        if(arr[start]>arr[end]){
            *max=arr[start];
            *min=arr[end];
        }
        else{
            *min=arr[start];
            *max=arr[end];
        }
    }
    else{
        int mid= (start+end)/2;
        maxMin(start,mid,arr,max,min);

        int tempMax= *max,tempMin= *min;

        maxMin(mid+1,end,arr,max,min);

        if(tempMax>*max) *max=tempMax;
        if(tempMin<*min) *min=tempMin;

    }
}
int main(){
    int arr[]={10,25,33,14,52,45,23,89},MAX,MIN;

    maxMin(0,7,arr,&MAX,&MIN);

    printf("Max --> %d\nMin --> %d\n",MAX,MIN);

    return 0;
}