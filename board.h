#pragma once

#include "chess_piece.h"

class Board{
public:
    Board();
    ChessPiece get(char vertical, int horizontal);
    ChessPiece set(char vertical, int horizontal, ChessPiece piece);
private:
    ChessPiece _fields[8][8];
};