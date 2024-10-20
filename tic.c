#include <stdio.h>

char board[3][3];  // 3x3 Tic-Tac-Toe board

// Function to initialize the board with empty spaces
void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void display_board() {
    int i, j;
    printf("\n");
    printf("  1 2 3\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("  -----\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
int check_win(char symbol) {
    int i, j;
    // Check rows and columns
    for (i = 0; i < 3; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1;
    }
    return 0;
}

int main() {
    int row, col, player = 1, moves = 0;
    char mark;

    init_board();

    do {
        display_board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter row (1-3) and column (1-3) to place your mark: ", player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid move! Row and column must be between 1 and 3.\n");
            continue;
        }

        if (board[row - 1][col - 1] == ' ') {
            mark = (player == 1) ? 'X' : 'O';
            board[row - 1][col - 1] = mark;
            moves++;

            if (check_win(mark)) {
                display_board();
                printf("Player %d wins!\n", player);
                break;
            } else if (moves == 9) {
                display_board();
                printf("It's a draw!\n");
                break;
            }

            player++;
        } else {
            printf("Invalid move! That slot is already taken.\n");
        }
    } while (1);

    return 0;
}
