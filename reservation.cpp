#include "reservation.h"

#include<iostream>


using namespace std;

Reservation::Reservation() : reservationID(0), showID(""), customer(), row(0), seat(' ') {}

Reservation::Reservation(int reservationID, const std::string& showID, const Customer& customer,
                        int row, char seat) 
            : reservationID(reservationID), showID(showID), customer(customer), row(row), seat(seat) {}

int Reservation::getReservationID() const {
    return reservationID; 
}

string Reservation::getShowID() const{
    return showID;
}

Customer Reservation::getCustomer() const{ 
    return customer;
}

int Reservation::getRow() const{
    return row;
}

char Reservation::getSeat() const{
    return seat;
}
 
string Reservation::getSeatLabel() const{
    return to_string(row) + string(1, seat);
}


void Reservation::setReservationID(int reservationID) {
    this->reservationID = reservationID;
}

void Reservation::setShowID(const string& showID){
    this->showID = showID;
}

void Reservation::setCustomer(const Customer& customer){
    this->customer = customer; 
}

void Reservation::setRow(int row){
    this->row = row; 
}

void Reservation::setSeat(char seat){ 
    this->seat = seat;
}


void Reservation::display() const{
    cout << customer.getFirstName() << " "
         << customer.getLastName() << "    "
         << customer.getPhoneNumber() << "  " 
         << row << "    "
         << toupper(seat) << "    "
         << reservationID
         << endl;

}