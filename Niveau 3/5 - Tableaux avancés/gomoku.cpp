#include <iostream>
#include <vector>
#include <string>

enum pion {
  empty = 0,
  player1 = 1,
  player2 = 2,
};

pion checkRow(std::vector<pion> *row) {
  pion previous = (*row)[0];
  size_t count = 1;
  for (size_t i = 1; i < row->size(); i++) {
    if ((*row)[i] == previous)
      count++;
    if (count == 5 && previous != 0)
      return previous;
    previous = (*row)[i];
  }
  return empty;
}

pion checkColumn(std::vector<std::vector<pion>> *board, size_t col) {
  pion previous = (*board)[0][col];
  size_t count = 1;
  for (size_t i = 1; i < board->size(); i++) {
    if ((*board)[i][col] == previous)
        count++;
    if (count == 5 && previous != 0) {
        return previous;
    }
    previous = (*board)[i][col];
  }
  return empty;
}
// \\ 

pion checkDiagonal1(std::vector<std::vector<pion>> *board, size_t row, size_t col) {
  pion previous = (*board)[row][col];
  size_t count = 1;
  for (size_t i = 1; i < board->size() - 4; i++) {
    if ((*board)[row+i][col+i] == previous) 
      count++;
    if (count == 5 && previous != 0)
      return previous;
    previous = (*board)[row+i][col+i];
  }
  return empty;
}

// /
pion checkDiagonal2(std::vector<std::vector<pion>> *board, size_t row, size_t col) {
  // starting row is 4
  pion previous = (*board)[row][col];
  size_t count = 1;
  for (size_t i = 1; i < board->size(); i++) {
    if ((*board)[row-i][col+i] == previous) 
      count++;
    if (count == 5 && previous != 0)
      return previous;
    previous = (*board)[row-i][col+i];
  }
  return empty;
}

pion gomoku(std::vector<std::vector<pion>> *board, size_t size) {
  for (size_t i = 0; i < size; i++) {
      pion row = checkRow(&(*board)[i]);
      if (row != empty) {
        return row;
      }
      pion column = checkColumn(board,i);
      if (column != empty) {
        return column;
      }
      // max starting column is size-5
      for (size_t j = 0; j < size-4; j++) {
        if (i < size-4) {
          pion diagonal1 = checkDiagonal1(board, i, j);
          if (diagonal1 != empty) {
            return diagonal1;
          }
        }
        if (i > 4) {
          pion diagonal2 = checkDiagonal2(board, i, j);
          if (diagonal2 != empty) {
            return diagonal2;
          }
        }
      }
  }
  return empty;
}

int main(int argc, char const *argv[])
{
    size_t size;
    std::cin >> size;
    std::vector<std::vector<pion>> board(size, std::vector<pion>(size, empty));

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            uint8_t a;
            std::cin >> a;
            if (a == 1) 
              board[i][j] = player1;
            else if (a == 2)
              board[i][j] = player2;
            else 
              board[i][j] = empty;
        }
    }
    std::cout << (int)gomoku(&board, size) << '\n';

    return 0;
}
