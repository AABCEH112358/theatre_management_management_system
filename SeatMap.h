#ifndef SEATMAP_H
#define SEATMAP_H
#include <vector>
#include <string>
using namespace std;


class SeatMap {
private:
int numRows;
int seatsPerRow;
vector<vector<bool>> grid;

public:
SeatMap();
SeatMap(int numRows, int seatsPerRow);
void initialize(int numRows, int seatsPerRow);
void markSeat(int row, int col, bool reserved); 
bool isSeatTaken(int row, int col) const;
bool isValidRow(int row) const;
bool isValidCol(int col) const;
bool isValidSeat(char seat) const;

int getNumRows() const;
int getSeatsPerRow() const;

char colToLabel(int col) const;
int labelToCol(char label) const;

};
#endif
