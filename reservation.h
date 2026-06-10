#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "costumer.h"

class Reservation {
    private:
        int reservationID;
        std::string showID;
        Customer customer;
        int row;
        char seat;

    public: 
        Reservation(); 
        Reservation(int reservationID, const std::string& showID, const Customer& customer,
                        int row, char seat);


        int getReservationID() const; 
        std::string getShowID() const;
        Customer getCustomer() const;
        int getRow() const;
        char getSeat() const;

        std::string getSeatLabel() const;


        void setReservationID(int reservationID);
        void setShowID(const std::string& showID);
        void setCustomer(const Customer& customer);
        void setRow(int row);
        void setSeat(char seat);

        
        void display() const;         
};

#endif