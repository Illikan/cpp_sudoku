cmake_minimum_required(VERSION 3.25)
project(sudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_sudoku main.cpp
			"SudokuBoard.cpp" "SudokuCell.h" "SudokuCell.cpp" "SudokuValidator.h" "SudokuValidator.cpp"  )
