#include "passenger.h"
#include "seat.h"

//Passenger Class
//constructor
passenger::passenger(const int pID, const string& FN, const string& LN, const string& PNum, string&seatcode) {
    passenger_id = pID;
    FName = FN;
    LName = LN;
    PhoneNumber = PNum;
    seat_code = seatcode;
}

//default constructor
passenger::passenger() {
    passenger_id = 0;
    FName = "Unavailable";
    LName = "Unavailable";
    PhoneNumber = "N/A";
    seat_code = "0A";
}

//setters
void passenger::set_PhoneNumber(char* pNum) {
    PhoneNumber = pNum;
}

void passenger::set_FName(char* FN) {
    FName = FN;
}

void passenger::set_LName(char* LN) {
    LName = LN;
}

void passenger::set_passenger_id(int pID) {
    passenger_id = pID;
}

void passenger::set_seatPointer(seat* ptr) {
    seatPTR = new seat(*ptr);   
}

//copy constructor
passenger::passenger(const passenger& source) {
    passenger_id = source.passenger_id;
    FName = source.FName;
    LName = source.LName;
    PhoneNumber = source.PhoneNumber;
    seat_code = source.seat_code;

    if (source.seatPTR != nullptr) {
        seatPTR = new seat(*source.seatPTR);
    } 
    else {
        seatPTR = nullptr;
    }
}

//getters
int passenger::get_passenger_id() const {
    return passenger_id;
}

string passenger::get_FName()const {
    return FName;
}

string passenger::get_LName()const {
    return LName;
}

string passenger::get_PhoneNumber()const {
    return PhoneNumber;
}
string passenger::get_seat_code() const {
    return seat_code;
}

seat* passenger::get_seatPointer() const {
        return seatPTR;
}

//other



