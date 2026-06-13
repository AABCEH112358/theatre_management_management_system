#include "SeatMap.h"

SeatMap::SeatMap() : numRows(0), seatsPerRow(0) {}

SeatMap::SeatMap(int numRows, int seatsPerRow) {
initialize(numRows, seatsPerRow);
}
void SeatMap::initialize(int numRows, int seatsPerRow) { // CHANGE THISSSSSS
  this->numRows = numRows;
  this->seatsPerRow = seatsPerRow;
  grid.clear();
  for(int i = 0; i < numRows; ++i) {
    vector<bool> row;
    for(int j = 0; j < seatsPerRow; ++j) {
      row.push_back(false);
    }
    grid.push_back(row);
      }
}

void SeatMap::markSeat(int row, int col, bool reserved) {
  if(isValidRow(row) && isValidCol(col)) {
    grid[row][col] = reserved;
  }
}

bool SeatMap::isSeatTaken(int row, int col) const {
  if(!isValidRow(row) || !isValidCol(col)) {
    return false;
  }
  return grid[row][col];
}
bool SeatMap::isValidRow(int row) const {
  return row >= 0 && row < numRows;
}

bool SeatMap::isValidCol(int col) const {
  return col >= 0 && col < seatsPerRow;
}
bool SeatMap::isValidSeat(char seat) const {
  int col = labelToCol(seat);
  return isValidCol(col);
}

int SeatMap::getNumRows() const {
  return numRows;
}

int SeatMap::getSeatsPerRow() const {
  return seatsPerRow;
}

char SeatMap::colToLabel(int col) const {
  return 'A' + col;
}

int SeatMap::labelToCol(char label) const {
  return toupper(label) - 'A';
}
