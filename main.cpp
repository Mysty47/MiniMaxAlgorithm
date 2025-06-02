#include <iostream>

#define SIZE 3

using namespace std;

void printboard(char board[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if(j < (SIZE - 1)) {
                cout << "|";
            }
        }
        cout << "\n";
        if(i < (SIZE - 1)) {
            cout << "-----\n";
        }
    }
}

void createBoard(char board[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    createBoard(board);
    printboard(board);
}