#include "board.h"

ChessPiece Board::get(char horizontal, int vertical){
    return _fields[horizontal-97][vertical-1];
}

ChessPiece Board::set(char horizontal, int vertical, ChessPiece piece){
    _fields[horizontal-97][vertical-1] = piece;
}