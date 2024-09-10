#include "airline.h"

// three data members
string *airline_name;
vector<string *> flights;
int numberOflights;

// constructor
airlines::airlines(const string &name) : numberOflights(0) {
    airline_name = new string(name);
}

// destructor
airlines::~airlines() {
    delete airline_name;
}

// member function to add flights
void addFlight(const string &flight) {
    string *newFlight = new string(flight);
    flights.push_back(newFlight);
    numberOflights++;
}

// getter function for airline name
string airlines::get_airline_name() const {
    return *airline_name;
}

// getter function for list of flights
const vector<string *> &airlines::get_flights() const {
    return flights;
}

// getter function for number of flights
int airlines::get_num_flights() const {
    return numberOflights;
}
