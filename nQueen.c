#include <stdio.h>
#include <stdbool.h>

int boardSize=5, board[5][5]={false};

bool isSafe(int row, int col){

    // check all the rows for given col
    for (int i = 0; i < row; i++)
    {
        if(board[i][col]){
            return false;
        }
    }

    // check the diagonal right
    int maxRight= row < (boardSize-col-1) ? row:(boardSize-col-1);
    for (int i = 1; i <=maxRight; i++)
    {
        if(board[row-i][col+i]){
            return false;
        }
    }

    // check the diagonal left
    int maxLeft= row < col ? row:col;
    for (int i = 1; i <=maxLeft; i++)
    {
        if(board[row-i][col-i]){
            return false;
        }
    }

    return true;
    
}

void displayBoard(){
    for (int row = 0; row < boardSize; row++){

        for (int col = 0; col < boardSize; col++)
        {
            if(board[row][col]){
                printf("Q ");
            }
            else{
                printf("_ ");
            }
        }
        printf("\n");       
    }
    
}

int nQueen(int row){

    if(row==boardSize){                                 // it indicates that we have successfully placed queens
        displayBoard();                                 // display the solution
        printf("\n");
        return 1;
    }

    int count=0;
    for (int col = 0; col < boardSize; col++){          // Checking all the cols for a particular row

        if(isSafe(row,col)){                            // If this place is safe  

            board[row][col]=true;                       // put a Queen
            count+=nQueen(row+1);                       // look for the next possible location at the next row
            board[row][col]=false;                      // before tracking back to parent function, discard the queen
        }
    }
    return count;
}

int main(){
    printf("There are %d ways",nQueen(0));
    return 0;
}