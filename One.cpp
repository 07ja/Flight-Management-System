#include "One.h"

flight Flight;
vector<passenger> passengers;

void populate_flight_from_file() {
    ifstream file("flight_info.txt");

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        Person person;
        person.firstName = line.substr(0, 20);
        person.lastName = line.substr(20, 20);
        person.phoneNumber = line.substr(40, 20);
        person.rownum = line.substr(60, 3);

        person.pID = convertStringToInt(line.substr(64, 5));

        passenger newPassenger(person.pID, person.firstName, person.lastName, person.phoneNumber, person.rownum);
       
        seat newSeat(person.rownum, 'X');
        newPassenger.set_seatPointer(&newSeat);
       
        passengers.push_back(newPassenger);
    }

    file.close();
    Flight.set_listPassenger(passengers);
}

void menu() {
    int input;
    while (true) {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Please select one of the following options:" << endl;
            cout << "1. Display Flight Seat Map." << endl;
            cout << "2. Display Passengers Information." << endl;
            cout << "3. Add a new Passenger." << endl;
            cout << "4. Remove an Existing Passenger." << endl;
            cout << "5. Save data" << endl;
            cout << "6. Quit." << endl;
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Enter your choice: (1, 2, 3, 4, 5 or 6) " ;

            cin >> input;
        
            vector <passenger> p = Flight.get_listPassenger();
            if (cin.fail() || input < 1 || input > 6) {
                cin.clear();
                while (cin.get() != '\n') {
                    continue;
                }

                cout << "<<Invalid Input>> \nPlease choose one of the following options\n" << endl;
            } 
            else {
                switch (input) {
                     case 1: {
                        //code for displaying flight seat map (NEED TO READ FROM FIRST LINE FROM FILE)
                        //flight Flight("WJ1045", 20, 5);
                        
                        int rows = 20;
                        int cols = 5;
                        
                        cout <<"    ";
                        for (int j = 0; j < cols; j++) {
                            char column = 'A' + j;
                            cout << "   " << column;
                        }
                        cout<<endl;
                        
                        for (int i = 0 ; i < p.size(); i++) {
                            Flight.set_seatMap(vector<vector<passenger> >(rows, Flight.get_listPassenger()));
                        }
                        
                        for (int i = 0; i < rows; i++) {
                            cout << "     +";
                            for (int j = 0; j < cols; j++) {
                                cout << "---+";
                            }
                            cout << endl;
                            cout << setw(4) << i << " ";
              
                            int lastAssignedCol = -1;
                            
                            for (int passengerIndex = 0; passengerIndex < Flight.get_listPassenger().size(); passengerIndex++) {
                                seat* k = Flight.get_listPassenger()[passengerIndex].get_seatPointer();
                                
                                if (k->get_row() == i) {
                             
                                    for (int j = lastAssignedCol + 1; j < cols; j++) {
                                        //vertical grid element
                                        cout << "| ";
                                        
                                        //check if the current column j matches the passenger's column
                                        if (j == k->get_col() - 1) {
                                            cout << "X ";
                                            lastAssignedCol = j;
                                            break;
                                        } 
                                        else {
                                            cout << "  ";  //print empty space if no passenger in the current column
                                        }
                                    }
                                }
                            }
                            
                            //fill remaining empty seats in the row
                            for (int j = lastAssignedCol + 1; j < cols; j++) {
                                
                                cout << "| ";
                                cout << "  ";
                            }
                            
                            //vertical grid element at the end of the row
                            cout << "|";
                            cout << endl;
                        }
                      
                        cout << "     +";
                        for (int j = 0; j < cols; j++) {
                            cout << "---+";
                        }
                        cout << endl; 
                        
                        cin.clear();
                        cout << "\n<<Press Enter to continue>>\n";
                        cin.ignore();
                        cin.get();    // Wait for user to press Enter
                        break;
                    }


                    case 2: {
                        cout << "\nPassengers Information:\n" << endl;
                        cout << setw(20) << left << "First Name"
                             << setw(20) << left << "Last Name"
                             << setw(20) << left << "Phone"
                             << setw(5) << left << "Row"
                             << setw(10) << left << "Seat ID" << endl;
                        cout << "------------------------------------------------------------------------" << endl;
                        
                        
                        for (size_t i = 0; i < p.size(); ++i) {
                            seat *k = p[i].get_seatPointer();
                            
                            cout<< setw(20) << left << p[i].get_FName()
                            << setw(20) << left << p[i].get_LName()
                            << setw(20) << left<<p[i].get_PhoneNumber()
                            << setw(4) << left << k->get_row()
                            << setw(5)<< p[i].get_passenger_id() << endl;
                            
                            cout << "------------------------------------------------------------------------" << endl;
                        }

                        cin.clear();
                        cout << "\n<<Press Enter to continue>>\n";
                        cin.ignore();
                        cin.get();
                        break;
                    }
                        
                        
                    case 3: {
                        // Code for adding a new passenger
                        int id;
                        string FName, LName, pNum;
                        string desiredrow;
                        string desiredcol;
                        int row;
                        
                        //Add restrictions//
                        do {
                            cout << "\nPlease enter the passenger id (5 digits): ";
                            cin >> id;
                            
                            if (cin.fail() || id < 10000 || id > 99999) {
                                cin.clear(); // Clear the error flag
                                
                                // Consume the remaining characters in the input buffer
                                while (cin.get() != '\n') {
                                    continue;
                                }
                                cout << "\nInvalid input for passenger id. Please enter a 5-digit integer." << endl;
                            }

                            else {
                                cin.ignore();
                                bool idExist = false;
                                for (size_t i = 0; i < p.size(); ++i) {
                                    if (p[i].get_passenger_id() == id) {
                                        cout << "\nA passenger with ID " << id << " already exists. Please enter a new ID." << endl;
                                        idExist = true;
                                        break;
                                    }
                                }
                                if (!idExist) {
                                    break;
                                }
                            }
                        }
                        while (true);
                        
                        do {
                            cout << endl << "Please enter the passenger first name: ";
                            cin >> FName;
                            
                            bool isValidFirstName = (FName.length() <= 20);

                            for (int i = 0; i < FName.length(); ++i) {
                                if (!((FName[i] >= 'A' && FName[i] <= 'Z') || (FName[i] >= 'a' && FName[i] <= 'z'))) {
                                    isValidFirstName = false;
                                    break;
                                }
                            }

                            if (isValidFirstName) {
                                break;
                            } 
                            else {
                                cout << "\nInvalid input for first name. Please enter a valid name." << endl;
                            }
                        } 
                        while (true);
                        
                        do {
                            cout << endl << "Please enter the passenger last name: ";
                            cin >> LName;
                        
                            bool isValidFirstName = (FName.length() <= 20);
                            for (int i = 0; i < FName.length(); ++i) {
                                if (!((FName[i] >= 'A' && FName[i] <= 'Z') || (FName[i] >= 'a' && FName[i] <= 'z'))) {
                                    isValidFirstName = false;
                                    break;
                                }
                            }
                            
                            if (isValidFirstName) {
                                break;
                            } 
                            else {
                                cout << "\nInvalid input for first name. Please enter a valid name." << endl;
                            }
                        }
                        while (true);
                        
                        do {
                            cout << endl << "Please enter the passenger phone number: ";
                            cin >> pNum;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

                            // Check if pNum does not exceed the maximum length (20 characters)
                            bool isValidPhoneNumber = (pNum.length() <= 20);
                            int digitCount = 0;

                            // Iterate through characters in pNum and check if they are valid (digits, whitespace, or '-')
                            for (size_t i = 0; i < pNum.length(); ++i) {
                                if (isdigit(pNum[i])) {
                                    digitCount++;
                                } 
                                else if (!(isspace(pNum[i]) || pNum[i] == '-')) {
                                    isValidPhoneNumber = false;
                                    break;
                                }
                            }

                            if (isValidPhoneNumber && digitCount >= 10) {
                                break; // Exit the loop if the input is valid
                            } 
                            else {
                                cout << "Invalid input for phone number. Please enter a valid number with at least 10 digits and a maximum of 20 characters." << endl;
                            }
                        } 
                        while (true);
                        
                        do {
                            cout << endl << "Please enter the passenger's desired row: ";
                            cin>>desiredrow;
                            row = convertStringToInt(desiredrow);
                            
                            
                               
                            if (row < 0 || row >= 20) {
                                
                                cout << "Invalid input for desired row. Please enter an integer." << endl;
                            } else {
                                
                                break;
                            }
                        } 
                        while (true);
                        
                        do {
                            cout << endl << "Please enter the passenger's desired seat (A to "
                                 << static_cast<char>('A' + 4) << "): ";
                            cin >> desiredcol;

                            if (desiredcol.length() != 1 || !isalpha(desiredcol[0])) {
                                cout << "Invalid input for desired seat. Please enter a single character." << endl;
                                cin.clear();
                                while (cin.get() != '\n') {
                                    continue;
                                }
                            } 
                            else {
                                char colChar = toupper(desiredcol[0]);
                                if (colChar < 'A' || colChar >= 'A' + 5) {
                                    cout << "Invalid input for desired seat. Please enter a character between 'A' and "
                                         << static_cast<char>('A' + 4) << "." << endl;
                                } 
                                else {
                                    desiredcol = colChar;
                                    break;
                                }
                            }
                        } 
                        while (true);
                        
                        
                        cout << "------------------------------------------------------------------------" << endl;
                        
                        string rownum = desiredrow+desiredcol;
                        
                        passenger newPassenger(id, FName, LName, pNum, rownum);
                        
                        seat newSeat(rownum, 'X');
                        newPassenger.set_seatPointer(&newSeat);
                        
                        passengers.push_back(newPassenger);
                        
                        newPassenger.set_seatPointer(&newSeat);

                        Flight.set_listPassenger(passengers);
                    
                        cin.clear();
                        cout << "\n<<Press Enter to continue>>\n";
                        cin.ignore();
                        cin.get();
                        break;
                    }
                         
    
                    case 4: {
                        int idToRemove;
                        cout << "\nPlease enter the ID of the passenger to be removed: ";
                        cin >> idToRemove;

                        const vector<passenger>& passengerList = Flight.get_listPassenger();
                        int  indexToRemove = passengerList.size(); // Initialize to an invalid index

                        // Find the passenger with the given ID in the flight's passengerList
                        for (size_t i = 0; i < passengerList.size(); ++i) {
                            if (passengerList[i].get_passenger_id() == idToRemove) {
                                indexToRemove = i;
                                break;
                            }
                        }

                        if (indexToRemove < passengerList.size()) {
                            // Passenger found, create a modified copy of the passengerList
                            vector<passenger> modifiedPassengerList(passengerList);
                            modifiedPassengerList.erase(modifiedPassengerList.begin() + indexToRemove);

                            // Update the corresponding seat status to 'O' (unoccupied)
                            seat* seatPtr = passengerList[indexToRemove].get_seatPointer();
                            if (seatPtr != nullptr) {
                                seatPtr->set_status('O');
                            }

                            // Set the modified passenger list back to the flight
                            Flight.set_listPassenger(modifiedPassengerList);

                            cout << "Passenger with ID " << idToRemove << " removed successfully." << endl;
                        } 
                        else {
                            cout << "Passenger with ID " << idToRemove << " not found." << endl;
                        }

                        cin.clear();
                        cout << "\n<<Press Enter to continue>>\n";
                        cin.ignore();
                        cin.get();
                        break;
                    }


                    case 5: {
                        ofstream outFile("flight_info.txt");

                        if (!outFile.is_open()) {
                            cerr << "Error opening file for writing." << endl;
                            break;
                        }

                        outFile << "WJ1045   20    5" << endl;

                        // Write each passenger's information to the file
                        for (size_t i = 0; i < p.size(); ++i) {
                            seat *k = p[i].get_seatPointer();
                            
                                outFile << setw(20) << left << p[i].get_FName()
                                        << setw(20) << left << p[i].get_LName()
                                        << setw(20) << left<<p[i].get_PhoneNumber()
                                        << setw(4) << left << k->get_row()
                                        << setw(5)<< p[i].get_passenger_id() << endl;
                          
                        }

                        outFile.close();
                        cout << "\nData saved successfully." << endl;
                        break;
                    }


                    case 6: {
                        cout << "\nQuitting..." << endl;
                        return;
                    }
                }
        }
    }
    return;
}


void display_header(){
    cout << "\n\n------------------------------------------------------------------------"<< endl;
    cout << "Version: 1.0" << endl;
    cout << "Term Project - Flight Mannagement Program in C++" << endl;
    cout << "Produced by: Mark Jimenez, Jaimal Sahota, Rajvir Bhatti," << endl;
    cout << "Year: 2023" << endl;
    cout << "------------------------------------------------------------------------"<< endl;
    cout << "\n<<Press Enter to continue>> ";
    
    cin.get(); // Wait for user to press Enter
    
    return;
}

int convertStringToInt(const string& str) {
    int result = 0;
    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (isdigit(c)) {
            result = result * 10 + (c - '0');
        }
    }
    return result;
}

int charToInt(char c) {
    if ('A' <= c && c <= 'F') {
        return c - 'A' + 1;
    } else {
        cerr << "Error: Input is not a valid digit or letter." << std::endl;
        return 0;
    }
}
