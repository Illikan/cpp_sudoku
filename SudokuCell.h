#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H

class SudokuCell {
private:
    int value;
    bool protection;
public:
    SudokuCell();
    SudokuCell(int value);
    int GetValue() const;
    void SetValue(int value);
    void ProtectCell();
    bool IsProtected();
};

#endif // SUDOKUCELL_H