#include <iostream>
#include <limits>

#define SIZE 3

using namespace std;

char board[SIZE][SIZE];

void initBoard() {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void printBoard() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if(j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if(i < SIZE - 1) cout << "--+---+--" << endl;
    }
    cout << endl;
}

char checkWinner() {
    for(int i = 0; i < SIZE; i++) {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    bool isFull = true;
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(board[i][j] == ' ')
                isFull = false;

    if(isFull)
        return 'D';

    return ' ';
}

int minimax(bool isMaximizing) {
    char result = checkWinner();
    if(result == 'X') return -10;
    if(result == 'O') return 10;
    if(result == 'D') return 0;

    if(isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for(int i = 0; i < SIZE; i++)
            for(int j = 0; j < SIZE; j++)
                if(board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(false);
                    board[i][j] = ' ';
                    bestScore = max(score, bestScore);
                }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for(int i = 0; i < SIZE; i++)
            for(int j = 0; j < SIZE; j++)
                if(board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(true);
                    board[i][j] = ' ';
                    bestScore = min(score, bestScore);
                }
        return bestScore;
    }
}

void aiMove() {
    int bestScore = numeric_limits<int>::min();
    int moveRow = -1, moveCol = -1;

    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(false);
                board[i][j] = ' ';
                if(score > bestScore) {
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }

    board[moveRow][moveCol] = 'O';
    cout << "AI избра позиция: " << moveRow + 1 << "," << moveCol + 1 << endl;
}

void playerMove() {
    int row, col;
    while(true) {
        cout << "Enter row and then column(1-3): ";
        cin >> row >> col;
        row--; col--;
        if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = 'X';
            break;
        } else {
            cout << "Invalid turn, try again" << endl;
        }
    }
}

int main() {
    initBoard();
    printBoard();

    while(true) {
        playerMove();
        printBoard();
        char result = checkWinner();
        if(result != ' ') {
            if(result == 'X') cout << "You Win" << endl;
            else if(result == 'O') cout << "Ai Wins" << endl;
            else cout << "Draw" << endl;
            break;
        }

        aiMove();
        printBoard();
        result = checkWinner();
        if(result != ' ') {
            if(result == 'X') cout << "You Win" << endl;
            else if(result == 'O') cout << "Ai Wins!" << endl;
            else cout << "Draw" << endl;
            break;
        }
    }

    return 0;
}
