#include<bits/stdc++.h>
using namespace std;

// Important:=>  To understand in detail, use debugger and see the step-wise execution of the program

void displayBoard(vector<vector<int>> board, int n){       // displaying the board
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<" "<<setw(2)<<board[i][j]<<" ";              
        cout<<"\n";
    }     
}

bool checkSafe(vector<vector<int>> board, int row, int col, int n){
    

    for(int i=0;i<col;i++)
        if(board[row][i]==1)    return false;               

    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j]==1)  return false;

    for(int i=row,j=col;i>=0 && j<n;i--,j++)                
        if(board[i][j]==1)  return false;

    return true;
}

bool solveQueen(vector<vector<int>> &board, int col, int n){           // 2d vector passed by reference & col is initially set to 0 
    if(col==n)  return true;                                           // if we have reached the last column that means the solution has been found and it returns true

    for(int i=0;i<n;i++){                                              // for every {[column]} we are checking whether the move is safe or not
        if(checkSafe(board, i, col, n)){                               // if the move is safe then we have to mark that position as 1
            board[i][col]=1;

            cout<<"\nQueen is placed\n\n";
            displayBoard(board, n);
            cout<<"\n\n";

            if(solveQueen(board, col+1, n)) return true;               // call recursively and find whether there is a safe solution for upcoming queens in the further columns
            
            board[i][col]=0;   // backtracking                            if upcoming queen cannot be placed safely then we backtrack the solution and change our previous queen to next position.... it continues on
            cout<<"\nBacktracking occurs\n\n";
            displayBoard(board, n);
            cout<<"\n\n";
        }
    }
    return false;                                                      // if there is no solution the the function returns false
}

bool nQueen(int n){
    vector<vector<int>> board;                // 2d vector

    for(int i=0;i<n;i++){                     // initialising the 2d vector to 0 upto board_size*board_size
        vector<int> currVec;
        for(int j=0;j<n;j++)
            currVec.push_back(0);
        board.push_back(currVec);
    }

    if(solveQueen(board, 0, n)==false){                         // 0 is passed as column so we start from the first column
        cout<<"\nSolution doesn't exist!!\n";
        return false;
    }                  
    displayBoard(board, n);            // if above if section didn't execute that means we have found the solution thus displaying
    return true;  


}

int main()
{
    cout<<"\n\n============================ Welcome to NQueen Problem ============================\n\n";
    int n=4;
    cout<<"Enter the size of the board: \t";      // the size of the board accross which solutions will be found
    cin>>n;
    nQueen(n);                                    // driver function
    
    return 0;

}

















