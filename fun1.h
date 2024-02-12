#ifndef NQUEENS_H
#define NQUEENS_H

#include <vector>
#include <iostream>

class NQueens {
private:
    int boardSize;
    std::vector<std::vector<int>> board;

    bool isSafe(int row, int col);
    bool solveNQueensUtil(int col);

public:
    NQueens(int size);
    void solveNQueens();
    void printSolution();
};

#endif
