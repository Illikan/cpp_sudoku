#include <iostream>
#include <vector>
#include "SudokuValidator.h"
using namespace std;
SudokuValidator::SudokuValidator(SudokuBoard& board): board(board){}

// Проверка строки на корректность
bool SudokuValidator::IsRowValid(int row) const {
    vector<bool> usedNumbers(9, false);

    for (int col = 0; col < 9; ++col) {
        int value = board.GetValue(row, col);

        if (value == 0) {
            continue;
        }

        if (usedNumbers[value - 1]) {
            return false;
        }

        usedNumbers[value - 1] = true;
    }

    return true;
}
// Проверка столбца на корректность
bool SudokuValidator::IsColumnValid(int col) const {
    vector<bool> usedNumbers(9, false);

    for (int row = 0; row < 9; ++row) {
        int value = board.GetValue(row, col);

        if (value == 0) {
            continue;
        }

        if (usedNumbers[value - 1]) {
            return false;
        }

        usedNumbers[value - 1] = true;
    }

    return true;
}
// Проверка района на корректность
bool SudokuValidator::IsBoxValid(int rowStart, int colStart) const {
    vector<bool> usedNumbers(9, false);

    for (int row = rowStart; row < rowStart + 3; ++row) {
        for (int col = colStart; col < colStart + 3; ++col) {
            int value = board.GetValue(row, col);

            if (value == 0) {
                continue;
            }

            if (usedNumbers[value - 1]) {
                return false;
            }

            usedNumbers[value - 1] = true;
        }
    }

    return true;
}
// Проверка решения на корректность путем проверки всех строк, столбцов и районов
bool SudokuValidator::IsValidSolution() const {
    for (int i = 0; i < 9; ++i) {
        if (!IsRowValid(i)) {
            return false;
        }

        if (!IsColumnValid(i)) {
            return false;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!IsBoxValid(i * 3, j * 3)) {
                return false;
            }
        }
    }

    return true;
}
// Проверяет, решено ли судоку
bool SudokuValidator::IsSolved() const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.GetValue(i, j) == 0) {
                return false;
            }
        }
    }

    return IsValidSolution();
}
// Проверка хода на корректность, если ход некорректен, то он не совершается
bool SudokuValidator::IsValidMove(int row, int col, int value) {
    if (value < 1 || value > 9) {
        return false;
    }
    int stored = board.GetValue(row, col);
    board.SetValue(row, col, value);
    
    if (!IsRowValid(row)) {
        board.SetValue(row, col, stored);
        return false;
    }
    if (!IsColumnValid(col)) {
        board.SetValue(row, col, stored);
        return false;
    }

    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;

    if (!IsBoxValid(boxStartRow, boxStartCol)) {
        board.SetValue(row, col, stored);
        return false;
    }

    return true;
}