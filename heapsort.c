/* 
    Heap is a complete binary tree. Reference: https://youtu.be/HqPJF2L5h9U

    1. If the root is having element greater than or equal to its children, it is called max heap.

    2. If the root is having element smaller than or equal to its children, it is called min heap.

    N.B. Each and every operation related to heap discussed below uses array-representation of binary tree. Other methods of representation like linked-list are not used.

    Insertion:
    ----------

    First, we add an element to the leaf (keeping the heap's completeness intact). After that it moves towards root by comparing with its parent node. Refer to video lecture for details.

    Time complexity of Insertion in heap Min( O(1),O(logn) ) .

    Deletion:
    ---------

    From heap, we can **only** remove the root element.
    After removing the root, the last element of the heap is added to the root. Then it is pushed towards leaf by comparing with its children nodes (For details, checkout the lecture)

    Time taken to delete is O(log n).

    Whenever we delete from heap, we get max or min element (depending on the type of the heap)

    Heap Sort: (Inplace and Unstable)
    ---------

    1) First we need to create a max or min heap from the given values, inserting them one by one or applying heapify . It takes O(nlogn) or O(n) respectively.

    2) Post that, we shall delete all elements from heap one by one. Ultimately, we obtain sorted values. It also takes O(nlogn).
    
    Total time complexity O(nlogn). Refer to the video lecture for details.

    Heapify: O(n)
    ---------

    The process of converting a heap (complete binary tree) into a max-heap or min-heap. 

        Adding elements one by one to our max-heap isn't practical at all.
        The values(to be sorted) provided in an array, we consider it to be a heap. Now, heapify is used to make a min or max heap from that heap.
    
    Refer to the lecture for details.

    Priority Queue:
    --------------

    There are two types of PQ,

        i) smaller number, higher priority (Min-heap is used)
        ii) largeer number, higher priority (Max-heap is used)

    In both the cases, insertion and deletion in PQ takes O(logn)
    
 */
// Heap Sort in C
#include <stdio.h>

void swap(int arr[],int a, int b)
{

	int temp = arr[a];

	arr[a] = arr[b];

	arr[b] = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)   // **This function will perform heapify on elements having index upto N-1 **
{
	// First, find largest among root (i.e. i ) , its left child and right child

	// Initialize largest as root
	int largest = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < N && arr[left] > arr[largest])

		largest = left;

	// If right child is larger than largest so far
	if (right < N && arr[right] > arr[largest])

		largest = right;

	// If largest is not root, swap the largest element to the root
	if (largest != i) {

		swap(arr,i,largest);    // After swapping, the tree rooted at 'i' is a max-heap

		// Now, Recursively heapify the sub-tree corresponding to the swapped index
		heapify(arr, N, largest);
	}
}



void heapSort(int arr[], int N)
{

	// First, heapify the given arr
	for (int i = N / 2 - 1; i >= 0; i--) // Start heapify process from the parent node of the last element i.e. N/2-1

		heapify(arr, N, i);

	// After that, delete from max heap
	for (int i = N - 1; i >= 0; i--) {

		swap(arr,0,i);      // To mimic the deletion process, we swap the root and last element

		// Now, Heapify swapped root element to get highest element at root again

		heapify(arr, i, 0);  // This will heapify till index i-1 i.e. leaving the last index.
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr,N);
	printf("Sorted array is\n");
	printArray(arr, N);
    return 0;
}

// Time Complexity is O(NlogN)


