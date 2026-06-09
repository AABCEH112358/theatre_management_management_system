//
//  TheatreManagementSystem.h
//  termProject
//
//  Created by Yaseen Azzam on 2026-06-08.
//

#ifndef THEATRE_MANAGEMENT_SYSTEM_H
#define THEATRE_MANAGEMENT_SYSTEM_H

#include <vector>
#include <string>
#include <iostream>

// Temporary Mock Class for Person 2s code so you can compile
class TheatreShow {
public:
    // Expanded constructor to support Admin data fields
    TheatreShow(std::string id, std::string name, std::string city)
        : showID(id), showName(name), showCity(city) {}

    // Core attribute getters used by the interface loops
    std::string getShowID() const { return showID; }
    std::string getShowName() const { return showName; }
    std::string getCity() const { return showCity; }

    // Mock functions to verify visual logic paths without crashing
    void displaySeatMap() const {
        std::cout << "\n  [Mock Grid 1-Based]:\n";
        std::cout << "    A   B   C   D\n";
        std::cout << "  +---+---+---+---+\n";
        std::cout << " 1|   | X |   |   |\n";
        std::cout << "  +---+---+---+---+\n";
    }

    bool addReservation(std::string f, std::string l, std::string p, int r, char s) {
        std::cout << "\n[Mock Backend] Added: " << f << " " << l
                  << " at Row " << r << ", Seat " << s << "\n";
        return true;
    }

    bool cancelReservation(int id) {
        std::cout << "\n[Mock Backend] Cancelled ID: " << id << "\n";
        return true;
    }

    void displayReservations() const {
        std::cout << "\n  [Mock Reservations for " << showName << "]:\n";
        std::cout << "  First Name | Last Name | Phone        | Seat\n";
        std::cout << "  John       | Smith     | 403-111-2222 | 5A\n";
    }

private:
    std::string showID;
    std::string showName;
    std::string showCity;
};

// Temporary Mock Class for Person 1s code so you can compile
class FileManager {};

class TheatreManagementSystem {
public:
    void start();

private:
    void displayTitleScreen();
    int selectUserRole();
    void runCustomerMenu();
    void runAdminMenu();

    FileManager fileManager;
    std::vector<TheatreShow> theatreShows;
    int selectedShowIndex = -1;
};

#endif


