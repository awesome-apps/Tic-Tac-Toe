#include <iostream> //General Foundation
#include <math.h>   //Math Functions
#include <cstdlib>  //Random Numbers
#include <string>   //String Objects
using namespace std;    //Standard Namespace
//I am working on networking so that you can play with other players over network: But C++ Networking is hella complicated so... gonna take a while
char board[] = {'0' ,'1', '2', '3', '4', '5', '6', '7', '8'};   //All board positions
void display_board(){   //Stored in function to repeatedly display updated boards for each move
    for(int i = 0; i < 9; i += 3){
        cout << board[i];
        cout << board[i+1];
        cout << board[i+2] << endl;
    }
}
bool checkRows(char letter){    //Checking the Rows to see if anyone won the game by completing a row
    //Row Checking Loop
    bool somebodyWon = false;
    for(int i = 0; i < 9; i += 3){
        if(board[i] == letter && board[i+1] == letter && board[i+2] == letter){
            somebodyWon = true;
            break;
        }
    }
    return somebodyWon;
}
bool checkColumns(char letter){ //Checking the Columns to see if anyone won the game by completing it
    //Columns Checking Loop
    bool somebodyWins = false;
    for(int i = 0; i <= 2; i++){
        if(board[i] == letter && board[i + 3] == letter && board[i+6] == letter){
            somebodyWins = true;
            break;
        }
    }
    return somebodyWins;
}
bool checkDiagonals(char letter){   //Check Diagonal Wins
    //Diagonals: Just Conditionals
    bool someBodyWins = false;
    if(board[0] == letter && board[4] == letter && board[8] == letter){
        someBodyWins = true;
    }
    if(board[2] == letter && board[4] == letter && board[6] == letter){
        someBodyWins = true;
    }
    return someBodyWins;
}
string randselect(string name1, string nametwo){    //Select a random player to go first so that it's fair
    string names[] = {name1, nametwo};
    return names[rand() % 1];
}
int main(){
    //Main Code Goes Here
    cout << "Welcome to Tic Tac Toe! Play against your friends!" << endl;   //Title of Program
    //General Gameplay Variables
    cout << "Enter your names: ";   //For username selections (Important in future of networking)
    string name;
    string name2;
    cin >> name;
    cout << "Player 2, enter your name: ";
    cin >> name2;
    int position;
    int turns = 1;
    //Game Code
    display_board();    //Initial display of board so new players can understand interface and make first move
    cout << "Enter the position you want to put your letter in - " << randselect(name, name2) << " goes first!" << endl;    //Instruction
    while(turns <= 9){  //Beginning of game turn loop
       cin >> position;
        if(board[position] == 'X' || board[position] == 'O'){   //To avoid cheating and breaking of game because of trolls
            cout << "Quit Cheating!" << endl;
            turns -= 1;
        }
        else{
            if(turns % 2 == 0){ //Default Logic for making a move based on odd or even turn number
                board[position] = 'O';
            }
            else{
                board[position] = 'X';
            }
        }
        //Checking Code Starts Here
        if(checkRows('X')  == true || checkColumns('X') == true || checkDiagonals('X') == true){
            cout << name << " Wins!" << endl;
            break;
        }
        if(checkRows('O') == true || checkColumns('O') == true || checkDiagonals('O') == true){
            cout << name2 << " Wins!" << endl;
            break;
        }
        //Checking Code Ends Here
        display_board();
        turns += 1;
    }
    return 0;
}
/* 
Thank you for experiencing a tour of the Tic Tac Toe Game. We hope you enjoyed it. Please make your way to the exit button on the tab. 
*/
