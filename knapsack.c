// Reference: https://youtu.be/oTTzNMHM05I

#include <stdio.h>

// creating a structure to store the relevant info about a single product
struct Item{ 
    int price;
    int weight;
    double pw_Ratio;
};

void sort(struct Item * ptr,int length){
    for (int i = 0; i < length-1; i++)
    {
        int isSwapped=0;
        for (int j = 1; j < length-i; j++)
        {
            if(ptr[j].pw_Ratio>ptr[j-1].pw_Ratio){
                struct Item temp= ptr[j-1];
                ptr[j-1]=ptr[j];
                ptr[j]=temp;
                isSwapped=1;
            }
        }
        if(!isSwapped){
            break;
        }
        
    } 
}

void display(struct Item * ptr,int length){     // This is for displaying the struct array
    printf("\n\n");
    for (int i = 0; i < length; i++)
    {
        printf("item %d price --> %d, weight --> %d, price_weight ratio is --> %0.2lf\n",i+1,ptr[i].price,ptr[i].weight,ptr[i].pw_Ratio);
    }
    printf("\n\n");
    
}

double knapSack(struct Item * ptr, int capacity,int length){
    int curWeight=0;
    double profit=0;
    
    for (int i = 0; i < length; i++)                // Execute the loop for n times
    {
        if(ptr[i].weight+curWeight<=capacity){      // If possible, put the entire item in knapsack and update the weight and profit
            curWeight+=ptr[i].weight;
            profit+=ptr[i].price;
            printf("Put %d units of item worth Rs.%d in knapsack, remaining capacity %d\n",ptr[i].weight,ptr[i].price,capacity-curWeight);
        }
        else{                                       // Otherwise, calculate the remaining capacity of knapsack and add that much only. Also, update the profit 
            int remCapacity= capacity-curWeight;
            profit+= ((double) remCapacity/ptr[i].weight)*ptr[i].price;
            printf("Put %d units of item worth Rs.%d in knapsack, remaining capacity 0\n",remCapacity,ptr[i].price);
            break;                                  // At this part, the knapsack is full, so break the loop
        }
    }
    return profit;
    
}


int main(){
    // user input
    int products,capacity;
    printf("Enter the total number of products\n");
    scanf("%d",&products);
    printf("Enter the capacity of knapsack\n");
    scanf("%d",&capacity);
    struct Item arr[products];              // creating an array of struct Item
    for (int i = 0; i < products; i++)
    {
        printf("Enter the price and weight of item %d separated by a space\n",i+1);
        scanf("%d %d",&arr[i].price,&arr[i].weight);
        arr[i].pw_Ratio=(double)arr[i].price/arr[i].weight;
    }
    
    // sorting the received data
    sort(arr,products);

    // display the sorted items
    // display(arr,products);

    //calling the function
    printf("\nGained Profit will be Rs. %0.2lf\n\n",knapSack(arr,capacity,products));
   
    return 0;
}