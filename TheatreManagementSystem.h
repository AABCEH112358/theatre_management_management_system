#ifndef THEATRE_MANAGEMENT_SYSTEM_H
#define THEATRE_MANAGEMENT_SYSTEM_H

#include <vector>
#include <string>
#include <iostream>

#include "filemanager.h"
#include "TheatreShow.h"

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
    int nextReservationID = 2000;
};

#endif


