#include <iostream>
#include "SudokuBoard.h"

using namespace std;

int main() {
    
    SudokuBoard board;
    // ���������� ������������� ������ ���������� ������ � 23 �������
    int initialGrid[9][9] = {
       {3, 0, 0, 0, 1, 0, 4, 0, 0},
       {0, 0, 2, 0, 5, 0, 0, 0, 0},
       {8, 0, 0, 4, 0, 2, 0, 6, 0},
       {0, 3, 0, 0, 0, 0, 0, 5, 0},
       {0, 0, 0, 1, 0, 0, 0, 0, 0},
       {0, 0, 9, 8, 0, 4, 3, 0, 0},
       {0, 0, 0, 0, 2, 0, 0, 0, 0},
       {0, 0, 8, 3, 0, 9, 5, 0, 0},
       {6, 0, 0, 0, 0, 0, 0, 0, 7}
    };
    
    // ���������� ��������� ��������. 2 ������: ������� ����� � ��������� ��� ����� ������� �������� �� ���������, �� ��� ����� ������ � ���������
    board.ReadSudokuBoardFromConsole(initialGrid);
    cout << "Start :" << endl;
    // ������� ��������� ��������� �����
    board.PrintSudokuBoard();
    // �������� ����� ������: �� 1 ������ ����, �� 2 �������� ������ ������ �� ���, �� 3 �������� ������ ������ �� ��� � ����� ���������� ��� ����.
    int mode = 0;
    while (mode != 1 && mode != 2 && mode != 3)
    {
        cout << "Select mode: if you want to play enter 1, if you want to automatically solve sudoku, enter 2, if you want to watch demo, enter 3" << endl;
        cin >> mode;
    }
    if (mode == 1) {
        // ���� ������ �� ������ - ������
        while (!board.IsSolved()) {
            int row, column, value;
            cout << "Enter your turn in format: row column value" << endl;
            cin >> row >> column >> value;
            cout << endl;
            board.makeMove(row, column, value);
            board.PrintSudokuBoard();
        }
        cout << "Succesfully solved!" << endl;
    }
    else if (mode == 2)
    {
        cout << "Answer :" << endl;
        board.SolveSudoku();
        board.PrintSudokuBoard();
    }
    else
    {
        board.DemoPlay();
    }
    
     
    return 0;
}