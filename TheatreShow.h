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
  TheatreShow(const std::string& showID, const std::string& showName, const std::string& city, int numRows =0, int seatsPerRow = 0);

//getters
  std::string getShowID() const;
  std::string getShowName() const;
  std::string getCity() const;
  int getNumRows() const;
  int getSeatsPerRow() const;
  std::vector<Reservation> getReservations() const;

//setters
  void setShowID(const std::string& showID);
  void setShowName(const std::string& showName);
  void setCity(const std::string& city);
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
