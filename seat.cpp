#include "seat.h"
#include "One.h"

//Seat Class//
//constructor
seat::seat(int row, char col, char s) {
    Srow = row;
    Scol = col;
    status = s;
}

seat::seat(string& rownum, char s) {
    if (isdigit(rownum[1])) {
        string r = rownum.substr(0, 2);
        Srow = convertStringToInt(r);
        Scol = rownum[2];
    } 
    else {
        string r = rownum.substr(0, 1);
        Srow = convertStringToInt(r);
        Scol = rownum[1];
    }
}

//default constructor
seat::seat() {
    Srow = 0;
    Scol = 'A';
    status = 'O';
}

//setters
void seat::set_row(int row) {
    Srow = row;
}

void seat::set_col(char col) {
    Scol = col;
}

void seat::set_status(bool s) {
    status = s;
}

//copy constructor
seat::seat(const seat& source) {
    Srow = source.Srow;
    Scol = source.Scol;
    status = source.status;
}

//getters
int seat::get_row() const {
    return Srow;
}

int seat::get_col() const {
    return charToInt(Scol);
}

bool seat::get_status() const {
    return status;
}

//others

