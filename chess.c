#include <stdio.h>
#include "functions.h"

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
int scores[2]={0,0};
int game_over = 0;

int main(){
    int i = 0;
    while(1){
        int status;
        do{
            print_board();
            printf("Player %d turn:\n",i+1);
            status = game_input(i);
        }while (status);
        if (game_over)
            break;
        i = (i+1) % 2;
    }
    printf("Player %d won.",i+1);
    printf("Players Scores\n");
    printf("Player 1:  %d", scores[0]);
    printf("Player 2:  %d", scores[1]);
    return 0;
}

int game_input(int pl){
    char cmd[10];
    fgets(cmd, 10, stdin);
    int cond = (cmd[0]=='>')&&(cmd[1]>='a'&&cmd[1]<='h')&&(cmd[2]>='1'&&cmd[2]<='8')&&(cmd[3]==' ')&&(cmd[4]>='a'&&cmd[4]<='h')&&(cmd[5]>='1'&&cmd[5]<='8');
    if (cond){
        struct pos p1,p2;
        p1.y= cmd[2] - '0' - 1;
        p1.x=(cmd[1] - 'a');
        p2.y= cmd[5] - '0' - 1;
        p2.x=(cmd[4] - 'a');
        return move(p1,p2,pl);
    }
    printf("Wrong syntax\n");
    return 1;
}

int move(struct pos p1, struct pos p2, int pl){
	char src;
    char des;
    src = board[p1.y][p1.x];
    des = board[p2.y][p2.x];
    if(((src=='K'&&des=='R')&&(p1.x==4&&p1.y==7)&&(board[p1.y][p1.x+1])&&(board[p1.y][p1.x+2])&&(p2.x==7&&p2.y==7))||
       ((src=='k'&&des=='r')&&(p1.x==4&&p1.y==1)&&(board[p1.y][p1.x+1])&&(board[p1.y][p1.x+2])&&(p2.x==7&&p2.y==1))){
        board[p1.y][p1.x] = ' ';
        board[p2.y][p2.x] = ' ';
        board[p1.y][p1.x+1] = des;
        board[p1.y][p1.x+2] = src;
        return 0;
    }
	if (chkmove(p1,p2,pl)){
        printf("Wrong Move!\n");
        return 1;
    }
	board[p1.y][p1.x] = ' ';
	if (board[p2.y][p2.x] == ' ')
		board[p2.y][p2.x] = src;
	else{
        char cap = {board[p2.y][p2.x]};
		board[p2.y][p2.x] = src;
		update_score(cap,pl);
	}
	if (src == 'P'&&p2.y==0){
        char evolve;
        do {
            printf("Enter P,N,B,R,Q to change piece to anyone\n");
            scanf("%c", &evolve);
        }while(evolve=='P'||evolve=='N'||evolve=='B'||evolve=='R'||evolve=='Q');
	    board[p2.y][p2.x] = evolve;
	}
    if (src == 'p'&&p2.y==7){
        char evolve;
        do {
            printf("Enter p,n,b,r,q to change piece to anyone\n");
            scanf("%c", &evolve);
        }while(evolve=='p'||evolve=='n'||evolve=='b'||evolve=='r'||evolve=='q');
        board[p2.y][p2.x] = evolve;
    }
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
    printf("_________________\n");
}

int chkmove(struct pos p1, struct pos p2, int pl){
    char src,des;
    src = board[p1.y][p1.x];
    des = board[p2.y][p2.x];
    if(((src=='K'&&des=='R')&&(p1.x==4&&p1.y==7)&&(board[p1.y][p1.x+1])&&(board[p1.y][p1.x+2])&&(p2.x==7&&p2.y==7))||
    ((src=='k'&&des=='r')&&(p1.x==4&&p1.y==1)&&(board[p1.y][p1.x+1])&&(board[p1.y][p1.x+2])&&(p2.x==7&&p2.y==1))){

    }
    if (pl==0){
        if((src<'A'||src>'Z')||((des<'a'||des>'z')&&(des!=' ')))
            return 1;
    }
    else if (pl==1)
    {
        if((src<'a'||src>'z')||((des<'A'||des>'Z')&&(des!=' ')))
            return 1;
    }
    int i,j;
    switch(src) {
        case 'r':
        case 'R': {
            if ((p1.y != p2.y) && (p1.x != p2.x))
                return 1;
            if (p1.y == p2.y) {
                if (p1.x < p2.x) {
                    for (j = p1.x+1; j != p2.x; ++j) {
                        if (board[p1.y][j]!=' ')
                            return 1;
                    }
                } else if (p1.x > p2.x) {
                    for (j = p1.x-1; j != p2.x; --j) {
                        if (board[p1.y][j]!=' ')
                            return 1;
                    }
                }
            }
            else if (p1.x == p2.x) {
                if (p1.y < p2.y) {
                    for (i = p1.y+1; i != p2.y; ++i) {
                        if (board[i][p1.x]!=' ')
                            return 1;
                    }
                } else if (p1.y > p2.y) {
                    for (i = p1.y-1; i != p2.y; --i) {
                        if (board[i][p1.x]!=' ')
                            return 1;
                    }
                }
            }
            break;
        }
        case 'b':
        case 'B': {
            if (abs(p2.y - p1.y) != abs(p2.x - p1.x))
                return 1;
            if (p1.y > p2.y) {
                if (p1.x < p2.x) {
                    for (i = 1; i != abs(p2.x-p1.x); ++i) {
                        if (board[p1.y-i][p1.x+i]!=' ')
                            return 1;
                    }
                } else if (p1.x > p2.x) {
                    for (i = 1; i != abs(p2.x-p1.x); ++i) {
                        if (board[p1.y-i][p1.x-i]!=' ')
                            return 1;
                    }
                }
            }
            else if (p1.y < p2.y) {
                if (p1.x < p2.x) {
                    for (i = 1; i != abs(p2.x-p1.x); ++i) {
                        if (board[p1.y+i][p1.x+i]!=' ')
                            return 1;
                    }
                } else if (p1.x > p2.x) {
                    for (i = 1; i != abs(p2.x-p1.x); ++i) {
                        if (board[p1.y+i][p1.x-i]!=' ')
                            return 1;
                    }
                }
            }
            break;
        }
        case 'n':
        case 'N': {
            if (((abs(p1.y - p2.y) + abs(p1.x - p2.x)) != 3) || ((abs(p1.y - p2.y) > 2) || (abs(p1.x - p2.x) > 2)))
                return 1;
            break;
        }
        case 'q':
        case 'Q': {
            if (((p1.y != p2.y) && (p1.x != p2.x)) && ((p2.y - p1.y) != (p2.x - p1.x)))
                return 1;
            if ((p1.x==p2.x)||(p1.y==p2.y)){
                if (p1.y == p2.y) {
                    if (p1.x < p2.x) {
                        for (j = p1.x+1; j != p2.x; ++j) {
                            if (board[p1.y][j]!=' ')
                                return 1;
                        }
                    } else if (p1.x > p2.x) {
                        for (j = p1.x-1; j != p2.x; --j) {
                            if (board[p1.y][j]!=' ')
                                return 1;
                        }
                    }
                }
                else if (p1.x == p2.x) {
                    if (p1.y < p2.y) {
                        for (i = p1.y+1; i != p2.y; ++i) {
                            if (board[i][p1.x]!=' ')
                                return 1;
                        }
                    } else if (p1.y > p2.y) {
                        for (i = p1.y-1; i != p2.y; --i) {
                            if (board[i][p1.x]!=' ')
                                return 1;
                        }
                    }
                }
            }
            if (abs(p2.y - p1.y) == abs(p2.x - p1.x)){
                if (p1.y > p2.y) {
                    if (p1.x < p2.x) {
                        for (i = 1; i != abs(p2.x-p1.x); ++i) {
                            if (board[p1.y-i][p1.x+i]!=' ')
                                return 1;
                        }
                    } else if (p1.x > p2.x) {
                        for (i = 1; i != abs(p2.x-p1.x); ++i) {
                            if (board[p1.y-i][p1.x-i]!=' ')
                                return 1;
                        }
                    }
                }
                else if (p1.y < p2.y) {
                    if (p1.x < p2.x) {
                        for (i = 1; i != abs(p2.x-p1.x); ++i) {
                            if (board[p1.y+i][p1.x+i]!=' ')
                                return 1;
                        }
                    } else if (p1.x > p2.x) {
                        for (i = 1; i != abs(p2.x-p1.x); ++i) {
                            if (board[p1.y+i][p1.x-i]!=' ')
                                return 1;
                        }
                    }
                }
            }
            break;
        }
        case 'k':
        case 'K': {
            if ((((p1.y - 1) < p2.y) || ((p1.y + 1) > p2.y)) || (((p1.x - 1) < p2.x) || ((p1.x + 1) < p2.x)))
                return 1;
            break;
        }
        case 'p':
        case 'P':{
            if (pl == 0) {
                if (p1.y == 6) {
                    if (((p1.x != p2.x) || (p1.y <= p2.y)) || (abs(p1.y - p2.y) > 2))
                        return 1;
                    if (abs(p2.y - p1.y) == 2){
                        if (board[p1.y-1][p1.x]==' ')
                            return 1;
                    }
                } else if (((p1.x != p2.x) || (p1.y <= p2.y)) || (abs(p1.y - p2.y) > 1))
                    return 1;
            } else if (pl == 1) {
                if (p1.y == 1) {
                    if (((p1.x != p2.x) || (p1.y >= p2.y)) || (abs(p2.y - p1.y) > 2))
                        return 1;
                    if (abs(p2.y - p1.y) == 2){
                        if (board[p1.y+1][p1.x]==' ')
                            return 1;
                    }
                } else if (((p1.x != p2.x) || (p1.y >= p2.y)) || (abs(p2.y - p1.y) > 1))
                    return 1;
            }
            break;
            default:
                return 1; //not possible?
        }
    }
    return 0;
}

int abs(int n){
    if (n<0)
        n = -1 * n;
    return n;
}
int score(char capture){
    switch (capture){
        case 'P':
        case 'p':
            return 1;
        case 'B':
        case 'b':
        case 'N':
        case 'n':
            return 3;
        case 'R':
        case 'r':
            return 5;
        case 'Q':
        case 'q':
            return 9;
        case 'K':
        case 'k':
            return 100;
        default:
            return 0;
    }
}

void update_score(char capture,int pl){
    scores[pl] += score(capture);
    if (capture=='K'||capture=='k')
        game_over = 1;
}