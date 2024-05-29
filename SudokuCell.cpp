#include <iostream>
#include "SudokuCell.h"
using namespace std;

//Конструкторы объекта Клетка
SudokuCell::SudokuCell(): value(0) {}

SudokuCell::SudokuCell(int value): value(value){}

//Геттер значения в клетке
int SudokuCell::GetValue() const {
	return value;
}

//Метод Protect защищает ячейку от изменения пользователем.
//Нужен для того, чтобы во время решения нельзя было переписать изначальную цифру в задачке на другую
void SudokuCell::ProtectCell() {
	this->protection = true;
}
bool SudokuCell::IsProtected() {
	return this->protection;
}
//Сеттер значения в клетке
void SudokuCell::SetValue(int value) {
	if (this->protection == true) {
		cout << "This cell is protected from changing. Please choose other cell" << endl;
	}
	else
	{
		this->value = value;
	}
}
