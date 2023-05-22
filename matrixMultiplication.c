#include <stdio.h>

int dim_Arr[10];
int cost_Arr[10][10]={0};
int k_Arr[10][10]={0};

int multiplyMatrix(int N){              // Refer to the lectures for detailed explanation

    for (int diff = 1; diff <= N-1; diff++)         
    {
        
        for (int i = 1; i <= N-diff ; i++)
        {
            int j= diff+i;
            int min= __INT_MAX__;


            for (int k = i; k<j ; k++)  // Try all the possible ways for different values of k
            {
                int q= cost_Arr[i][k]+cost_Arr[k+1][j]+ dim_Arr[i-1]*dim_Arr[k]*dim_Arr[j];

                // store the minimum value 
                if(q<min){
                    min=q;
                    k_Arr[i][j]=k;
                }
            }
            cost_Arr[i][j]=min;           
        }
        
    }
    
    return cost_Arr[1][N];
}

void displayResult(int i, int j)
{
    if (i == j)
    {
        printf("%c",'A' + i-1) ;            // As our calculation is 1 index based, we have to subtract 1
    }
    else
    {
        printf("(");
        displayResult(i, k_Arr[i][j]);
        displayResult(k_Arr[i][j] + 1, j);
        printf(")");
    }
}
int main(){

    int N;
    printf("Enter the number of matrices to be multiplied:\n");
    scanf("%d",&N);

    printf("Enter the %d dimensions separated by a space\n",N+1);
    for (int i = 0; i < N+1; i++)
    {
        scanf("%d",dim_Arr+i);
    }

    printf("%d\n",multiplyMatrix(N));
    displayResult(1,N);
    printf("\n");
    return 0;
}

/* 
    Reference: https://youtu.be/_WncuhSJZyA (Part 1) and https://youtu.be/eKkXU3uu2zk (Part 2)

    Total calculations required to multiply matrices from i to j are, Cost_Arr[i,j]= Min( Cost_Arr[i,k] + Cost_Arr[k+1,j] + Dim_Arr[i-1]*Dim_Arr[k]*Dim_Arr[j] ) , where i<=k<j

        E.g., Total calculations required to multiply 3 matrices (i.e. from 1 to 3) are, Cost_Arr[1,3]= Min( Cost_Arr[1,k]+ Cost_Arr[k+1,3] + Dim_Arr[0]*Dim_Arr[k]*Dim_Arr[3] ) , where 1<=k<3
        We have to calculate this for k=1 & 2


 */