// Didn't include <stdio.h> as it is already included in queue.c
#include "cQueue_bfs.c"      // For including local files, we use " " instead of < >


int graph[MAX][MAX];       // MAX is defined in queue program


void displayArr(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void bfs(){
    int visited[MAX];
    for (int i = 0; i < MAX; i++)
    {
        visited[i]=0;
    }
    
    int startInd=0;
    visited[startInd]=1;
    enQueue(startInd);

    while (!isEmpty())
    {
        int node= deQueue();
        printf("%d\t",node);

        for(int i=0;i<MAX;i++){
            if(graph[node][i]&& !visited[i]){
                visited[i]=1;
                enQueue(i);
            }
        }
    }
    
    printf("\n");    
}


int main(){

/* Reading the file */   

    FILE * ptr= fopen("testMatrix.txt","r");
    if(ptr==NULL) {
        printf("File does not exist\n");
        return 1;
    }
    int n;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(fscanf(ptr,"%d",&n)!=EOF){
                graph[i][j]=n;
            }
            else{
                printf("File Terminated Unexpectedly\n");
                fclose(ptr);
                return 1;
            }
        }
    }
    fclose(ptr);

/* Displaying the Received Adjacency Matrix */

    displayArr();

/* Calling BFS function */
    printf("The Breadth First Search Traversal of the graph looks like\t");
    bfs();
    return 0;
}

/* 

Time Complexity (Adjacency Matrix) :
----------------------------------

    For the first iteration:

        Before reaching the for loop, we perform a constant time operation dequeue() --> O(1) , This will be executed each time we enter While loop
        Now, the for loop will execute for 5 times (i.e. the number of vertices)

        Total --> (1+5)

    Similarly, for other iterations it will look like:

    (1+5)+(1+5)+(1+5)+(1+5)+(1+5)           //As total 5 vertices are there, and for each vertex the while loop will run once

    (5+5*5)

    (N+N*N)  --> O(N^2)                     // N is the number of vertices



Time Complexity (Adjacency List):
---------------------------------

    This is how nodes are connected(assuming undirected graph) :

        0 -> 1 ,2, 3
        1 -> 0
        2 -> 0,  4
        3 -> 0
        4 -> 2
        So, total no. of edges = E = 4

    For first while loop , 
    node = 0,   edges = 3
    Now, before going to the for loop part, u see a constant time operation O(1)  --> deQueue( )
    This step will be executed every time we enter into while loop.

    So, for first while loop how many times for loop will execute ??
    It will be equal to the no. of edges , here it will be 3.

    Therefore, total =  ( 1 + 3 )

    Similarly for all other nodes, this is how it will look :
    ( 1 + 3 )  + ( 1 + 1 ) + ( 1 + 2 ) + ( 1 + 1 ) + ( 1 + 1 )
    =   13  
    =   O ( V  +  2 * E )  
    =   O ( 5  +  2  * 4 )

 */