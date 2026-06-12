#include "TheatreShow.h"
#include <iostream>
using namespace std;
//constructors
TheatreShow::TheatreShow() :showID(""), showName(""), city(""), numRows(0), seatsPerRow(0) {}

TheatreShow::TheatreShow(const string& showID, const string&  showName, const string& city, int numRows, int seatsPerRow) : showID(showID), showName(showName), city(city), numRows(numRows), seatsPerRow(seatsPerRow) {}

//getters
string TheatreShow::getShowID() const {
  return showID;
    }
string TheatreShow::getShowName() const{
  return showName;
}
string TheatreShow::getCity() const {
  return city;
}
int TheatreShow::getNumRows() const {
  return numRows;
}
int TheatreShow::getSeatsPerRow() const {
  return seatsPerRow;
}
vector<Reservation> TheatreShow::getReservations() const {
return reservations;
}

//setters
void TheatreShow::setShowID(const string& showID) {
  this->showID = showID;
}
void TheatreShow::setShowName(const string& showName) {
  this->showName = showName;
}
void TheatreShow::setCity(const string& city) {
  this->city = city;
}
void TheatreShow::setNumRows(int numRows) {
  this->numRows = numRows;
}
void TheatreShow::setSeatsPerRow(int seatsPerRow) {
  this->seatsPerRow = seatsPerRow;
}

void TheatreShow::displaySeatMap() const {
  if(numRows <= 0 || seatsPerRow <= 0) {
    cout << "\nError: Invalid seat for this theatre.\n";
    return;
}

cout << "\nTheatre Seat Map for Show " << showID << "\n\n";
cout << "    ";
for(int c = 0; c < seatsPerRow; ++c) {
  cout << " "<< seatToColumnLabel(c) << " ";
}
cout << "\n";
cout << "  +";

for(int c =0; c < seatsPerRow; ++c) {
  cout << "---+";
}

cout << "\n";
for(int r=0; r < numRows; ++r) {
  if(r < 10) {
    cout << " " << r << " |";
  }
  else {
    cout << r << " |";
}
  for(int c = 0; c < seatsPerRow; ++c) {
    char label = seatToColumnLabel(c);
    if(isSeatTaken(r, label)) {
      cout << " X |";
    }
    else {
      cout << "   |";
    }
  }
cout << "\n";
cout << "  +";

for(int c = 0; c < seatsPerRow; ++c) {
  cout << "---+";
}
cout << "\n";
  }
}
//Reservation display
void TheatreShow::displayReservations() const {
  cout << "\nReservation List (show: " << showID << " " << showName << " " << city << ")\n";
  cout << "---------------------------------------------------------------\n";
  cout << "First Name  Last Name  Phone Number  Row  Seat  ID\n";
  cout << "---------------------------------------------------------------\n";
  if(reservations.empty()) {
    cout << "No reservations found.\n";
    return;
  }
  for(int i = 0; i < reservations.size(); ++i) {   
    cout <<reservations[i].getCustomer().getFirstName() << "  " << reservations[i].getCustomer().getLastName() << "  " 
    << reservations[i].getCustomer().getPhoneNumber() << "  " << reservations[i].getRow() << "  " 
    <<reservations[i].getSeat() << "  "
    <<reservations[i].getReservationID() << "\n";
  }
}
bool TheatreShow::isSeatTaken (int row, char seat) const {
  char upperSeat = toupper(seat);
  for(int i =0; i < reservations.size(); ++i) {
    if(reservations[i].getRow() == row && toupper(reservations[i].getSeat()) == upperSeat) {
      return true;
    }
  }
return false;
}
bool TheatreShow::isValidRow(int row) const {
  return row >= 0 && row < numRows;
}

bool TheatreShow::isValidReservationID(int reservationID) const{
  for(int i = 0; i < reservations.size(); ++i) {
    if(reservations[i].getReservationID() == reservationID) {
      return false;
    }
  }
return true;
}
void TheatreShow::addReservation(const Reservation&  reservation) {
  reservations.push_back(reservation);
}

bool TheatreShow::addReservation(int reservationID, const string& firstName, const string& lastName, const string& phoneNumber, int row, char seat) {
  if(!isValidRow(row)) {
    cout << "Error: Row " << row << " is invalid. Valid rows: 0 to " << (numRows -1) << ".\n";
    return false;
    }
  char upperSeat = toupper(seat);
  if(!isValidSeat(upperSeat)) {
    cout << "Error: Seat " << seat << " is invalid. Valid Seats A to " << seatToColumnLabel(seatsPerRow - 1) << ".\n";
    return false;
  }
  
  if(isSeatTaken(row, upperSeat)) {
    cout << "Error: Seat " << row << upperSeat << " is already reserved.\n";
    return false;
  }
  
  if(!isValidReservationID(reservationID)) {
    cout << "Error: Reservation ID " << reservationID << " already exists.\n";
    return false;
  }
  
  Customer customer(firstName, lastName, phoneNumber);
  Reservation newReservation(reservationID, showID, customer, row, upperSeat);
  reservations.push_back(newReservation);
  cout << "Reservation successfully added. ID: " << reservationID <<", Seat: " << row << upperSeat << "\n";
  return true;
}
bool TheatreShow::isValidSeat (char seat) const {
  char upperSeat = toupper(seat);
  int col = labelToColumnIndex(upperSeat);
  return col >= 0 && col < seatsPerRow;
}

bool TheatreShow::cancelReservation(int reservationID) {
  for(int i = 0; i < reservations.size(); ++i) {
    if(reservations[i].getReservationID() == reservationID) {
      cout << "Reservation for " << reservations[i].getCustomer().getFullName() << " was successfully removed.\n";
      for(int j = i; j < reservations.size() - 1; ++j) {
        reservations[j] = reservations[j+1];
      }
      reservations.pop_back();
      return true;
    }   
  }
  cout << "Error: reservation ID " << reservationID << " not found.\n";
  return false;
}

char TheatreShow::seatToColumnLabel(int col) const {
  return 'A' + col;
}
int TheatreShow::labelToColumnIndex(char label) const {
  return toupper(label) - 'A';
}
