#include <iostream>
#include <vector>
#include "SudokuBoard.h"
#include "SudokuValidator.h"
#include "SudokuCell.h"
using namespace std;

// Конструктор поля, всё поле - массив из 81 объекта Клетка
// со стартовым значением 0 и без защиты
SudokuBoard::SudokuBoard() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = SudokuCell(0);
            interactiveBoard[i][j] = SudokuCell(0);
        }
    }
}
//Сеттер значения выбранной ячейки
void SudokuBoard::SetValue(int row, int col, int value) {
    board[row][col].SetValue(value);
}
void SudokuBoard::SetValueDemo(int row, int col, int value) {
    interactiveBoard[row][col].SetValue(value);
}
//Геттер значения выбранной ячейки
int SudokuBoard::GetValue(int row, int col) const {
    return board[row][col].GetValue();
}
int SudokuBoard::GetValueDemo(int row, int col) const {
    return interactiveBoard[row][col].GetValue();
}
//Решатор судоку. Используется алгоритм обратного хода. Если ход приводит к некорректному результату
//то делается шаг назад и перебираются все варианты, пока корректное положение всех 81 цифр не будет достигнуто
//Алгоритм рекурсивный, так что читается сложно
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
//Проверка на то что судоку решено. Реализовано именно так в угоду декомпозиции.
bool SudokuBoard::IsSolved() {
    SudokuValidator validator = SudokuValidator(*this);
    return validator.IsSolved();
}
//Вывод поля на экран
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
//Считывание поля. Есть 2 режима: забитое ранее в программу или можно вручную задавать по клеточкам, но это очень больно и неприятно.
//Все считанные поля, которые не равны нулю, защищаются от изменения пользователем
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
                //В ручном вводе если вводится некорректное число то пользователя просят сделать нормально
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

//Функция хода игрока. Если ход некорректный, то он не происходит, а пользователю сообщают об этом
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
// Демонстрационный режим. Сначала программа решает судоку 
// а потом на новой доске пошагово заполняет каждую незаполненную клеточку
// после каждого заполнения ожидается любая клавиша 
// чтобы гарантировать что пользователь успел понять что произошло в каждый конкретный ход
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