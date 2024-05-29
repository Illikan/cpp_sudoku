#ifndef SUDOKU_H
#define SUDOKU_H
#include <vector>
#include "SudokuCell.h"
class SudokuBoard {
private:
public:
    SudokuCell board[9][9];
    SudokuCell interactiveBoard[9][9];
    SudokuBoard();
    void SetValue(int row, int col, int value);
    void SetValueDemo(int row, int col, int value);
    int GetValue(int row, int col) const;
    int GetValueDemo(int row, int col) const;
    void PrintSudokuBoard();
    void PrintSudokuBoardDemo();
    void ReadSudokuBoardFromConsole(int board[9][9]);
    bool SolveSudoku();
    bool IsSolved();
    bool makeMove(int row, int col, int num);
    void DemoPlay();

};

#endif // SUDOKU_H