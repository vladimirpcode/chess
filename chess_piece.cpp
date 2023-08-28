#include "chess_piece.h"
#include "constants.h"


ChessPiece::ChessPiece(char char_present){

}

ChessPiece::ChessPiece(){
    _type = ChessPieceType::BLANK;
    _color = Color::WHITE;
    _weight = 0;
}

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

char to_upper_for_chess_piece(char c){
    switch (c){
        case 'k': return 'K';
        case 'q': return 'Q';
        case 'r': return 'R';
        case 'b': return 'B';
        case 'n': return 'N';
        case 'p': return 'P';
    }
    return c;
}

char ChessPiece::get_char_present(){
    char result = ' ';
    switch (_type){
        case ChessPieceType::BLANK: result = ' '; break;
        case ChessPieceType::KING: result = 'k'; break;
        case ChessPieceType::QUEEN: result = 'q'; break;
        case ChessPieceType::ROCK: result = 'r'; break;
        case ChessPieceType::BISHOP: result = 'b'; break;
        case ChessPieceType::KNIGHT: result = 'n'; break;
        case ChessPieceType::PAWN: result = 'p'; break;
    }
    if (_color == Color::WHITE && _type != ChessPieceType::BLANK){
        result = to_upper_for_chess_piece(result);
    }
    return result;
}