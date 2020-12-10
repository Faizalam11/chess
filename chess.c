#include <stdio.h>
#include "functions.h"
char board[8][8]={
    {'R','N','B','Q','K','B','N','R'},
    {'P','P','P','P','P','P','P','P'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'P','P','P','P','P','P','P','P'},
    {'R','N','B','Q','K','B','N','R'}
};
int main(){
    print_board();

    return 0;
}

void print_board(){
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
