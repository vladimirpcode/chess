#pragma once

enum class ChessPieceType{
    PAWN,
    KNIGHT,
    BISHOP,
    ROCK,
    KING,
    QUEEN,
    BLANK
};

enum class Color{
    BLACK,
    WHITE
};

class ChessPiece{
public:
    ChessPiece(char char_present);
    ChessPiece(ChessPieceType, Color);
    ChessPiece();
    ChessPieceType type();
    int weight();
    Color color();
    char get_char_present();
private:
    ChessPieceType _type;
    int _weight;
    Color _color;
};