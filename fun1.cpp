#include "fun1.h"

NQueens::NQueens(int size) {
    boardSize = size;
    board.resize(size, std::vector<int>(size, 0));
}

bool NQueens::isSafe(int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < boardSize; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool NQueens::solveNQueensUtil(int col) {
    if (col >= boardSize)
        return true;

    for (int i = 0; i < boardSize; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQueensUtil(col + 1))
                return true;
            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

void NQueens::solveNQueens() {
    if (!solveNQueensUtil(0)) {
        std::cout << "Solution does not exist";
        return;
    }
    printSolution();
}

void NQueens::printSolution() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++)
            std::cout << board[i][j] << " ";
        std::cout << "\n";
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the chessboard: ";
    std::cin >> n;

    NQueens nQueens(n);
    nQueens.solveNQueens();

    return 0;
}
