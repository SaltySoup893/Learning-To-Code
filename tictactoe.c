#include <stdio.h>
#include <stdlib.h>

void main() {

    // Declaring functions
    void printBoard(int gameBoard[]);
    int possibleMove(int gameBoard[], int move);
    int isWinner(int boardArray[]);
    void gameWon(int player);
    void gameDraw();

    // 0 means they don't have it, 1 means they do
    int player1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int player2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // 0 means no one has it, 1 means player 1 has it, 2 means player 2 has it
    int game[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // 1 for player 1, 2 for player 2
    int playersTurn = 1;

    // 0 for false, 1 for true
    int gameDone = 0;

    for(int i = 1; i <= 9; i++) {
        system("clear");
        printf("\n\n\nWelcome to Tic Tac Toe!\n\n");
        printBoard(game);
        printf("Player %d it is your turn\n", playersTurn);
        printf("Where would you like to place your %c\n", (playersTurn == 1) ? 'X' : 'O');
        int mark;
        scanf("%d", &mark);
        int legalMove = possibleMove(game, mark);
        while(legalMove == 0) {
            system("clear");
            printf("\n\n\nWelcome to Tic Tac Toe!\n\n");
            printBoard(game);
            printf("Player %d moving to %d is not a legal move\n", playersTurn, mark);
            printf("Please try again\n");
            scanf("%d", &mark);
            legalMove = possibleMove(game, mark);
        }

        // update players board stats, game board stats, determine if the game has been won yet, and clear the terminal screen
        if(playersTurn == 1) {
            player1[mark - 1] = 1;
            game[mark - 1] = 1;
            gameDone = isWinner(player1);
            
        } else {
            player2[mark - 1] = 1;
            game[mark - 1] = 2;
            gameDone = isWinner(player2);
        }
        
        // swap players turn
        if (gameDone == 1) break;
        else {playersTurn = (playersTurn == 1) ? 2 : 1;}
    }
    if (gameDone == 0) gameDraw();
    else {gameWon(playersTurn);}
}

// Prints out the board into the terminal
void printBoard(int gameBoard[]) {
    char Board[9];
    
    for (int i = 0; i < 9; i++) {
        if (gameBoard[i] == 0) Board[i] = (i+1) + '0';
        else if (gameBoard[i] == 1) Board[i] = 'X';
        else {Board[i] = 'O';}
    }

    printf(" %c | %c | %c \n", Board[0], Board[1], Board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", Board[3], Board[4], Board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", Board[6], Board[7], Board[8]);
}

int possibleMove(int gameBoard[], int move) {
    if (move <= 9 && move >= 1) {
        if (gameBoard[move - 1] == 0) return 1;
    }
    return 0; 
}

int isWinner(int boardArray[]) {
    int isWinner = 0;
    if(boardArray[0] == 1 && boardArray[1] == 1 && boardArray[2] == 1) isWinner = 1;
    else if(boardArray[3] == 1 && boardArray[4] == 1 && boardArray[5] == 1) isWinner = 1;
    else if(boardArray[6] == 1 && boardArray[7] == 1 && boardArray[8] == 1) isWinner = 1;
    else if(boardArray[0] == 1 && boardArray[3] == 1 && boardArray[6] == 1) isWinner = 1;
    else if(boardArray[1] == 1 && boardArray[4] == 1 && boardArray[7] == 1) isWinner = 1;
    else if(boardArray[2] == 1 && boardArray[5] == 1 && boardArray[8] == 1) isWinner = 1;
    else if(boardArray[0] == 1 && boardArray[4] == 1 && boardArray[8] == 1) isWinner = 1;
    else if(boardArray[4] == 1 && boardArray[4] == 1 && boardArray[6] == 1) isWinner = 1;

    return isWinner;
}

void gameWon(int player) {
    system("clear");
    printf("Congrats Player %d!!!\n", player);
    printf("You Won!!!\n\n\n\n");
}

void gameDraw() {
    system("clear");
    printf("\n\n\nUh Oh looks like the game is a draw\n");
    printf("Hope you enjoyed\n\n\n\n\n");
}