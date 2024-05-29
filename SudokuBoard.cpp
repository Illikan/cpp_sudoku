#include <iostream>
#include <vector>
#include "SudokuBoard.h"
#include "SudokuValidator.h"
#include "SudokuCell.h"
using namespace std;

// ����������� ����, �� ���� - ������ �� 81 ������� ������
// �� ��������� ��������� 0 � ��� ������
SudokuBoard::SudokuBoard() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = SudokuCell(0);
            interactiveBoard[i][j] = SudokuCell(0);
        }
    }
}
//������ �������� ��������� ������
void SudokuBoard::SetValue(int row, int col, int value) {
    board[row][col].SetValue(value);
}
void SudokuBoard::SetValueDemo(int row, int col, int value) {
    interactiveBoard[row][col].SetValue(value);
}
//������ �������� ��������� ������
int SudokuBoard::GetValue(int row, int col) const {
    return board[row][col].GetValue();
}
int SudokuBoard::GetValueDemo(int row, int col) const {
    return interactiveBoard[row][col].GetValue();
}
//������� ������. ������������ �������� ��������� ����. ���� ��� �������� � ������������� ����������
//�� �������� ��� ����� � ������������ ��� ��������, ���� ���������� ��������� ���� 81 ���� �� ����� ����������
//�������� �����������, ��� ��� �������� ������
bool SudokuBoard::SolveSudoku() {
    SudokuValidator validator = SudokuValidator(*this);
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (GetValue(row, col) == 0) {
                for (int value = 1; value <= 9; value++) {
                    if (validator.IsValidMove(row, col, value)) {
                        SetValue(row, col, value);

                        if (SolveSudoku()) {
                            return true;
                        }
                        else
                        {
                             SetValue(row, col, 0);
                        }

                    }
                }

                return false;
            }
        }
    }
    return true;
}
//�������� �� �� ��� ������ ������. ����������� ������ ��� � ����� ������������.
bool SudokuBoard::IsSolved() {
    SudokuValidator validator = SudokuValidator(*this);
    return validator.IsSolved();
}
//����� ���� �� �����
void SudokuBoard::PrintSudokuBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << GetValue(i, j) << " ";

            if ((j + 1) % 3 == 0) {
                cout << "| ";
            }
        }
         
        if ((i + 1) % 3 == 0) {
            cout << endl << "---+---+---" << endl;
        }
        cout << endl;
    }

}
void SudokuBoard::PrintSudokuBoardDemo() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << GetValueDemo(i, j) << " ";

            if ((j + 1) % 3 == 0) {
                cout << "| ";
            }
        }

        if ((i + 1) % 3 == 0) {
            cout << endl << "---+---+---" << endl;
        }
        cout << endl;
    }

}
//���������� ����. ���� 2 ������: ������� ����� � ��������� ��� ����� ������� �������� �� ���������, �� ��� ����� ������ � ���������.
//��� ��������� ����, ������� �� ����� ����, ���������� �� ��������� �������������
void SudokuBoard::ReadSudokuBoardFromConsole(int grid[9][9]) {
    int mode;
    cout << "Enter input mode: 1 for prepicked board, 2 for manual input" << endl;
    cin >> mode;
    if (mode == 1){
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                SetValue(i, j, grid[i][j]);
                SetValueDemo(i, j, grid[i][j]);
                if (grid[i][j] != 0) {
                    board[i][j].ProtectCell();
                    interactiveBoard[i][j].ProtectCell();
                }
            }
        }
    }
    else
    {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                int value;

                cout << "Enter value for cell (" << row + 1 << ", " << col + 1 << "): ";
                cin >> value;
                //� ������ ����� ���� �������� ������������ ����� �� ������������ ������ ������� ���������
                if (value < 0 || value > 9) {
                    cout << "Entered invalid value. Please enter values from 0 to 9." << endl;
                    col--;
                    continue;
                }

                SetValue(row, col, value);
                SetValueDemo(row, col, value);
                if (value != 0) {
                    board[row][col].ProtectCell();
                    interactiveBoard[row][col].ProtectCell();
                }
            }
        }
    }
}

//������� ���� ������. ���� ��� ������������, �� �� �� ����������, � ������������ �������� �� ����
bool SudokuBoard::makeMove(int row, int col, int value) {
    SudokuValidator validator = SudokuValidator(*this);
    if (validator.IsValidMove(row, col, value)) {
        return true;
    }
    else
    {
        cout << "Incorrect move. Please enter correct move" << endl;
    }
    return false;
}
// ���������������� �����. ������� ��������� ������ ������ 
// � ����� �� ����� ����� �������� ��������� ������ ������������� ��������
// ����� ������� ���������� ��������� ����� ������� 
// ����� ������������� ��� ������������ ����� ������ ��� ��������� � ������ ���������� ���
void SudokuBoard::DemoPlay(){
    SolveSudoku();
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!interactiveBoard[i][j].IsProtected())
            {   
                int UserInput;
                cout << "Placing " << GetValue(i, j) << " in cell (" << i << "," << j << ")" << endl;
                SetValueDemo(i, j, GetValue(i, j));
                PrintSudokuBoardDemo();
                cout << endl;
                system("pause");
            }
        }
    }
}