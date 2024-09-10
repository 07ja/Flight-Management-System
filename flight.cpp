#include "flight.h"

//Flight Class
//Flight constructor
flight::flight(const char* fID, const int rows, const int cols) {
    flightID = fID;
    fRows = rows+1;
    fCols = cols;
    passengerList.resize(cols*(rows+1));
    
    seatMap.resize(rows+1);
    
    for(int i = 0 ; i< rows+1;i++){
        
        seatMap[i].resize(cols);
    }
}

//Flight default constructor
flight::flight() {
    flightID = "Unavailable";
    fRows = 0;
    fCols = 0;
}

//Flight copy constructor
flight::flight(const flight& source) {
    flightID = source.flightID;
    fRows = source.fRows;
    fCols = source.fCols;
}

//Flight setter
void flight::set_flightID(char* fID) {
    flightID = fID;
}

void flight::set_fRows(int rows) {
    fRows = rows;
}

void flight::set_fCols(int cols) {
    fCols = cols;
}

void flight::set_listPassenger(const vector<passenger>& list) {
    passengerList = list;
    for (int i = 0 ; i < fRows; i++){
        for (int j = 0 ; i < fCols; j++){
            seatMap[i][j] = list[i];
        }
    }    
}

void flight::set_seatMap(const vector<vector<passenger> >& map) {
    seatMap = map;
}

//Flight getters
string flight::get_flightID() const {
    return flightID;
}

int flight::get_fRows() const {
    return fRows;
}

int flight::get_fCols() const {
    return fCols;
}

const vector<passenger>& flight::get_listPassenger() const {
    return passengerList;
}

const vector<vector<passenger> >& flight::get_seatMap() const {
    return seatMap;
}
