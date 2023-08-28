#include "board.h"

Board::Board(){
    
}

ChessPiece Board::get(char vertical, int horizontal){
    return _fields[horizontal-1][vertical-97];
}

ChessPiece Board::set(char vertical, int horizontal, ChessPiece piece){
    _fields[horizontal-1][vertical-97] = piece;
}