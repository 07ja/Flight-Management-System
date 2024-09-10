#include "One.h"
#include "airline.h"
#include "flight.h"
#include "seat.h"
#include "passenger.h"

int main(void) {
    populate_flight_from_file();
    display_header();
    menu();
}
