#include<bits/stdc++.h>
using namespace std;

// defining variables for ease
#define Size 3 // length of the box

string capitaliseString(string name){
        
    transform(name.begin(), name.end(), name.begin(), ::tolower); // applying tolower function to each element and storing it back in the name using transform(STL)
    name[0] = toupper(name[0]);
    return name;

}

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
    cout<<"\n--\t--\t--\t--\t--\t--\t--\t--\t--\t--\n";

}

void showInstructions(){
    cout<<"\nPlayer has to choose a cell numbered from 1 to 9 as below to play\n\n";
      
    cout<<"\t\t   |   |   \n";
    cout<<"\t\t 1 | 2 | 3 \n";
    cout<<"\t\t___|___|___\n";
    cout<<"\t\t   |   |    \n";
    cout<<"\t\t 4 | 5 | 6  \n";
    cout<<"\t\t___|___|___\n";
    cout<<"\t\t   |   |    \n";
    cout<<"\t\t 7 | 8 | 9  \n";
    cout<<"\t\t   |   |    \n";
      
    cout<<"\n--\t--\t--\t--\t--\t--\t--\t--\t--\t--\n\n";
}

void initialiseGame(char box[][Size]){

    for(int i=0;i<Size;i++)
        for(int j=0;j<Size;j++)
            box[i][j]=' ';            // initialise the positions of the box with blank spaces
    
}

void specialStyle(){                  // special style message 
    cout << R"(
              _____ ____  _   _  _____ _____         _______ _    _ _            _______ _____ ____  _   _  _____ 
             / ____/ __ \| \ | |/ ____|  __ \     /\|__   __| |  | | |        /\|__   __|_   _/ __ \| \ | |/ ____|
            | |   | |  | |  \| | |  __| |__) |   /  \  | |  | |  | | |       /  \  | |    | || |  | |  \| | (___  
            | |   | |  | | . ` | | |_ |  _  /   / /\ \ | |  | |  | | |      / /\ \ | |    | || |  | | . ` |\___ | 
            | |___| |__| | |\  | |__| | | \ \  / ____ \| |  | |__| | |____ / ____ \| |   _| || |__| | |\  |____) |
             \_____\____/|_| \_|\_____|_|  \_\/_/    \_\_|   \____/|______/_/    \_\_|  |_____\____/|_| \_|_____/ 
            )" << "\n";
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

void announceWinner(string turn, string player1, string player2){
    
    cout<<"\n\n";
    specialStyle();        // special style congratulations is displayed
    cout<<"\n\n";

    if(turn == player1)   cout<<"\t\t\t\t\t"<<player1<<" has won! \n\n\n\n";     // the player with current turn will be the winner (turn has been toggled)
    else    cout<<"\t\t\t\t\t"<<player2<<" has won! \n\n\n\n";

}

int invalidChoice(int &choice){
    while(choice<1 || choice>9){         // in case the choice is not from 1-9 then handling the situation
        cout<<"Invalid Move! Try again. ( you have to choose a cell from 1 to 9 ) \t";
        cin>>choice;
    }
    return choice;
}

void repeatChoice(map<int,string> mpp, int &choice){          // in case the player makes a repetitive move that is already used by a player
    
    while(mpp.count(choice)==1){                              // if the choice exists then the count will be 1 as it is not a multimap
        auto it=mpp.find(choice);                             // the type is automatically identified using auto
        cout<<"\n"<<it->second<<" has already used that move. Try something else!\t";          // using it->second will give the value of the key pointed by iterator
        cin>>choice;
    }
}


int updateBox(int &playerMove, char box[][Size], char &player1Move, char &player2Move){
    char currentMove;
    static int count=1;     // to identify which type of move ( X / O ) should be displayed

    if(count%2==0)  currentMove= player2Move;   
    else    currentMove= player1Move; 
        switch(playerMove){                                  // changing the value at the location according to the parameters
        case 1: box[0][0] = currentMove; count++; break;
        case 2: box[0][1] = currentMove; count++; break;
        case 3: box[0][2] = currentMove; count++; break;
        case 4: box[1][0] = currentMove; count++; break;
        case 5: box[1][1] = currentMove; count++; break;
        case 6: box[1][2] = currentMove; count++; break;
        case 7: box[2][0] = currentMove; count++; break;
        case 8: box[2][1] = currentMove; count++; break;
        case 9: box[2][2] = currentMove; count++; break;
        default:
                ;// do nothing as this will not execute at any condition since it is already checked using invalidChoice()
        }
}

void playTicTacToe(string player1, string player2, char &player1Move, char &player2Move){
    char box[Size][Size]; // the size of the playing box

    // initialise the game
    initialiseGame(box);

    // showing the instructions
    showInstructions();

    // for soting key value pairs of the move & the player that used that move to check for repetition
    map<int, string> mpp;       

    int movePos{0}, choice;       // choice is for storing the position at which the user wishes to play
    string playerTurn = player1;  // player1 will play the first move
    
    while(gameOver(box) == false && movePos!=Size*Size){     // limiting the game to 9 moves

        if(playerTurn == player1){
            
            cout<<"\n"<<player1<<" please type the position:   ";
            cin>>choice;                                                    // the position at which player wants to play (1-9)
            choice=invalidChoice(choice);                                   // handling the case if the input value is not in the range
            if(movePos>0)  repeatChoice(mpp, choice);                       // ignoring first time the repetition is checked for the input
            updateBox(choice, box, player1Move, player2Move);               // updating the box with the value at the corresponding location
            cout<<"\n"<<player1<<" has put a "<<player1Move<<" at the position "<<choice<<"\n";
            mpp.insert({choice, player1});                                  // inserting in map where choice is the key & player name is the value
            printBox(box);                                                  // displaying Box
            movePos++;                                                      
            playerTurn= player2;
            

        }else if(playerTurn == player2){

            cout<<"\n"<<player2<<" please type the position:   ";
            cin>>choice;
            choice=invalidChoice(choice);
            repeatChoice(mpp, choice);
            updateBox(choice, box, player1Move, player2Move);
            cout<<"\n"<<player2<<" has put a "<<player2Move<<" at the position "<<choice<<"\n";
            mpp.insert({choice, player2});
            printBox(box);
            movePos++;
            playerTurn= player1;
        }
    }
    // to check the draw condition
    if(gameOver(box) == false && movePos==Size*Size)    cout<<"\nIt's a DRAW!!\n";
    else{
        // toggling the user to find the actual winner (since playerTurn is shifted to the different player in the above loops at the end)
        if (playerTurn == player1) playerTurn = player2;
        else if (playerTurn == player2) playerTurn = player1;
        // announcing the winner
        announceWinner(playerTurn, player1, player2);
    }

}

int main()
{  
    cout<<"\n\n============================ Welcome to TIC TAC TOE  Game ============================\n\n";
    cout<<"                                 2 Players                                  \n\n";

    string player1, player2;
    cout<<"Enter the name of player 1 (player 1 will play first move)                         \t";
    cin>>player1;
    cout<<"Enter the name of player 2 (player 2 will be the one to choose preferred piece(X/O)\t";
    cin>>player2;

    if(!player1.empty() && !player2.empty()){
        player1= capitaliseString(player1);                  // function to make the first letter of the string captial and rest of them lowercase
        player2= capitaliseString(player2);
    }else{
        cout<<"The name entered is invalid!\nRestart the Game.\n";
        return 0;
    }

    char player1Move{'O'}, player2Move{'X'};
    do{
        cout<<"\n"<<player2<<" please select the character from which you wish to play: X / O \n";
        cin>>player2Move;
        player2Move=toupper(player2Move);                               // transforming the character to uppercase

        if(player2Move!='O' && player2Move!='X')    cout<<"\nWrong Character! Please try again: \n";
        else if(player2Move=='O')   player1Move='X';       // we don't need to check other condition due to the initialised values

    }while(player2Move!='O' && player2Move!='X');      
    
    
    cout<<"\n"<<player1<<" will play with "<<player1Move<<"\n";
    cout<<player2<<" will play with "<<player2Move<<"\n\n"; 
    
    // main driving function
    playTicTacToe(player1, player2, player1Move, player2Move);

    return 0;
}
   

    
    

