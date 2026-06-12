#include "TheatreShow.h"
#include <iostream>
using namespace std;
//constructors
TheatreShow::TheatreShow() :showID(""), showName(""), city(""), numRows(0), seatsPerRow(0) {}

TheatreShow::TheatreShow(const string& showID, const string&  showName, const string& city, int numRows, int seatPerRow) : showID(showID), showName(showName), city(city), numRows(numRows), seatsPerRow(seatsPerRow) {}

//getters
string TheatreShow::getShowID() const {
  return showID;
    }
string TheatreSHow::getShowName() const{
  return showName;
}
string TheatreShow::getCity() const {
  return city;
}
int ThreatreShow::getNumRows() const {
  return numRows;
}
int TheatreShow::getSeatsPerRows() const {
  return seatsPerRow;
}

//setters
void TheatreShow::setShowID(const string& showID) {
  this->showID = showID
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
void TheatreShow::seatsPerRow(int seatsperRow) {
  this->seatsPerRow = seatsPerRow;
}

void TheatreShow::displaySeatMap() const {
  if(numRows <= 0 || seatsPerRow <= 0) {
    cout << "\nError: Invalid seat for this theatre.\n";
    return;
}

cout << "\nTheatre Seat Map for Show " << showID << "\n\n"
cout << "    ";
for(int c = 0; c < seatsPerRow; ++C) {
  cout << " "<< seatToColumnLabel(c) << " ";
}
cout << "\n"
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
    for(int c = 0; c < seatsPerRow; ++c) {
      char label = SeatToColumnLabel(c);
      if(isSeatTaken(r, label)) {
        cout << " X |";
      }
      else {
        cout << "  |";
      }
    }
cout << "\n";
cout << "  +";
for(int c = 0; c < seatsPerRow; ++c) {
  cout << "---+";
}
cout << "\n";
  }
