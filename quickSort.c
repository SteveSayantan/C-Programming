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
        int pivot = nums[low];                    //Here, We have to choose arr[low] as pivot only

        while (s < e) {                         // if only one element is there, no need to run the loop

            while (nums[s] <= pivot && s <hi) {          // search for an element greater than pivot in the left part. s<hi because we need s to stop when s=hi 
                s++;
            }
            while (nums[e] > pivot && e > low) {          // search for an element less than pivot in the right part. e<low because we need e to stop when e=low
                e--;
            }

            if (s < e) {                      // we have to perform this check to prevent swapping when the pointers have changed their polarity 
                int temp = nums[s];
                nums[s] = nums[e];
                nums[e] = temp;
            }
        }

        // Ultimately, swapping the pivot element with the element at e (This will ensure, all the smaller elements than pivot are on its left and vice versa)

        int temp = nums[low];
        nums[low] = nums[e];
        nums[e] = temp;


        // now my pivot is at index e, sort the two sides of pivot
        sort(nums, low, e-1);
        sort(nums, e+1, hi);
    }

    void quickSort(int[] arr, int low, int high){   

        // Here, we are choosing the high element as pivot and placing it at its correct position
        
         if (low < high) {
           int i = low;
           int pivot = arr[high];

            for (int j = low; j < high; j++) {
                // i always points to the element grater than the pivot, dry run this part for better understanding
                if (arr[j] <= pivot) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i++;
                }
            }
            // swapping the element at 'i' with the pivot element
            int temp = arr[i];
            arr[i] = arr[high];
            arr[high] = temp; 
            
            // now my pivot is at index i, sort the two sides of pivot
            quickSort(arr, low, i - 1);
            quickSort(arr, i + 1, high);
        }
    }


    void quickSort2 (int[] arr, int low, int high){   

        // Here, we are choosing the mid element as pivot and placing it at its correct position
        
        if (low < high) {
            int i = low;
            int mid= low+(high-low)/2;
            int pivot = arr[mid];

        // Sending the pivot element to high to avoid conflict

            int temp1 = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp1;

        // Now, our pivot is located at high, hence the remaining part is same as the previous   
            for (int j = low; j < high; j++) {
                if (arr[j] <= pivot) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i++;
                }
            }
        
            int temp = arr[i];
            arr[i] = arr[high];
            arr[high] = temp; 
            
            quickSort2 (arr, low, i - 1);
            quickSort2 (arr, i + 1, high);
        }
    }



 int main(){
    int arr[]={22,34,56,12,6};
    sort(arr,0,4);
    return 0;
 }