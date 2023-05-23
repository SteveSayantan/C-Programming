#include <stdio.h>

struct Edge{
    int wt;
    int u; 
    int v;         // u and v are the two adjacent vertices of an edge
};


void sort_edges(struct Edge arr[],int length){
    for (int i = 0; i < length-1; i++)
    {
        int isSwapped=0;
        for (int j = 1; j < length-i; j++)
        {
            if(arr[j].wt < arr[j-1].wt){
                struct Edge temp= arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
                isSwapped=1;
            }
        }
        if(!isSwapped){
            break;
        }
        
    } 
}
int findParent(int ind,int parent_arr[]){
    if(ind==parent_arr[ind]){
        return parent_arr[ind];
    }
    return parent_arr[ind]=findParent(parent_arr[ind],parent_arr);              // Path Compression to avoid extra function calls for searching ultimate parents
}

void unionByRank(int par_ind1,int par_ind2,int rank_arr[],int parent_arr[]){

    if(rank_arr[par_ind1]>rank_arr[par_ind2]){
        parent_arr[par_ind2]=par_ind1;     
    }
    else if(rank_arr[par_ind1]<rank_arr[par_ind2]){
        parent_arr[par_ind1]=par_ind2;     
    }
    else{
        parent_arr[par_ind2]=par_ind1; 
        rank_arr[par_ind1]++;
    }
    
}
int kruskal(struct Edge arr[],int parent_arr[],int rank_arr[]){

    struct Edge mstArr[9];          // This will store the edges included in mst
    int minWeight=0, mstPtr=0;      

    for (int i = 0; i < 9; i++)
    {
        int par_u=  findParent(arr[i].u,parent_arr);
        int par_v=  findParent(arr[i].v,parent_arr);

        if(par_u!=par_v){
            unionByRank(par_u,par_v,rank_arr,parent_arr);
            minWeight+=arr[i].wt;
            mstArr[mstPtr++]=arr[i];
        }
    }

    for (int i = 0; i <6-1; i++)                // This will execute for N-1 times
    {
        printf("%d -- %d -> %d\n",mstArr[i].u,mstArr[i].v,mstArr[i].wt);
    }
    
    return minWeight;
    
}


int main(){
    struct Edge temp[]={ 
                        {1,0,3},
                        {2,0,1},
                        {3,1,2},
                        {3,1,3},
                        {4,0,4},
                        {5,2,3},
                        {7,1,5},
                        {8,2,5},
                        {9,3,4}
                        };
    int parent[]={0,1,2,3,4,5};
    
    int rank[6]={0};
    sort_edges(temp,9);
    printf("%d",kruskal(temp,parent,rank));
    
    return 0;
}

/* 
    References:
    ----------
        1. https://youtu.be/KxLtIrCyXwE (Love Babbar)
        2. https://youtu.be/aBxjDBC4M1U (Striver Disjoint Set)
        3. https://youtu.be/DMnDM_sxVig (Striver Kruskal)
        4. https://youtu.be/wU6udHRIkcc (Abdul Bari)

    Approach:
    ---------
    Initially, all the vertices are parents of themselves and rank of each vertex is 0 .

    Now , we sort the edge list in ascending order. 

    1) In the first step, we take the first edge in the sorted list and find the ultimate parents of its two adjacent vertices (i.e. u and v)
    
    2) For different ultimate parents, if the ultimate parents are equal in rank, mark the first vertex as the ultimate parent of the second one and increment the rank of the first ultimate parent (or vice-versa)
        Otherwise, the ultimate parent with higher rank should be marked as ultimate parent but no change in rank. 
       For same ultimate parents, just ignore.

    3) Add the weight of the edges.

    Repeat these steps for every edge in the edge list.

    Rank
    -----
    It represents how many times a vertex-edge set has been merged with a vertex-edge set of same rank.
    Greater the rank, deeper the vertex-edge tree. That is why a vertex-edge set with lower rank is added under the same with higher rank.
    For further clarification, refer to the videos.
 */