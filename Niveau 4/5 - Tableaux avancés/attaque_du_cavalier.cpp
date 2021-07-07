#include <iostream>
#include <vector>
#include <string>

#define boardSize 8

struct position {
    size_t row, column;
    position(size_t _col, size_t _row) {
        column = _col;
        row = _row;
    }
};

std::vector<position> getKnightMoves(position pos) {
    // Note: it's not worth filtering the moves that are outside of the board
    return std::vector<position>{
        position(pos.column-1, pos.row-2),
        position(pos.column-1, pos.row+2),
        position(pos.column-2, pos.row-1),
        position(pos.column-2, pos.row+1),
        position(pos.column+1, pos.row-2),
        position(pos.column+1, pos.row+2),
        position(pos.column+2, pos.row-1),
        position(pos.column+2, pos.row+1),
    };
}

bool canEat(std::vector<position> knights, std::vector<position> pieces) {
    for (auto &&knight : knights) {
        for (auto &&knightMove : getKnightMoves(knight)) {
            if (knightMove.column >= 0 && knightMove.column < boardSize && knightMove.row >= 0 && knightMove.row < boardSize) {
                for (auto &&piece : pieces) {
                    if (piece.column == knightMove.column && piece.row == knightMove.row)
                        return true;
                }
            }
            
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::vector<position> whiteKnights{}, blackPieces{};

    // INPUT and CLASSIFICATION
    for (size_t i = 0; i < boardSize; i++)
    {
        std::string line;
        std::getline(std::cin, line);
        // std::cout << line << '\n';
        for (size_t j = 0; j < boardSize; j++)
        {
            if (line[j] == 'C') {
                // add position to white knights
                whiteKnights.push_back(position(i, j));
            } else if (std::islower(line[j])) {
                // add position to black pieces
                blackPieces.push_back(position(i, j));
            }
        }
    }    
    std::cout << (canEat(whiteKnights, blackPieces) ? "yes" : "no") << '\n';
    
    return 0;
}