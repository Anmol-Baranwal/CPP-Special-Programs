#include<bits/stdc++.h>
using namespace std;

// Important:=>  To understand in detail, use debugger and see the step-wise execution of the program

bool checkSafe(int** arr, int x, int y, int n){        // this function checks whether the current position is safe for the queen or not
    
    // check rows on the above sides
    for(int row=0;row<x;row++)                         // row & col is used for the ease of the understanding
        if(arr[row][y]==1)    return false;            // column is same for the check

    // checking upper left diagonal
    for(int row=x,col=y;row>=0 && col>=0;row--,col--)
        if(arr[row][col]==1)  return false;

    // checking upper right diagonal
    for(int row=x,col=y;row>=0 && col<n;row--,col++)        
        if(arr[row][col]==1)  return false;

    return true;                                       // if above statements didn't execute then the move is completely safe and function returns true
}

bool nQueen(int** arr, int x, int n){            // 2d array is passed like this & initial value of x is 0 i.e. 1st column of the board
    if(x==n)  return true;                       // n queens are placed at the corresponding columns 

    for(int col=0;col<n;col++){                  // for every {[column]} we are checking whether the move is safe or not
        if(checkSafe(arr, x, col, n)){           // if the move is safe then we have to mark that position as 1
            arr[x][col]=1;

            if(nQueen(arr, x+1, n))  return true; // call recursively and find whether there is a safe solution for upcoming queens in the further columns                     
            
            arr[x][col]=0; // backtracking         if upcoming queen cannot be placed safely then we backtrack the solution and change our previous queen to next position.... it continues on
        }   
    }
    return false;                                 // if there is no solution the the function returns false
}

int main()
{
    cout<<"\n\n============================ Welcome to NQueen Problem ============================\n\n";
    int n=4;


    int** arr=new int*[n];                                  // dynamic memory allocation of 2D array
    for(int i=0;i<n;i++){                                   
        arr[i]=new int[n];                                  // initialising the elements of 2d array to 0
        for(int j=0;j<n;j++)                                         
            arr[i][j]=0;
    }

    if(nQueen(arr,0,n)){                                     // driver function if this is true then the solutions are printed otherwise the program is terminated
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
             
    }

    return 0;
}



























