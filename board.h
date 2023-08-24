#include "chess_piece.h"

class Board{
public:
    ChessPiece get(char horizontal, int vertical);
    ChessPiece set(char horizontal, int vertical, ChessPiece piece);
private:
    ChessPiece _fields[8][8];
};