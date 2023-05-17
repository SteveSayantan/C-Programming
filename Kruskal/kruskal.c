#include <stdio.h>

struct Edge{
    int wt,u,v;
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
    return parent_arr[ind]=findParent(parent_arr[ind],parent_arr);
}
void unionByRank(int ind1,int ind2,int rank_arr[],int parent_arr[]){
    
    int par_ind1= findParent(ind1,parent_arr);
    int par_ind2= findParent(ind2,parent_arr);

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
    int minWeight=0;
    for (int i = 0; i < 5; i++)
    {
        int par_u=  findParent(arr[i].u,parent_arr);
        int par_v=  findParent(arr[i].v,parent_arr);

        if(par_u!=par_v){
            unionByRank(arr[i].u,arr[i].v,rank_arr,parent_arr);
            minWeight+=arr[i].wt;
        }
    }
    return minWeight;
    
}

int main(){
    struct Edge temp[]={ { 4,2, 3},
                        {6, 0, 2 },
                        { 5,0, 3},
                       { 15,1, 3},
                        {10, 0, 1},
                        
                       };
    int parent[]={0,1,2,3};
    
    int rank[4]={0};
    sort_edges(temp,5);
    printf("%d\n",kruskal(temp,parent,rank));
    return 0;
}

/* 
    References:
    ----------
        1. https://youtu.be/KxLtIrCyXwE (Love Babbar)
        2. https://youtu.be/aBxjDBC4M1U (Striver Disjoint Set)
        3. https://youtu.be/DMnDM_sxVig (Striver Kruskal)
        4. https://youtu.be/wU6udHRIkcc (Abdul Bari)



 */