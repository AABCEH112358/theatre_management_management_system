#include "costumer.h"
#include <iostream> 

using namespace std;

Customer::Customer() : firstName(""), lastName(""), phoneNumber("") {}

Customer::Customer(const std::string& firstName, 
                   const std::string& lastName, 
                   const std::string& phoneNumber)
                   : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber) {}


string Customer::getFirstName() const{
      return firstName; 
}

string Customer::getLastName() const{
      return lastName;
}

string Customer::getPhoneNumber() const{

      return phoneNumber;
}

string Customer::getFullName() const{
      return firstName + " " + lastName;
}


void Customer::setFirstName(const string& firstName){
      (*this).firstName = firstName; 
}

void Customer::setLastName(const string& lastName){
      this->lastName = lastName; 
}

void Customer::setPhoneNumber(const string& phoneNumber){
      this->phoneNumber = phoneNumber;
}


string Customer::validatePhoneNumber(){
    string inputPhoneNumber; 
    while(true){
        bool phoneFlag = true;
        cout << "Enter phone number (digits only, or 0 to cancel): ";
        cin >> inputPhoneNumber;
        if (inputPhoneNumber == "0") return "";

        for (int i = 0; i < inputPhoneNumber.length(); i++)
        {
            if(!isdigit(inputPhoneNumber[i])){
                cout << "Invalid phone number, try again!" << endl;
                phoneFlag = false; 
                break;
            }
        }
        if (!phoneFlag) continue;
        
        if (inputPhoneNumber.size() != 10)
        {
            cout << "Invalid phone Number, try again!";
            continue;
        }

        string validPhoneNumber = inputPhoneNumber.substr(0,3) + "-"
                        + inputPhoneNumber.substr(3, 3) + "-" + inputPhoneNumber.substr(6, 4);

        return validPhoneNumber;
    }
}



void Customer::display() const{
      cout << "Customer information" << endl;
      cout << "Name: " << getFullName() << endl;
      cout << "Phone number: " << getPhoneNumber() << endl;
}
