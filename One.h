#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "airline.h"
using namespace std;

#ifndef ONE_H
#define ONE_H

void populate_flight_from_file();
void menu();
void display_header();

int convertStringToInt(const string& str);
int charToInt(char c);

// Struct to store person info
struct Person {
    string firstName;
    string lastName;
    string phoneNumber;
    string rownum;
    int pID;
};
#endif