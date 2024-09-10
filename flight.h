#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "passenger.h"
#include "seat.h"

using namespace std;

#ifndef FLIGHT_H
#define FLIGHT_H

class flight {
public:
    //ctor
    flight();
    flight(const char* fID, const int rows, const int cols);
    flight(const flight& source);
    
    //setter functions
    void set_flightID(char* fID);
    void set_fRows(int rows);
    void set_fCols(int cols);
    void set_listPassenger(const vector<passenger>& list);
    void set_seatMap(const vector<vector<passenger> >& map);
    
    //getter functions
    string get_flightID() const;
    int get_fRows() const;
    int get_fCols() const;
    const vector<passenger>& get_listPassenger() const;
    const vector<vector<passenger> >& get_seatMap() const;
    
private:
    string flightID;
    int fRows;
    int fCols;
    vector <passenger> passengerList;
    vector<vector<passenger> > seatMap;
    //seatMap[][]
};
#endif
