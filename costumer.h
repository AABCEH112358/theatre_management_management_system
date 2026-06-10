#ifndef CUSTOMER_H
#define CUSTOMER_H 

#include <string>

class Customer{

    private: 
        std::string firstName; 
        std::string lastName; 
        std::string phoneNumber;

    public:
        Customer(); 
        Customer(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber);
        
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getPhoneNumber() const;
        std::string getFullName() const;

        void setFirstName(const std::string& firstName);
        void setLastName(const std::string& lastName); 
        void setPhoneNumber(const std::string& phoneNumber);

        static std::string validatePhoneNumber(); 

        void display()const; 


};

#endif // CUSTOMER_H
