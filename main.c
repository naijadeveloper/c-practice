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
    char response = ' ';
    char winner = ' ';
    puts("NOTE: YOU ARE X AND COMPUTER IS O");
    //
    do {
        resetBoard();
        response = ' ';
        winner = ' ';

        while(winner == ' ' && checkFreeSpaces() != 0) {
            // info[30] = " ";
            printBoard();

            // player moves
            playerMove();
            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0) {
                break;
            }

            // computer moves
            computerMove();
            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0) {
                break;
            }

            puts("\t**Your turn again**");

        }

        printBoard();
        printWinner(winner);

        // ask user if he/she would like to play again
        getchar();
        printf("\nWould you like to play again? (Y/N): ");
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');

    puts("\nTHANKS FOR PLAYING!!!");

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
    puts("");
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
        puts("----ROW MOVE----");
        do {
            printf("Enter row number (1 - 3): ");
            scanf("%d", &x);

            // print error mssg
            if(x < 1 || x > 3) {
                puts("**Not a valid entry**");
            }
        } while(x < 1 || x > 3);
        x--; // in array world its 0-2 not 1-3

        puts("\n----COLUMN MOVE----");
        do {
            printf("Enter col number (1 - 3): ");
            scanf("%d", &y);

            // print error mssg
            if(y < 1 || y > 3) {
                puts("**Not a valid entry**");
            }
        } while(y < 1 || y > 3);
        y--; // in array world its 0-2 not 1-3

        if(board[x][y] != ' ') {
            puts("\n**Sorry position already taken. Try again**\n");
            printBoard();
        }
    } while(board[x][y] != ' ');

    // assign space to player's value
    board[x][y] = PLAYER;
}

void computerMove() {
    int x, y;

    // generate random row num and col num for computer
    srand(time(0));

    if(checkFreeSpaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;

        printf("\n----Computer moved to row %d and col %d----\n", x+1, y+1);
        
    } else {
        printWinner(' ');
    }
}

char checkWinner() {

    // horizontal check i.e checking each row
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }

    // vertical check i.e checking each col
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // diagonal checks
    for(int i = 0; i < 2; i++) {
        if(i == 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
        }

        if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return board[0][2];
        }
    }

    // if no conditional gives true
    return ' ';
    
}

void printWinner(char winner_char) {
    if(winner_char == PLAYER) {
        printf("CONGRATULATIONS!! YOU WON!!");
    } else if(winner_char == COMPUTER) {
        printf("COMPUTER WINS THIS ROUND!! BETTER LUCK NEXT TIME!");
    } else {
        printf("WELL, IT'S A TIE!!!");
    }
}