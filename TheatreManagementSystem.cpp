#include "TheatreManagementSystem.h"
#include "filemanager.h"
#include "costumer.h"
#include "TheatreShow.h"
#include "reservation.h"

#include <iostream>
#include <string>
#include <limits>
#include <ios>

void TheatreManagementSystem::start() {
    fileManager.loadShows("shows.txt", theatreShows);
    fileManager.loadReservations("reservations.txt", theatreShows);
    
    displayTitleScreen();
    
    int role = selectUserRole();
    if (role == 1) {
        runCustomerMenu();
    } else if (role == 2) {
        runAdminMenu();
    }
}

void TheatreManagementSystem::displayTitleScreen() {
    std::cout << "TTRMS Version: 1.0\n";
    std::cout << "Term Project - Theatre Ticket Reservation Management System\n";
    std::cout << "Produced by Group #3\n";
    std::cout << "Names: Anes Khacha, Usman Mirza, Yaseen Azzam\n\n";
    std::cout << "<<< Press Return to Continue >>>\n";

    std::cin.get();
}

int TheatreManagementSystem::selectUserRole() {
    int choice = 0;
    while (true) {
        std::cout << "\nPlease select whether your running the program as a Customer or Admin:\n\n";
        std::cout << "1. Customer\n";
        std::cout << "2. Admin\n";
        std::cout << "Enter choice: ";
        
        if (std::cin >> choice && (choice == 1 || choice == 2)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
        std::cout << "\nError: Invalid option. Please enter 1 or 2.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void TheatreManagementSystem::runCustomerMenu() {
    int choice = 0;
    bool keepRunning = true;

    while (keepRunning) {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "Please select one of the following options:\n";
        std::cout << "1. Select a Theatre Show\n";
        std::cout << "2. Display Theatre Seat Map\n";
        std::cout << "3. Add a New Reservation\n";
        std::cout << "4. Cancel an Existing Reservation\n";
        std::cout << "5. Save Data\n";
        std::cout << "6. Quit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "\nError: Invalid input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "\n--- Available Theatre Shows ---\n";
                for (size_t i = 0; i < theatreShows.size(); ++i) {
                    std::cout << i + 1 << ". " << theatreShows[i].getShowName() << "\n";
                }
                std::cout << "Select a show number: ";
                std::cin >> selectedShowIndex;
                selectedShowIndex--;
                break;

            case 2:
                if (selectedShowIndex >= 0 && selectedShowIndex < static_cast<int>(theatreShows.size())) {
                    theatreShows[selectedShowIndex].displaySeatMap();
                } else {
                    std::cout << "Error: Select a show first (Option 1).\n";
                }
                break;

             case 3:
                 if (selectedShowIndex >= 0 && selectedShowIndex < static_cast<int>(theatreShows.size())) {
                     std::string first, last;
                     int row;
                     char seat;
                                
                     std::cout << "First Name: ";
                     std::cin >> first;
                     std::cout << "Last Name: ";
                     std::cin >> last;
                                
                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                     std::string phone = Customer::validatePhoneNumber();
                        if (phone.empty()) {
                            std::cout << "Reservation cancelled.\n";
                            break;
                        }

                        std::cout << "Row (Starts at 0): ";
                        std::cin >> row;
                        std::cout << "Seat Letter: ";
                        std::cin >> seat;

                        int newResID = nextReservationID++;

                        theatreShows[selectedShowIndex].addReservation(newResID, first, last, phone, row, seat);
                                
                    } else {
                        std::cout << "Error: Select a show first.\n";
                    }
                    break;

            case 4:
                if (selectedShowIndex >= 0 && selectedShowIndex < static_cast<int>(theatreShows.size())) {
                    int resID;
                    std::cout << "Enter reservation ID to cancel: ";
                    std::cin >> resID;
                    theatreShows[selectedShowIndex].cancelReservation(resID);
                } else {
                    std::cout << "Error: Select a show first.\n";
                }
                break;

            case 5: {
                std::cout << "Do you want to save your reservation data?\n";
                std::cout << "Please answer <Y or N>: ";
                char saveConfirm;
                std::cin >> saveConfirm;
                
                if (saveConfirm == 'Y' || saveConfirm == 'y') {
                    fileManager.saveReservations("reservations.txt", theatreShows);
                    
                    std::cout << "Success: Your reservation has been saved to the system.\n";
                } else {
                    std::cout << "Save cancelled.\n";
                }
                break;
            }

            case 6:
                std::cout << "Program terminated.\n";
                keepRunning = false;
                break;

            default:
                std::cout << "\nInvalid option.\n";
        }
    }
}

void TheatreManagementSystem::runAdminMenu() {
    int choice = 0;
    bool keepRunning = true;
    
    while (keepRunning){
        std::cout << "\nMain Menu\n";
        std::cout << "Please select of of the following options:\n";
        std::cout << "1. Display list of shows\n";
        std::cout << "2. Display reservation information\n";
        std::cout << "3. Add a new show\n";
        std::cout << "4. Remove an existing show\n";
        std::cout << "5. Save Data\n";
        std::cout << "6. Quit\n";
        std::cout << "Enter your choice: ";
        
        // Catching non-integer inputs
        if(!(std::cin >> choice)){
            std::cout << "\nError: Invalid input. Please enter a valid menu number.\n";
            std::cin.clear();
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            continue;
        }
        switch (choice) {
            case 1: {
                std::cout << "\n--- Master Show List ---\n";
                if (theatreShows.empty()) {
                    std::cout << "No shows currently loaded in the system.\n";
                } else {
                    for (size_t i = 0; i < theatreShows.size(); ++i) {
                        std::cout << i + 1 << ". "
                                  << theatreShows[i].getShowID() << " "
                                  << theatreShows[i].getShowName() << " "
                                  << theatreShows[i].getCity() << "\n";
                    }
                }
                break;
            }

            case 2: {
                std::cout << "\n--- Display Reservation Information ---\n";
                if (theatreShows.empty()) {
                    std::cout << "Error: No shows available to view.\n";
                    break;
                }

                for (size_t i = 0; i < theatreShows.size(); ++i) {
                    std::cout << i + 1 << ". " << theatreShows[i].getShowName() << "\n";
                }
                std::cout << "Select a show number: ";
                int showChoice;
                std::cin >> showChoice;
                int idx = showChoice - 1;

                if (idx >= 0 && idx < static_cast<int>(theatreShows.size())) {
                    theatreShows[idx].displayReservations();
                } else {
                    std::cout << "Error: Invalid show selection.\n";
                }
                break;
            }

            case 3: {
                std::cout << "\n--- Add a New Show ---\n";
                std::string id, name, city;
                int rows, seatsPerRow;

                std::cout << "Enter Show ID (e.g., SH500): ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "Enter Show Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter City: ";
                std::getline(std::cin, city);
                std::cout << "Enter Rows: ";
                std::cin >> rows;
                std::cout << "Enter Seats Per Row: ";
                std::cin >> seatsPerRow;

                theatreShows.push_back(TheatreShow(id, name, city, rows, seatsPerRow)); // Fixed by anes khacha
                std::cout << "Show successfully added.\n";
                break;
            }

            case 4: {
                std::cout << "\n--- Remove an Existing Show ---\n";
                std::string targetID;
                std::cout << "Enter the Show ID to remove: ";
                std::cin >> targetID;

                bool found = false;

                for (auto it = theatreShows.begin(); it != theatreShows.end(); ++it) {
                    if (it->getShowID() == targetID) {
                        theatreShows.erase(it);
                        std::cout << "Show " << targetID << " was successfully removed.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Error: Show ID not found.\n";
                }
                break;
            }

            case 5: {
                std::cout << "Do you want to save all system data? (Shows and Reservations)\n";
                std::cout << "Please answer <Y or N>: ";
                char saveConfirm;
                std::cin >> saveConfirm;
                
                if (saveConfirm == 'Y' || saveConfirm == 'y') {
                    fileManager.saveShows("shows.txt", theatreShows);
                    fileManager.saveReservations("reservations.txt", theatreShows);
                    
                    std::cout << "Success: Shows saved to shows.txt and Reservations saved to reservations.txt.\n";
                } else {
                    std::cout << "Save cancelled.\n";
                }
                break;
            }

            case 6:
                std::cout << "Exiting Admin Menu. Program terminated.\n";
                keepRunning = false;
                break;

            default:
                std::cout << "\nInvalid choice. Please select a number between 1 and 6.\n";
        }
    }
}
