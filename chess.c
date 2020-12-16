#include <stdio.h>
#include "functions.h"
#include <string.h>
char board[8][8]={
    {'r','n','b','q','k','b','n','r'},
    {'p','p','p','p','p','p','p','p'},
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
    game_input(0);
    print_board();
    return 0;
}

int game_input(int pl){
    char cmd[50];
    fgets(cmd, 50, stdin);
    printf("cmd %s\n",cmd);
    int cond = (cmd[0]=='>')&&(cmd[1]>='a'&&cmd[1]<='h')&&(cmd[2]>='1'&&cmd[2]<='8')&&(cmd[3]==' ')&&(cmd[4]>='a'&&cmd[4]<='h')&&(cmd[5]>='1'&&cmd[5]<='8');
    if (cond){
        struct pos p1,p2;
        p1.y=(cmd[1]-'a');
        p1.x=cmd[2]-'0'-1;
        p2.y=(cmd[4]-'a');
        p2.x=cmd[5]-'0'-1;
        move(p1,p2,pl);
    }
        
}
void move(struct pos p1, struct pos p2, int pl){
	char temp;
	temp = board[p1.x][p1.y];
	board[p1.x][p1.y] = ' ';
	if (board[p2.x][p2.y]==' ')
		board[p2.x][p2.y] = temp;
	else{
        char str1[1] = {board[p2.x][p2.y]};
		if (pl == 1){
			strcat(str1, cap1);
		}
		else{
			strcat(str1, cap2);
		}
		board[p2.x][p2.y] = temp;
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
