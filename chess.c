#include <stdio.h>
#include "functions.h"

int main(){
    char board[8][8]={
        {'R','H','B','Q','K','B','K','R'},
        {'P','P','P','P','P','P','P','P'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'P','P','P','P','P','P','P','P'},
        {'R','H','B','Q','K','B','K','R'}
        };
    //char *ptb = &board; //Pointer to board --> ptb
    print_board(board);

    return 0;
}

void print_board(char board[8][8]){
    int i,j;
    printf("_________________\n");
    for (i=0;i<8;i++){
        printf("|");
        for (j=0;j<8;j++)
            printf("%c|",board[i][j]);
        printf("\n");
    }
    printf("‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
}