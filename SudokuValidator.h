#ifndef SUDOKUVAL_H
#define SUDOKUVAL_H

#include <vector>
#include "SudokuBoard.h"

class SudokuValidator {
public:
    SudokuBoard& board;
    SudokuValidator();
    SudokuValidator(SudokuBoard& board);
    bool IsRowValid(int row) const;
    bool IsColumnValid(int col) const;
    bool IsBoxValid(int rowStart, int colStart) const;
    bool IsValidMove(int row, int col, int value);
    bool IsSolved() const;
    bool IsValidSolution() const;
};

#endif // SUDOKUVAL_H