/* 
  Quick Sort:

    1. It is a non-stable sorting algorithm.

    2. It is an in-place sorting algorithm.

    3. The Best-Case time complexity is O(NlogN)

    4. The Worst-Case time complexity is O(N^2)
 */

 #include <stdio.h>

 void sort(int nums[], int low, int hi) {
        if (low >= hi) {
            return;
        }

        int s = low;
        int e = hi;
        int m = s + (e - s) / 2;
        int pivot = nums[m];

        while (s <= e) {

            // also a reason why if its already sorted it will not swap
            while (nums[s] < pivot) {
                s++;
            }
            while (nums[e] > pivot) {
                e--;
            }

            if (s <= e) {
                int temp = nums[s];
                nums[s] = nums[e];
                nums[e] = temp;
                s++;
                e--;
            }
        }

        // now my pivot is at correct index, please sort two halves now
        sort(nums, low, e);
        sort(nums, s, hi);
    }


 int main(){
    int arr[]={22,34,56,12,6};
    sort(arr,0,4);
    return 0;
 }