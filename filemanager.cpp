#include "filemanager.h"
#include "TheatreShow.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

FileManager::FileManager() {}

int FileManager::loadShows(const string& filename, vector<TheatreShow>& shows) {
    ifstream inFile; 
    inFile.open(filename);

    if (inFile.fail()){
        cout << "Erroe: could not open file" << filename << endl;
        return 0;
    }

    shows.clear();

    string showID;
    string showName; 
    string city;
    int numRows;
    int seatsPerRow; 

    while(inFile >> showID >> showName >> city >>numRows >> seatsPerRow){
        TheatreShow newShow(showID, showName, city, numRows, seatsPerRow);
        shows.push_back(newShow);
    }

    inFIle.close(); 
    return 1;
}

 
int FileManager::loadReservations(const string& filename,
                                   vector<TheatreShow>& shows) {
    ifstream inFile;
    inFile.open(filename);
 
    if (inFile.fail()) {
        cout << "Error: could not open " << filename << endl;
        return 0;
    }
 
    string showID;
    string firstName;
    string lastName;
    string phone;
    string seatLabel;
    int reservationID;
 
    while (inFile >> showID >> firstName >> lastName
                  >> phone   >> seatLabel >> reservationID) {
 
        int labelLength = seatLabel.length();
 
        if (labelLength < 2) {
            cout << "Warning: bad seat label '" << seatLabel
                 << "' ..." << endl;
            continue;
        }
 
        char seat = seatLabel.at(labelLength - 1);              
        string rowPart = seatLabel.substr(0, labelLength - 1);  
 
        int row = stoi(rowPart);  // converting string to int; 
 
        
        Customer newCustomer(firstName, lastName, phone);
        Reservation newReservation(reservationID, showID, newCustomer, row, seat);
 

        int matched = 0;
        for (int i = 0; i < shows.size(); i++) {
            if (shows.at(i).getShowID() == showID) {
                shows.at(i).addReservation(newReservation);
                matched = 1;
                break;
            }
        }
 
        if (matched == 0) {
            cout << "Warning: no show found for ID '" << showID
                 << "' — skipping reservation" << endl;
        }
    }
 
    inFile.close();
    return 1;
}
 
 

 
int FileManager::saveReservations(const string& filename,
                                   const vector<TheatreShow>& shows) const {
    ofstream outFile;
    outFile.open(filename);
 
    if (outFile.fail()) {
        cerr << "Error: could not write to " << filename << endl;
        return 0;
    }
 
    
    for (int i = 0; i < shows.size(); i++) {
        
        vector<Reservation> reservations = shows.at(i).getReservations(); // another func from the TheatreShow class
 
        
        for (int j = 0; j < reservations.size(); j++) {
            outFile << shows.at(i).getShowID()                          << " "
                    << reservations.at(j).getCustomer().getFirstName()  << " "
                    << reservations.at(j).getCustomer().getLastName()   << " "
                    << reservations.at(j).getCustomer().getPhoneNumber()<< " "
                    << reservations.at(j).getRow()
                    << reservations.at(j).getSeat()                     << " "
                    << reservations.at(j).getReservationID()            << endl;
        }
    }
 
    outFile.close();
    return 1;
}
 
/// need review by teammates ... 









