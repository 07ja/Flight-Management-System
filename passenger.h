#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "seat.h"

using namespace std;

#ifndef PASSENGER_H
#define PASSENGER_H

class passenger{
public:
    //ctor
    passenger();
    passenger(const int pID,const string& FN,const string& LN, const string& PNum, string &seatcode);
    passenger(const passenger& source);
    
    //setters
    void set_PhoneNumber(char* pNum);
    void set_FName(char* FN);
    void set_LName(char* LN);
    void set_passenger_id(int pID);
    void set_seatPointer(seat* ptr);
    
    //getters
    string get_FName()const;
    string get_LName()const;
    string get_PhoneNumber()const;
    int get_passenger_id()const;
    string get_seat_code()const;
    seat* get_seatPointer() const;
    
private:
    int passenger_id;
    string FName;
    string LName;
    string PhoneNumber;
    string seat_code;
    seat* seatPTR;
};
#endif
