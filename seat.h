#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#ifndef SEAT_H
#define SEAT_H

class seat{
public:
    //ctor
    seat();
    seat(int row,char col,char s);
    
    seat(const seat& source);
    seat(string& rownum, char s);
    
    //setters
    void set_row(int row);
    void set_col(char col);
    void set_status(bool s);
    
    //getters
    int get_row()const;
    int get_col()const;
    bool get_status()const;
    
private:
    int Srow; //reads from Airline class
    char Scol; //reads from Airline class
    bool status; // "X" if occupied
                 // "O" if not occupied
};
#endif
