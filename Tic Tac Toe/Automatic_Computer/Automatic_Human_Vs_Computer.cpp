#include<bits/stdc++.h>
using namespace std;

// defining variables for ease
#define Size 3 // length of the box
#define Human 2
#define Computer 1
#define computerMove 'O' // computer will play with O
#define humanMove 'X'    // human will play with X


void printBox(char box[][Size]){      // this concept is known as row major implementation i.e. no need to specify the row size

    cout<<"\n";
    cout<<"\t\t   |   |   \n";
    cout<<"\t\t "<<box[0][0]<<" | "<<box[0][1]<<" | "<<box[0][2]<<"\n";
    cout<<"\t\t___|___|___\n";
    cout<<"\t\t   |   |    \n";
    cout<<"\t\t "<<box[1][0]<<" | "<<box[1][1]<<" | "<<box[1][2]<<"\n";
    cout<<"\t\t___|___|___\n";
    cout<<"\t\t   |   |    \n";
    cout<<"\t\t "<<box[2][0]<<" | "<<box[2][1]<<" | "<<box[2][2]<<"\n";
    cout<<"\t\t   |   |    \n";

}

void showInstructions(){
    // cout<<"\nChoose a cell numbered from 1 to 9 as below to play\n\n";
      
    cout<<"\t\t   |   |   \n";
    cout<<"\t\t 1 | 2 | 3 \n";
    cout<<"\t\t___|___|___\n";
    cout<<"\t\t   |   |    \n";
    cout<<"\t\t 4 | 5 | 6  \n";
    cout<<"\t\t___|___|___\n";
    cout<<"\t\t   |   |    \n";
    cout<<"\t\t 7 | 8 | 9  \n";
    cout<<"\t\t   |   |    \n";
      
    cout<<"\n--\t--\t--\t--\t--\t--\t--\t--\t--\t--\n\n\n";
}

void initialiseGame(char box[][Size], int moves[]){

    srand(time(NULL));  //  using rand will give the same random number so this is preferred to make it random

    for(int i=0;i<Size;i++)
        for(int j=0;j<Size;j++)
            box[i][j]=' ';
    
    // initialise the moves & shuffling it using shuffle
    for(int i=0;i<Size*Size;i++)
        moves[i]=i;

    // unsigned rnd = 0;
    // shuffle(moves, moves+Size*Size, default_random_engine(rnd));        // one way to do the shuffling

    unsigned num = chrono::system_clock::now().time_since_epoch().count();
    shuffle (moves, moves+Size*Size, default_random_engine(num));   
    
}

// this will check the row of the same player's move & returns true if any row is crossed
bool rowCheck(char box[][Size]){     
    for(int i=0;i<Size;i++)
        if((box[i][0] == box[i][1]) && (box[i][1] == box[i][2]) && box[i][0]!=' ')    return true;  // top to bottom
    return false;
}

// this will check the column of the same player's move & returns true if any column is crossed
bool columnCheck(char box[][Size]){
    for(int i=0;i<Size;i++)
        if((box[0][i] == box[1][i]) && (box[1][i] == box[2][i]) && box[0][i]!=' ')    return true;  // left to right
    return false;
}

// this will check the diagonal of the same player's move & returns true if any diagonal is crossed
bool diagonalCheck(char box[][Size]){
        if((box[0][0] == box[1][1]) && (box[1][1] == box[2][2]) && box[0][0]!=' ')    return true;  // top-left to bottom-right
        if((box[0][2] == box[1][1]) && (box[1][1] == box[2][0]) && box[0][2]!=' ')    return true;  // bottom-left to top-right

        return false;
}


// returns false if the game is not over else rturns true
bool gameOver(char box[][Size]){ 
    return( rowCheck(box) || columnCheck(box) || diagonalCheck(box));  // all three conditions are checked to see whether the game is over
                                                                       // each funtion returns true if anything is crossed so even if one condition is true then the game is over
}

void announceWinner(int turn){
    if(turn == Human)   cout<<"\nThe human has won! Congratulations!!\n\n";
    else    cout<<"\nThe Computer has won! Congratulations!!\n\n";

}

void playTicTacToe(int playerTurn){
    char box[Size][Size]; // the size of the playing box

    int moves[Size*Size]; // total number of moves for which the game will be played

    // initialise the game
    initialiseGame(box, moves);

    // showing the instructions
    showInstructions();

    int movePos{0}, x, y;
    
    while(gameOver(box) == false && movePos!=Size*Size){     // limiting the game to 9 moves

        if(playerTurn == Computer){
            
            x=moves[movePos] % Size;  
            y=moves[movePos] / Size;    // we cannot use the same method with above line because we need different numbers for the box location
            box[y][x]=computerMove;
            cout<<"\nComputer has put a "<<computerMove<<" at the position "<<moves[movePos]+1<<"\n";
            printBox(box);
            movePos++;
            playerTurn=Human;

        }else if(playerTurn == Human){

            x=moves[movePos] % Size;  
            y=moves[movePos] / Size;    
            box[y][x]=humanMove;
            cout<<"\nHuman has put a "<<humanMove<<" at the position "<<moves[movePos]+1<<"\n";
            printBox(box);
            movePos++;
            playerTurn=Computer;

        }
    }
    // to check the draw condition
    if(gameOver(box) == false && movePos==Size*Size)    cout<<"\nIt's a DRAW!!\n";
    else{
        // toggling the user to find the actual winner (since playerTurn is shifted to the different player in the above loops at the end)
        if (playerTurn == Computer) playerTurn = Human;
        else if (playerTurn == Human) playerTurn = Computer;
        // announcing the winner
        announceWinner(playerTurn);
    }

}

int main()
{

    cout<<"\n\n============================ Welcome to TIC TAC TOE  Game ============================\n\n";
    cout<<"                                 Human  Vs  Computer                                  \n\n";

    // human will start the game
    playTicTacToe(Human);

    return 0;
}



