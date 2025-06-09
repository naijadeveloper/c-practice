#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// functions
void resetBoard();
void printBoard();
int checkFreeSpaces();
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

    while(winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();
        playerMove();
    }
    

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

int checkFreeSpaces() {
    int free_spaces = 9;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != ' ') {
                free_spaces--;
            }
        }
    }

    return free_spaces;
}

void playerMove() {
    int x,y;

    do {
        // get user's input
        do {
            printf("\nPlease enter row (1-3): ");
            scanf("%d", &x);
        } while(!(x < 1) && !(x > 3));
        x--; // in array world its 0-2 not 1-3

        do {
            printf("\nPlease enter col (1-3): ");
            scanf("%d", &y);
        } while(!(y < 1) && !(y > 3));
        y--; // in array world its 0-2 not 1-3

        if(board[x][y] != ' ') {
            puts("\nSorry position already taken. Try again\n");
            printBoard();
        }
    } while(board[x][y] != ' ');

    // assign space to player's value
    board[x][y] = PLAYER;
}

void computerMove() {

}

char checkWinner() {

}

void printWinner(char winner_char) {

}