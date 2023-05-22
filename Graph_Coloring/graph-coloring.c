#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int G[10][10],m,n,c=1,check=0;
int X[10]={0};

void display()
{
    printf("\n\nSolution %d : ",c++);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",X[i]);
        if(X[i]>0)
            check++;
    }
}

void nextValue(int k)
{
    int j;
    do
    {
        X[k]=(X[k]+1)%(m+1);            // X[k] can have values upto m, therefore we have taken (m+1)
        if(X[k]==0)
            break;

        for(j=1;j<=k-1;j++)             // k-1 assures that we only check the previous adjacent vertices, not all of them
            if(G[k][j]==1 && X[k]==X[j])
                break;

        if(j==k)
        // This means there is no conflict with adjacent vertices
            break;                      
    } while (true);
}

void mColoring(int k)
{
    do
    {
        nextValue(k);
        if(X[k]==0)
            break;
        
        if(k==n)
            display();
        else
            mColoring(k+1);
    } while(true);
}

int main()
{
    FILE *fp;
    fp=fopen("color.txt","r");
    if(fp==NULL)
    {
        printf("\nError in opening the file !\n");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(fp,"%d",&G[i][j]);

    printf("\n   -------- GRAPH COLORING --------\n\n");
    printf("\nEnter the number of colours : ");
    scanf("%d",&m);
    if(m>=1)
    {
        mColoring(1);
        if(check==0)
            printf("\n\nSorry.The graph needs more than %d colour(s) for proper coloring.",m);
    }
    else
    printf("\nInvalid Input.");
    return 0;
}

/* 
    Approach:
    ---------

        mColoring(vertex):
        ------------------
            It takes a vertex as input. First, it checks if a color can be assigned to this vertex by calling nextValue function. 
            After a color is assigned, if current vertex is the last vertex, it calls the display function. Otherwise, it recursively calls itself for the next vertex.

            If it can not assign any color to the current vertex by calling nextValue function, it backtracks to its parent function and changes the color value assigned to corresponding node. 
            This process is repeated until we get all possible combinations.

        nextValue(vertex):
        -----------------
            It assigns a color to the vertex taken as i/p. If the adjacent vertices of the current vertex have any conflict with the color applied,
            it increments the color and checks again for any conflict.
            

 */