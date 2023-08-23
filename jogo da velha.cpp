#include <stdio.h>

char board[3][3];  // Tabuleiro 3x3

// Inicializa o tabuleiro com espaços em branco
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Imprime o tabuleiro atual na tela
void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Verifica se um jogador venceu
int checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;  // Vitória
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;  // Vitória
    }
    return 0;  // Sem vitória
}

// Verifica se o tabuleiro está cheio, ou seja, empate
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  // Ainda há espaços vazios
            }
        }
    }
    return 1;  // Tabuleiro cheio
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int row, col;

    printf("Jogo da Velha do FARRAPO!\n");

    while (1) {
        printBoard();

        printf("Jogador %c, digite a linha e coluna (exemplo: 1 1): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(currentPlayer)) {
            printBoard();
            printf("Jogador %c venceu!\n", currentPlayer);
            break;
        } else if (isBoardFull()) {
            printBoard();
            printf("Empate!\n");
            break;
        }

        // Troca de jogador
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}