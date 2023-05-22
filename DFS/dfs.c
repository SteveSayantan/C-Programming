#include "stack-dfs.c"

int graph[10][10];

void displayArr(int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

void dfs(int N){

    int visited[10]={0};
  
    int startNode=2;
    visited[startNode]=1;
    push(startNode);

    while(!isEmpty()){
        int node= pop();
        printf("%d\t",node);

        for(int i=0;i<N;i++){
            if(graph[node][i] && !visited[i]){
                visited[i]=1;
                push(i);
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

    // Calling DFS function
    printf("The DFS of given graph looks like:\t");
    dfs(V);
    return 0;
}
/* 
Reference: https://youtu.be/4M1u4-eGlxU 

Time Complexity (Adjacency Matrix) :
----------------------------------

    For the first iteration:

        Before reaching the for loop, we perform a constant time operation dequeue() --> O(1) , This will be executed each time we enter While loop
        Now, the for loop will execute for 5 times (i.e. the number of vertices)

        Total --> (1+5)

    Similarly, for other iterations it will look like:

    (1+5)+(1+5)+(1+5)+(1+5)+(1+5)           //As total 5 vertices are there, and for each vertex the while loop will run once

    (5+5*5)

    (V+V*V)  --> O(V^2)                     // V is the number of vertices



Time Complexity (Adjacency List):
---------------------------------

    This is how nodes are connected(assuming undirected graph) :

        0 -> 1 ,2, 3
        1 -> 0
        2 -> 0,  4
        3 -> 0
        4 -> 2
        So, total no. of edges, E = 4

    For first while loop , 
    node = 0,   edges = 3
    Now, before going to the for loop part, u see a constant time operation O(1)  --> deQueue( )
    This step will be executed every time we enter into while loop.

    So, for first while loop how many times for loop will execute ??
    It will be equal to the degree of node 0 , i.e. 3

    Therefore, total =  ( 1 + 3 )

    Similarly for all other nodes, this is how it will look :
    ( 1 + 3 )  + ( 1 + 1 ) + ( 1 + 2 ) + ( 1 + 1 ) + ( 1 + 1 )
    =   13  
    =   O ( V  +  2 * E )  
    =   O ( 5  +  2  * 4 )

 */