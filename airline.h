#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "flight.h"

using namespace std;

#ifndef AIRLINE_H
#define AIRLINE_H

class airlines {
public:
    // constructor
    airlines(const string &name);

    // destructor
    ~airlines();

    // member function to add flights
    void addFlight(const string &flight);

    // getter function for airline name
    string get_airline_name() const;

    // getter function for list of flights
    const vector<string *> &get_flights() const;

    // getter function for number of flights
    int get_num_flights() const;

private:
    // three data members
    string *airline_name;
    vector<string *> flights;
    int numberOflights;
};
#endif
