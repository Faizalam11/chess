#include <stdio.h>
#include "functions.h"
#include <string.h>
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
char cap1[16], cap2[16];
int main(){
    print_board();

    return 0;
}

void input(){
}
void move(int x1, int y1, int x2, int y2, int pl){
	char temp;
	temp = board[x1][y1];
	board[x1][y1] = ' ';
	if (board[x2][y2]==' ')
		board[x2][y2] = temp;
	else{
		if (pl == 1){
			strcat(cap1,board[x2][y2]);
		}
		else{
			strcat(cap2,board[x2][y2]);
		}
		board[x2][y2] = temp;
	}
	
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
