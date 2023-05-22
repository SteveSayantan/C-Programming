// Reference : https://youtu.be/rnYBi9N_vw4

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int graph[10][10];

// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[],int N)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < N; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


void printMST(int parent[],int N)
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < N; i++)
		printf("%d - %d \t%d \n", parent[i], i,graph[i][parent[i]]);
}

void displayArr(int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void primMST(int N)
{
	// The indices of each auxiliary array represents the corresponding node

	
	int parent[10];				// Array to store constructed MST
	
	int key[10];				// Array to store the weight/cost incurred to reach neighbour
	
	bool mstSet[10]={false};	// To check if a vertex is included in MST

	// Since, no node has yet been visited, initialize all the elements of key array with infinite and mstSet with false
	for (int i = 0; i < N; i++)
	{
		key[i]=INT_MAX;
	}
	
	
	key[0] = 0;	// Make key 0 so that this vertex is picked as first vertex.

	
	parent[0] = -1;	// 0th node has no parent as it is genesis node

	/* 
		After this initial setup, at each step

		1. Find the index/node (not included in MST) with minimum value from key array.

		2. Include it in MST i.e. mark the corresponding index as true

		3. Find all the neighbours(not included in mst) of that node . 
			If the cost/weight incurred is less than the current key of a neighbour, update the key.
			Also update the parent (of that neighbour node) to current node.
		
		4. Repeat the above steps V-1 times, as the first vertex is already included in MST.
	 */
	
	for (int count = 0; count < N - 1; count++) {
		
		
		int u = minKey(key, mstSet,N);

		
		mstSet[u] = true;

		
		for (int v = 0; v < N; v++)

			
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printMST(parent, N);
}

// Driver's code
int main()
{	 FILE * ptr= fopen("testMatrix.txt","r");
    if(ptr==NULL) {
        printf("File does not exist\n");
        exit(1);
    }
    int V;
    fscanf(ptr,"%d",&V);

    int n;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(fscanf(ptr,"%d",&n)!=EOF){
                graph[i][j]=n;
            }
            else{
                printf("File Terminated Unexpectedly\n");
                fclose(ptr);
                exit(1);
            }
        }
    }
    fclose(ptr);

    // Displaying the received adjacency matrix
    printf("%d\n",V);
    displayArr(V);


	primMST(V);


	return 0;
}
