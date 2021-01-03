struct pos{
    int y;
    int x;
};
void print_board();
int move(struct pos p1, struct pos p2, int pl);
int game_input(int pl);
int chkmove(struct pos p1, struct pos p2, int pl);
int abs(int n);
int score(char capture);
void update_score(char capture,int pl);
