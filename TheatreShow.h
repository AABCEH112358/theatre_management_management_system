#ifndef THEATRESHOW_H
#define THEATRESHOW_H
#include <string>
#include <vector>
#include "reservation.h"

class TheatreShow {
private:
  std::string showID;
  std::string showName;
  std::string city;
  int numRows;
  int seatsPerRow;
  std::vector<Reservation> reservations;

public:
  TheatreShow();
  TheatreShow(const string& showID, const string& showName, const string& city, int numRows =0, int seatsPerRow = 0);

//getters
  std::string getShowID() const;
  std::string getShowName() const;
  std::string getCity() const;
  int getNumRows() const;
  int getSeatsPerRow() const;
  std::vector<Reservation> getReservations() const;

//setters
  void setShowID(const string& showID);
  void setShowName(const string& showName);
  void setCity(const string& city);
  void setNumRows(int numRows);
  void setSeatsPerRow(int seatsPerRow);
  
  void displaySeatMap() const;
  void displayReservations() const;
  bool isSeatTaken(int row, char seat) const;
  bool isValidRow(int row) const;
  bool isValidSeat(char seat) const;
  bool isValidReservationID(int reservationID) const;
  void addReservation(const Reservation& reservation);
  bool addReservation(int reservationID, const std::string& firstName, const std::string& lastName, const std::string& phoneNumber, int row, char seat);
  bool cancelReservation(int reservationID);
  
  char seatToColumnLabel(int col) const;
  int labelToColumnIndex(char label) const;
};
#endif
