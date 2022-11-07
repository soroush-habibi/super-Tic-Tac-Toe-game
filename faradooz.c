#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char mainboard[9][3][3] = {{{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}},
                        {{0,0,0},{0,0,0},{0,0,0}}}; // 1=player1       2=player2

int all[3][3] = {{0,0,0},
                {0,0,0},
                {0,0,0}};// 1=player1       2=player2

int turn = 1;

void win_shape(int winner,int game){
    if(winner == 1){
        mainboard[game][0][0] = 1;
        mainboard[game][0][1] = 1;
        mainboard[game][0][2] = 1;
        mainboard[game][1][0] = 1;
        mainboard[game][1][1] = 1;
        mainboard[game][1][2] = 1;
        mainboard[game][2][0] = 1;
        mainboard[game][2][1] = 1;
        mainboard[game][2][2] = 1;
    }else if(winner == 2){
        mainboard[game][0][0] = 2;
        mainboard[game][0][1] = 2;
        mainboard[game][0][2] = 2;
        mainboard[game][1][0] = 2;
        mainboard[game][1][1] = 2;
        mainboard[game][1][2] = 2;
        mainboard[game][2][0] = 2;
        mainboard[game][2][1] = 2;
        mainboard[game][2][2] = 2;
    }
}

void check_win_part(){
    for(int game = 0;game < 9;game++){
        //check row
        int r,c;
        int l = 0;//1 = mosavi nist
        int n = 0;//1 = hanooz tamam nashode
        switch(game){
            case 0:r=0;c=0;break;
            case 1:r=0;c=1;break;
            case 2:r=0;c=2;break;
            case 3:r=1;c=0;break;
            case 4:r=1;c=1;break;
            case 5:r=1;c=2;break;
            case 6:r=2;c=0;break;
            case 7:r=2;c=1;break;
            case 8:r=2;c=2;break;
        }
        //check row
        for(int row = 0;row < 3;row++){
            if(mainboard[game][row][0] == 1 && mainboard[game][row][1] == 1 && mainboard[game][row][2] == 1){
                all[r][c] = 1;
                win_shape(1,game);
                l = 1;
            }else if(mainboard[game][row][0] == 2 && mainboard[game][row][1] == 2 && mainboard[game][row][2] == 2){
                all[r][c] = 2;
                win_shape(2,game);
                l = 1;
            }
        }

        //check col
        for(int col = 0;col < 3;col++){
            if(mainboard[game][0][col] == 1 && mainboard[game][1][col] == 1 && mainboard[game][2][col] == 1){
                all[r][c] = 1;
                win_shape(1,game);
                l = 1;
            }else if(mainboard[game][0][col] == 2 && mainboard[game][1][col] == 2 && mainboard[game][2][col] == 2){
                all[r][c] = 2;
                win_shape(2,game);
                l = 1;
            }
        }

        //check diameter
        if(mainboard[game][0][0] == 1 && mainboard[game][1][1] == 1 && mainboard[game][2][2] == 1){
            all[r][c] = 1;
            win_shape(1,game);
            l = 1;
        }else if(mainboard[game][0][0] == 2 && mainboard[game][1][1] == 2 && mainboard[game][2][2] == 2){
            all[r][c] = 2;
            win_shape(2,game);
            l = 1;
        }else if(mainboard[game][0][2] == 1 && mainboard[game][1][1] == 1 && mainboard[game][2][0] == 1){
            all[r][c] = 1;
            win_shape(1,game);
            l = 1;
        }else if(mainboard[game][0][2] == 2 && mainboard[game][1][1] == 2 && mainboard[game][2][0] == 2){
            all[r][c] = 2;
            win_shape(2,game);
            l = 1;
        }

        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(mainboard[game][i][j] == 0){
                    n = 1;
                }
            }
        }

        if(n == 0 && l == 0){
            mainboard[game][0][0] = 0;
            mainboard[game][0][1] = 0;
            mainboard[game][0][2] = 0;
            mainboard[game][1][0] = 0;
            mainboard[game][1][1] = 0;
            mainboard[game][1][2] = 0;
            mainboard[game][2][0] = 0;
            mainboard[game][2][1] = 0;
            mainboard[game][2][2] = 0;
        }
    }
}

void check_win_main(){
    //check row
    for(int i = 0;i < 3;i++){
        if(all[i][0] == 1 && all[i][1] == 1 && all[i][2] == 1){
            system("cls");
            printboard();
            printf("\nPlayer 1 Win the game.Congratulations!!!!!!");
            getch();
        }else if(all[i][0] == 2 && all[i][1] == 2 && all[i][2] == 2){
            system("cls");
            printboard();
            printf("\nPlayer 2 Win the game.Congratulations!!!!!!");
            getch();
        }
    }

    //check col
    for(int i = 0;i < 3;i++){
        if(all[0][i] == 1 && all[1][i] == 1 && all[2][i] == 1){
            system("cls");
            printboard();
            printf("\nPlayer 1 Win the game.Congratulations!!!!!!");
            getch();
        }else if(all[0][i] == 2 && all[1][i] == 2 && all[2][i] == 2){
            system("cls");
            printboard();
            printf("\nPlayer 2 Win the game.Congratulations!!!!!!");
            getch();
        }
    }

    //check diameter
    if(all[0][0] == 1 && all[1][1] == 1 && all[2][2] == 1){
        system("cls");
        printboard();
        printf("\nPlayer 1 Win the game.Congratulations!!!!!!");
        getch();
    }else if(all[0][0] == 2 && all[1][1] == 2 && all[2][2] == 2){
        system("cls");
        printboard();
        printf("\nPlayer 2 Win the game.Congratulations!!!!!!");
        getch();
    }else if(all[0][2] == 1 && all[1][1] == 1 && all[2][0] == 1){
        system("cls");
        printboard();
        printf("\nPlayer 1 Win the game.Congratulations!!!!!!");
        getch();
    }else if(all[0][2] == 2 && all[1][1] == 2 && all[2][0] == 2){
        system("cls");
        printboard();
        printf("\nPlayer 2 Win the game.Congratulations!!!!!!");
        getch();
    }

    //check draw
    int k = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(all[i][j] == 0){
                k++;
            }
        }
    }
    if(k == 0){
        system("cls");
        printboard();
        printf("\nDraw");
        getch();
    }
}

void pixel_print(int game,int row,int col){
    int n;
    char c;
    if(mainboard[game][row][col] == 0){
        char name[5];
        n = 9*game + 3*row + col + 1;
        itoa(n, name, 10);
        int q = 0;
        switch(n){
            case 1:printf("01");q=1;break;
            case 2:printf("02");q=1;break;
            case 3:printf("03");q=1;break;
            case 4:printf("04");q=1;break;
            case 5:printf("05");q=1;break;
            case 6:printf("06");q=1;break;
            case 7:printf("07");q=1;break;
            case 8:printf("08");q=1;break;
            case 9:printf("09");q=1;break;
        }
        if(q == 0){
            printf(name);
        }
    }else if(mainboard[game][row][col] == 1){
        printf("X ");
    }else if(mainboard[game][row][col] == 2){
        printf("O ");
    }
}

void printboard(){
    pixel_print(0,0,0);
    printf("|");
    pixel_print(0,0,1);
    printf("|");
    pixel_print(0,0,2);
    printf("  ||\t");
    pixel_print(1,0,0);
    printf("|");
    pixel_print(1,0,1);
    printf("|");
    pixel_print(1,0,2);
    printf("   ||\t");
    pixel_print(2,0,0);
    printf("|");
    pixel_print(2,0,1);
    printf("|");
    pixel_print(2,0,2);
    printf("\n--------  ||	--------   ||	--------\n");
    pixel_print(0,1,0);
    printf("|");
    pixel_print(0,1,1);
    printf("|");
    pixel_print(0,1,2);
    printf("  ||\t");
    pixel_print(1,1,0);
    printf("|");
    pixel_print(1,1,1);
    printf("|");
    pixel_print(1,1,2);
    printf("   ||\t");
    pixel_print(2,1,0);
    printf("|");
    pixel_print(2,1,1);
    printf("|");
    pixel_print(2,1,2);
    printf("\n--------  ||	--------   ||	--------\n");
    pixel_print(0,2,0);
    printf("|");
    pixel_print(0,2,1);
    printf("|");
    pixel_print(0,2,2);
    printf("  ||\t");
    pixel_print(1,2,0);
    printf("|");
    pixel_print(1,2,1);
    printf("|");
    pixel_print(1,2,2);
    printf("   ||\t");
    pixel_print(2,2,0);
    printf("|");
    pixel_print(2,2,1);
    printf("|");
    pixel_print(2,2,2);
    printf("\n----------------------------------------\n");
    pixel_print(3,0,0);
    printf("|");
    pixel_print(3,0,1);
    printf("|");
    pixel_print(3,0,2);
    printf("  ||\t");
    pixel_print(4,0,0);
    printf("|");
    pixel_print(4,0,1);
    printf("|");
    pixel_print(4,0,2);
    printf("   ||\t");
    pixel_print(5,0,0);
    printf("|");
    pixel_print(5,0,1);
    printf("|");
    pixel_print(5,0,2);
    printf("\n--------  ||	--------   ||	--------\n");
    pixel_print(3,1,0);
    printf("|");
    pixel_print(3,1,1);
    printf("|");
    pixel_print(3,1,2);
    printf("  ||\t");
    pixel_print(4,1,0);
    printf("|");
    pixel_print(4,1,1);
    printf("|");
    pixel_print(4,1,2);
    printf("   ||\t");
    pixel_print(5,1,0);
    printf("|");
    pixel_print(5,1,1);
    printf("|");
    pixel_print(5,1,2);
    printf("\n--------  ||	--------   ||	--------\n");
    pixel_print(3,2,0);
    printf("|");
    pixel_print(3,2,1);
    printf("|");
    pixel_print(3,2,2);
    printf("  ||\t");
    pixel_print(4,2,0);
    printf("|");
    pixel_print(4,2,1);
    printf("|");
    pixel_print(4,2,2);
    printf("   ||\t");
    pixel_print(5,2,0);
    printf("|");
    pixel_print(5,2,1);
    printf("|");
    pixel_print(5,2,2);
    printf("\n----------------------------------------\n");
    pixel_print(6,0,0);
    printf("|");
    pixel_print(6,0,1);
    printf("|");
    pixel_print(6,0,2);
    printf("  ||\t");
    pixel_print(7,0,0);
    printf("|");
    pixel_print(7,0,1);
    printf("|");
    pixel_print(7,0,2);
    printf("   ||\t");
    pixel_print(8,0,0);
    printf("|");
    pixel_print(8,0,1);
    printf("|");
    pixel_print(8,0,2);
    printf("\n--------  ||	--------   ||	--------\n");
    pixel_print(6,1,0);
    printf("|");
    pixel_print(6,1,1);
    printf("|");
    pixel_print(6,1,2);
    printf("  ||\t");
    pixel_print(7,1,0);
    printf("|");
    pixel_print(7,1,1);
    printf("|");
    pixel_print(7,1,2);
    printf("   ||\t");
    pixel_print(8,1,0);
    printf("|");
    pixel_print(8,1,1);
    printf("|");
    pixel_print(8,1,2);
    printf("\n--------  ||	--------   ||	--------\n");
    pixel_print(6,2,0);
    printf("|");
    pixel_print(6,2,1);
    printf("|");
    pixel_print(6,2,2);
    printf("  ||\t");
    pixel_print(7,2,0);
    printf("|");
    pixel_print(7,2,1);
    printf("|");
    pixel_print(7,2,2);
    printf("   ||\t");
    pixel_print(8,2,0);
    printf("|");
    pixel_print(8,2,1);
    printf("|");
    pixel_print(8,2,2);
}

void player1_move(int num){
    int row,col;
    int game = 0;
    while(num > 9){
        num = num - 9;
        game = game + 1;
    }
    switch(num){
        case 1:
            row = 0;
            col = 0;
            break;
        case 2:
            row = 0;
            col = 1;
            break;
        case 3:
            row = 0;
            col = 2;
            break;
        case 4:
            row = 1;
            col = 0;
            break;
        case 5:
            row = 1;
            col = 1;
            break;
        case 6:
            row = 1;
            col = 2;
            break;
        case 7:
            row = 2;
            col = 0;
            break;
        case 8:
            row = 2;
            col = 1;
            break;
        case 9:
            row = 2;
            col = 2;
            break;
    }

    if(mainboard[game][row][col] == 0){
        mainboard[game][row][col] = 1;
        turn = 2;
    }else{
        printf("\nchecked before.try another number");
        _sleep(2000);
    }
}

void player2_move(int num){
    int row,col;
    int game = 0;
    while(num > 9){
        num = num - 9;
        game = game + 1;
    }
    switch(num){
        case 1:
            row = 0;
            col = 0;
            break;
        case 2:
            row = 0;
            col = 1;
            break;
        case 3:
            row = 0;
            col = 2;
            break;
        case 4:
            row = 1;
            col = 0;
            break;
        case 5:
            row = 1;
            col = 1;
            break;
        case 6:
            row = 1;
            col = 2;
            break;
        case 7:
            row = 2;
            col = 0;
            break;
        case 8:
            row = 2;
            col = 1;
            break;
        case 9:
            row = 2;
            col = 2;
            break;
    }

    if(mainboard[game][row][col] == 0){
        mainboard[game][row][col] = 2;
        turn = 1;
    }else{
        printf("\nchecked before.try another number\n");
        _sleep(2000);
    }
}

int main(){
    int i,t;
    while(1){
        if(turn == 1){
            system("cls");
            printboard();
            printf("\nPlayer1 turn:");
            scanf("%d", &i);
            player1_move(i);
            check_win_part();
            system("cls");
            printboard();
        }else if(turn == 2){
            system("cls");
            printboard();
            printf("\nPlayer2 turn:");
            scanf("%d", &i);
            player2_move(i);
            check_win_part();
            system("cls");
            printboard();
        }
        check_win_main();
    }
    return 0;
}