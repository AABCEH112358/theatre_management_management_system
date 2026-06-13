#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "reservation.h"

class TheatreShow;

class FileManager{
    public:

        FileManager(); 

        int loadShows(const std::string& filename, std::vector<TheatreShow>& shows);
        
        int loadReservations(const std::string& filename, std::vector<TheatreShow>& shows);

        int saveReservations(const std::string& filename, const std::vector<TheatreShow>& shows) const;

        int saveShows(const std::string& filename, const std::vector<TheatreShow>& shows) const; 
};

#endif