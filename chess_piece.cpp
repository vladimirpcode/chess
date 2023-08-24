#include "chess_piece.h"
#include "constants.h"

ChessPiece::ChessPiece(ChessPieceType type, Color color){
    _type = type;
    _color = color;
    switch(type){
        case ChessPieceType::PAWN: _weight = PAWN_WEIGHT; break;
        case ChessPieceType::KNIGHT: _weight = KNIGHT_WEIGHT; break;
        case ChessPieceType::BISHOP: _weight = BISHOP_WEIGHT; break;
        case ChessPieceType::ROCK: _weight = ROCK_WEIGHT; break;
        case ChessPieceType::QUEEN: _weight = QUEEN_WEIGHT; break;
        case ChessPieceType::KING: _weight = KING_WEIGHT; break;
        case ChessPieceType::BLANK: _weight = 0; break;
    }
}

ChessPieceType ChessPiece::type(){
    return _type;
}

int ChessPiece::weight(){
    return _weight;
}
 
Color ChessPiece::color(){
    return _color;
}