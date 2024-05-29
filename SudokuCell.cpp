#include <iostream>
#include "SudokuCell.h"
using namespace std;

//������������ ������� ������
SudokuCell::SudokuCell(): value(0) {}

SudokuCell::SudokuCell(int value): value(value){}

//������ �������� � ������
int SudokuCell::GetValue() const {
	return value;
}

//����� Protect �������� ������ �� ��������� �������������.
//����� ��� ����, ����� �� ����� ������� ������ ���� ���������� ����������� ����� � ������� �� ������
void SudokuCell::ProtectCell() {
	this->protection = true;
}
bool SudokuCell::IsProtected() {
	return this->protection;
}
//������ �������� � ������
void SudokuCell::SetValue(int value) {
	if (this->protection == true) {
		cout << "This cell is protected from changing. Please choose other cell" << endl;
	}
	else
	{
		this->value = value;
	}
}
