#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// functions
void resetBoard();
void printBoard();
void checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

// global vars
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


int main() {
    //
    char winner = ' ';
    resetBoard();
    printBoard();
    

    //
    return 0;
}


// set each space to empty
void resetBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for(int i = 0; i < 3; i++) {
        printf(" %c  | %c  | %c  ", board[i][0], board[i][1], board[i][2]);
        if(i != 2) {
            printf("\n----|----|----\n");
        }
    }
    puts("\n");
}

void checkFreeSpaces() {

}

void playerMove() {

}

void computerMove() {

}

char checkWinner() {

}

void printWinner(char winner_char) {

}